#include <cmath>
#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const double eps = 1e-5, PI = acos( -1 );

template<typename _T>
void read( _T &x )/*{{{*/
{
	x = 0; char s = getchar(); int f = 1;
	while( ! ( '0' <= s && s <= '9' ) ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	x *= f;
}/*}}}*/

template<typename _T>
void write( _T x )/*{{{*/
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}/*}}}*/

inline int Dcmp( const double &x, const double &y = 0 )
{ return fabs( x - y ) < eps ? 0 : ( x < y ? -1 : 1 ); }

inline double Dist( double sx, double sy, double tx, double ty ) 
{ return sqrt( ( sx - tx ) * ( sx - tx ) + ( sy - ty ) * ( sy - ty ) ); }

int main()
{
	double x1, y1, x2, y2, x3, y3;
	scanf( "%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3 );
	if( ( x2 - x1 ) * ( y3 - y1 ) - ( x3 - x1 ) * ( y2 - y1 ) < 0 )
		std :: swap( x2, x3 ), std :: swap( y2, y3 );
	double d1 = Dist( x1, y1, x2, y2 ),
		   d2 = Dist( x2, y2, x3, y3 ),
		   d3 = Dist( x3, y3, x1, y1 );
	double ans = 1e18;
	for( int i = 0 ; i <= 97 ; i ++ )   //1-2
		for( int j = 0 ; i + j <= 97 ; j ++ )  //2-3
			for( int k = 0 ; i + j + k <= 97 ; k ++ )   //3-1
			{
				int n = i + j + k + 3;
				double a1 = ( i + 1 ) * PI / n,
					   a2 = ( j + 1 ) * PI / n,
					   a3 = ( k + 1 ) * PI / n;
				double l1 = d1 * 0.5 / sin( a1 ),
					   l2 = d2 * 0.5 / sin( a2 ),
					   l3 = d3 * 0.5 / sin( a3 );
				if( Dcmp( l1, l2 ) == 0 && Dcmp( l2, l3 ) == 0 )
					ans = std :: min( ans, l1 * l1 * sin( 2 * PI / n ) * 0.5 * n );
			}
	printf( "%.8f\n", ans );
	return 0;
}