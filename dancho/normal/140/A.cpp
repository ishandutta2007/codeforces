#include <cstdio> 
#include <cmath> 
 
const double PI = 3.14159265; 
 
const double eps = 1e-6; 
 
int main() 
{ 
        int n; 
        double R, r, d, x, an; 
         
        scanf( "%d %lf %lf", &n, &R, &r ); 
        if ( R < r ) 
        { 
                printf( "NO\n" ); 
                return 0; 
        } 
        d = R - r; 
         
        if ( n == 1 ) 
        { 
                if ( R + eps >= r ) printf( "YES\n" ); 
                else printf( "NO\n" ); 
                return 0; 
        } 
        if ( n == 2 ) 
        { 
                if ( R + eps >= 2.0*r ) printf( "YES\n" ); 
                else printf( "NO\n" ); 
                return 0; 
        } 
         
        an = 2.0*PI/(double)n; 
        x = sqrt( 2.0*d*d-2.0*d*d*cos( an ) ); 
        if ( x + eps >= 2*r ) 
                printf( "YES\n" ); 
        else 
                printf( "NO\n" ); 
        return 0; 
}