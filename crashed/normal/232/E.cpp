#include <cstdio>
#include <bitset>

using namespace std;

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 505, MAXQ = 6e5 + 5;

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

bitset<MAXN> reach[MAXN][MAXN];

bool ans[MAXQ];
int x1[MAXQ], y1[MAXQ], x2[MAXQ], y2[MAXQ];
int seq[MAXQ], t1[MAXQ], t2[MAXQ], t3[MAXQ];

bool grid[MAXN][MAXN];
char str[MAXN];
int N, M, Q;

void Solve( const int gL, const int gR, const int qL, const int qR )
{
	if( gL > gR || qL > qR ) return ;
	if( gL == gR )
	{
		rep( j, 1, M ) reach[gL][j].reset();
		rep( j, 1, M ) rep( k, j, M )
		{
			if( ! grid[gL][k] ) break;
			reach[gL][j].set( k );
		}
		rep( i, qL, qR )
			ans[seq[i]] = reach[gL][y1[seq[i]]][y2[seq[i]]];
		return ;
	}
	int l1 = 0, l2 = 0, l3 = 0, mid = ( gL + gR ) >> 1;
	rep( i, qL, qR )
	{
		if( x2[seq[i]] <= mid ) t1[++ l1] = seq[i];
		else if( x1[seq[i]] > mid ) t2[++ l2] = seq[i];
		else t3[++ l3] = seq[i];
	}
	int cur = qL;
	rep( i, 1, l1 ) seq[cur ++] = t1[i];
	rep( i, 1, l2 ) seq[cur ++] = t2[i];
	rep( i, gL, gR ) rep( j, 1, M ) reach[i][j].reset();
	rep( j, 1, M ) rep( k, j, M )
	{
		if( ! grid[mid][k] ) break;
		reach[mid][j].set( k );
	}
	per( i, mid - 1, gL )
		per( j, M, 1 ) if( grid[i][j] )
		{
			reach[i][j] = reach[i + 1][j];
			if( j < M ) reach[i][j] |= reach[i][j + 1];
		}
	rep( j, 1, M ) rep( k, j, M )
	{
		if( ! grid[mid + 1][k] ) break;
		reach[mid + 1][k].set( j );
	}
	rep( i, mid + 2, gR )
		rep( j, 1, M ) if( grid[i][j] )
		{
			reach[i][j] = reach[i - 1][j];
			if( j > 1 ) reach[i][j] |= reach[i][j - 1];
		}
	rep( i, 1, l3 )
		rep( k, 1, M )
		{
			int cur = t3[i];
			ans[cur] |= reach[x1[cur]][y1[cur]][k] & reach[x2[cur]][y2[cur]][k];
			if( ans[cur] ) break;
		}
	Solve( gL, mid, qL, qL + l1 - 1 );
	Solve( mid + 1, gR, qL + l1, qL + l1 + l2 - 1 );
}

int main()
{
	read( N ), read( M );
	rep( i, 1, N )
	{
		scanf( "%s", str + 1 );
		rep( j, 1, M ) grid[i][j] = str[j] == '.';
	}
	read( Q );
	rep( i, 1, Q ) read( x1[i] ), read( y1[i] ), read( x2[i] ), read( y2[i] ), seq[i] = i;
	Solve( 1, N, 1, Q );
	rep( i, 1, Q ) puts( ans[i] ? "Yes" : "No" );
	return 0;
}