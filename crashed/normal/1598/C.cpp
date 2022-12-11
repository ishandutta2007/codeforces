#include <map>
#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 2e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = - x;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

std :: map<int, int> mp;

int A[MAXN];

int N;

int main()
{
	int T;
	read( T );
	while( T -- )
	{
		read( N ); LL su = 0; mp.clear();
		rep( i, 1, N ) read( A[i] ), su += A[i];
		if( su * 2 % N ) { puts( "0" ); continue; }
		LL ned = su * 2 / N, ans = 0;
		rep( i, 1, N )
		{
			ans += mp[ned - A[i]];
			mp[A[i]] ++;
		}
		write( ans ), putchar( '\n' );
	}
	return 0;
}