#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int i, j;
    int t, T;
    double k, c;
    double r, R, r0;
    double ox, oy;
    double ax, ay, bx, by;
    double d, da, db;
    scanf( "%d", &T );
    for ( t = 0; t < T; t++ )
    {
        scanf( "%lf %lf %lf", &R, &r, &k );

        ox = (r+R)/(4.0*r*R);
        oy = k*(R-r)/(2.0*r*R);
        r0 = (R-r)/(4.0*r*R);
        d = sqrt( ox*ox + oy*oy );
        c = r0/d;
        ax = c*ox + ox;  bx = ox - c*ox;
        ay = c*oy + oy;  by = oy - c*oy;

        da = sqrt( ax*ax + ay*ay );
        db = sqrt( bx*bx + by*by );

        ax = ax/da/da;
        ay = ay/da/da;
        bx = bx/db/db;
        by = by/db/db;

        d = sqrt( (ax-bx)*(ax-bx) + (ay-by)*(ay-by) )/2;
        printf( "%.9lf\n", d );
    }
    return 0;
}