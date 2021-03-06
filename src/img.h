/*
 *	img.h - Game image object (255 colours + transparency)
 *	AYM 2000-06-13
 */


#ifndef YH_IMG  /* DO NOT INSERT ANYTHING BEFORE THIS LINE */
#define YH_IMG


typedef u8             img_pixel_t;
typedef unsigned short img_dim_t;
class Img_priv;


/* The colour number used to represent transparent pixels in an
   Img. Any value will do but zero is probably best
   performance-wise. */
const img_pixel_t IMG_TRANSP = 0;


class Img
{
  public :
    Img ();
    Img (img_dim_t width, img_dim_t height, bool opaque);
    ~Img ();
    bool               is_null    () const;	// Is it a null image ?
    img_dim_t          width      () const;	// Return the width
    img_dim_t          height     () const;	// Return the height
    const img_pixel_t *buf        () const;	// Return pointer on buffer
    img_pixel_t       *wbuf       ();		// Return pointer on buffer
    void               clear      ();
    void               set_opaque (bool opaque);
    void               resize     (img_dim_t width, img_dim_t height);
    int                save       (const char *filename) const;
    
  private :
    Img            (const Img&);	// Too lazy to implement it
    Img& operator= (const Img&);	// Too lazy to implement it
    Img_priv *p;
};


#endif  /* DO NOT ADD ANYTHING AFTER THIS LINE */
