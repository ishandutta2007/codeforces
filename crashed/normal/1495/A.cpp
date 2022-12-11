#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar();int f = 1;
	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

double X[MAXN], Y[MAXN];

int N;

int main()
{
	int T; read( T );
	while( T -- )
	{
		read( N );
		int tx = 0, ty = 0;
		rep( i, 1, N * 2 )
		{
			int a, b;
			read( a ), read( b );
			if( a == 0 ) Y[++ ty] = 1ll * b * b;
			else X[++ tx] = 1ll * a * a;
		}
		sort( X + 1, X + 1 + tx );
		sort( Y + 1, Y + 1 + ty );
		double ans = 0;
		rep( i, 1, N )
			ans += sqrt( X[i] + Y[i] );
		printf( "%.15lf\n", ans );
	}
	return 0;
}