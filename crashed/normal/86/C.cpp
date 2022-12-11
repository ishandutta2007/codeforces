#include <cstdio>
#include <cstring>

#define Tour( c ) for( int c = 0 ; c < 4 ; c ++ )

const int mod = 1e9 + 9;
const int MAXN = 1005, MAXM = 15, MAXL = 105;

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

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int f[MAXN][MAXL][MAXM];
int ch[MAXL][4], fail[MAXL], q[MAXL], len[MAXL];
char S[MAXM];
int N, M, cnt, mx;

void add( int &x, const int v ) { x = ( x + v >= mod ? x + v - mod : x + v ); }

int getID( const char C )
{
	if( C == 'A' ) return 0;
	if( C == 'T' ) return 1;
	if( C == 'C' ) return 2;
	if( C == 'G' ) return 3;
}

void insert( char *T )
{
	int p = 0, id;
	for( int i = 1 ; T[i] ; i ++ )
	{
		id = getID( T[i] );
		if( ! ch[p][id] ) ch[p][id] = ++ cnt;
		p = ch[p][id];
	}
	mx = MAX( mx, len[p] = MAX( len[p], ( int ) strlen( T + 1 ) ) );
}

void init()
{
	int h = 1, t = 0, u, v;
	Tour( i ) if( ch[0][i] ) q[++ t] = ch[0][i];
	while( h <= t )
	{
		u = q[h ++];
		Tour( i )
		{
			if( v = ch[u][i] ) fail[v] = ch[fail[u]][i], q[++ t] = v;
			else ch[u][i] = ch[fail[u]][i];
		}
		len[u] = MAX( len[u], len[fail[u]] );
	}
}

int main()
{
	read( N ), read( M );
	for( int i = 1 ; i <= M ; i ++ ) scanf( "%s", S + 1 ), insert( S );
	init();
	f[0][0][0] = 1;
	for( int i = 0 ; i < N ; i ++ )
		for( int p = 0 ; p <= cnt ; p ++ )
			for( int j = 0 ; j <= mx ; j ++ )
				if( f[i][p][j] )
					Tour( c )
						add( f[i + 1][ch[p][c]][( len[ch[p][c]] > j ? 0 : j + ( j != mx ) )], f[i][p][j] );
	int ans = 0;
	for( int p = 0 ; p <= cnt ; p ++ ) add( ans, f[N][p][0] );
	write( ans ), putchar( '\n' );
	return 0;
}