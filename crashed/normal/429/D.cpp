#include <set>
#include <cmath>
#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int, int> Point;
typedef set<Point> :: iterator Iter;

#define rep( x, a, b ) for( int ( x ) = a ; x <= b ; x ++ )
#define per( x, a, b ) for( int ( x ) = a ; x >= b ; x -- )
#define xx first
#define yy second

const int MAXN = 1e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
_T ABS( const _T a )
{
	return a < 0 ? -a : a;
}

set<Point> s;

int su[MAXN];
int N;

double Dist( const Point &a, const Point &b )
{
	return sqrt( ( a.xx - b.xx ) * ( a.xx - b.xx ) + ( a.yy - b.yy ) * ( a.yy - b.yy ) );
}

int main()
{
	read( N );
	double ans = 0x3f3f3f3f;
	rep( i, 1, N ) { int a;
		read( a ), su[i] = su[i - 1] + a;
	}
	int l = 1;
	int b1, b2;
	rep( i, 1, N )
	{
		while( l < i && i - l > ans ) s.erase( Point( su[l], l ) ), l ++;
		Iter it = s.upper_bound( Point( su[i] - ans, 0 ) ); Point cur( su[i], i );
		while( it != s.end() && ABS( it->first - cur.first ) < ans ) 
		{
			if( Dist( *it, cur ) < ans )
				ans = Dist( *it, cur ), b1 = it->second, b2 = i;
			it ++;
		}
		s.insert( cur );
	}
	write( 1ll * ( b2 - b1 ) * ( b2 - b1 ) + 1ll * ( su[b2] - su[b1] ) * ( su[b2] - su[b1] ) ), putchar( '\n' );
	return 0;
}