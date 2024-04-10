#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

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

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

set<int> s;

int N, D;
int a[MAXN];

int main()
{
	int T, ans, res, tmp, left;
	read( T );
	while( T -- )
	{
		ans = 0x3f3f3f3f;
		s.clear();
		read( N ), read( D );
		for( int i = 1 ; i <= N ; i ++ ) read( a[i] ), s.insert( a[i] );
		std :: sort( a + 1, a + 1 + N );
		for( int i = 1 ; i <= N ; i ++ )
		{
			res = 0x3f3f3f3f, tmp = D / a[i], left = D % a[i];
			if( a[i] * 2 > D ) res = MIN( res, 2 );
			else if( a[i] * 2 > D - ( tmp - 1 ) * a[i] ) res = MIN( res, tmp + 1 );
			if( ! left ) res = MIN( res, tmp );
			if( s.find( left ) != s.end() ) res = MIN( res, tmp + 1 );
			res = MIN( res, tmp + 2 );
			ans = MIN( ans, res );
		}
		write( ans ), putchar( '\n' );
	}
	return 0;
}
/*
1
2 10
15 4
*/