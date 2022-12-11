/*RESUBMIT*/
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;

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

set<int> s;

int a[MAXN];
int N;

int twocnt( int x )
{
	int cnt = 0;
	while( ! ( x & 1 ) ) cnt ++, x >>= 1;
	return cnt;
}

int gcd( const int a, const int b ) { return b ? gcd( b, a % b ) : a; }

int main()
{
	int T, res = 0;
	read( T );
	while( T -- )
	{
		s.clear(); 
		res = 0;
		read( N );
		for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
		std :: sort( a + 1, a + 1 + N );
		for( int i = 1 ; i <= N ; i ++ )
		{
			for( int j = a[i] ; ! ( j & 1 ) ; j >>= 1 )
			{
				if( s.find( j ) != s.end() ) break;
				res ++;
			}
			s.insert( a[i] );
		}
		write( res ), putchar( '\n' );
	}
	return 0;
}