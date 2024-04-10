#include <set>
#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 1e3 + 5;

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

int ld[2][2] = { { 0, -1 }, { -1, 0 } },
	dd[2][2] = { { 1, 0 }, { 0, 1 } },
	ud[2][2] = { { -1, 0 }, { 0, -1 } },
	rd[2][2] = { { 0, 1 }, { 1, 0 } };

bool grid[MAXN][MAXN];
LL dp[MAXN][MAXN];

int N, M, Q;

inline bool Inside( const int x, const int y )
{
	return 1 <= x && x <= N && 1 <= y && y <= M;
}

int main()
{
	read( N ), read( M ), read( Q );
	LL ans = 0;
	rep( i, 1, N ) rep( j, 1, M )
	{
		ans += 2ll * std :: min( N - i + 1, M - j + 1 ) - 1;
		ans += std :: min( N - i, M - j + 1 );
		ans += std :: min( M - j, N - i + 1 );
	}
	while( Q -- )
	{
		int x, y;
		read( x ), read( y ); LL res = -1;
		int nxt = grid[x][y] ^ 1; grid[x][y] = false;
		int up = 0, dn = 0;
		for( int ux = x, uy = y ; ; )
		{
			ux += ld[up & 1][0], uy += ld[up & 1][1], up ++;
			if( ! Inside( ux, uy ) || grid[ux][uy] ) { up --; break; }
		}
		for( int ux = x, uy = y ; ; )
		{
			ux += dd[dn & 1][0], uy += dd[dn & 1][1], dn ++;
			if( ! Inside( ux, uy ) || grid[ux][uy] ) { dn --; break; }
		}
		res += 1ll * ( up + 1 ) * ( dn + 1 ), up = dn = 0;
		for( int ux = x, uy = y ; ; )
		{
			ux += ud[up & 1][0], uy += ud[up & 1][1], up ++;
			if( ! Inside( ux, uy ) || grid[ux][uy] ) { up --; break; }
		}
		for( int ux = x, uy = y ; ; )
		{
			ux += rd[dn & 1][0], uy += rd[dn & 1][1], dn ++;
			if( ! Inside( ux, uy ) || grid[ux][uy] ) { dn --; break; }
		}
		res += 1ll * ( up + 1 ) * ( dn + 1 ), up = dn = 0;
		ans += nxt ? - res : res, grid[x][y] = nxt;
		write( ans ), putchar( '\n' );
	}
	return 0;
}