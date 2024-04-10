#include <cstdio>
#include <cstring>

typedef long long LL;

const int mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

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
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int len[MAXN], rig[MAXN], lef[MAXN];
int stk[MAXN], top;

int f[MAXN][2], nxt[MAXN][2];

char S[MAXN];
int N, tot;

int Sub( int x, int v ) { return x < v ? x - v + mod : x - v; }
int Mul( LL x, int v ) { x *= v; if( x >= mod ) x %= mod; return x; }
int Add( int x, int v ) { return x + v >= mod ? x + v - mod : x + v; }

int main()
{
	scanf( "%s", S + 1 );
	N = strlen( S + 1 );
	
	int lead = 0; for( ; S[1 + lead] == '0' ; lead ++ );
	int las = 0; for( ; S[N - las] == '0' ; las ++ );
	
	int lst = N + 1;
	for( int i = N ; ~ i ; i -- )
	{
		nxt[i][1] = lst;
		if( S[i] == '1' ) lst = i;
	}
	lst = N + 1;
	for( int i = N ; ~ i ; i -- )
	{
		if( S[i] == '1' || S[i + 1] == '0' ) nxt[i][0] = lst;
		if( S[i] == '0' ) lst = i;
	}
	
	int tot = 0;
	for( int i = 1, r ; i <= N ; i ++ )
		if( S[i] == '0' )
		{
			for( r = i ; r <= N && S[r] == '0' ; r ++ );
			len[++ tot] = r - i, lef[tot] = i, rig[tot] = i = r - 1;
		}
	len[++ tot] = N, lef[tot] = N + 1, rig[tot] = N + 1;
	for( int i = 1 ; i <= tot ; i ++ )
	{
		while( top && len[stk[top]] < len[i] ) 
		{ nxt[rig[stk[top]]][0] = lef[i] + len[stk[top]], top --; }
		stk[++ top] = i;
	}
	
	if( lead == N ) return write( lead ), putchar( '\n' ), 0;
	
	int ans = 0;
	nxt[0][0] = N + 1, f[0][0] = 1;
	for( int i = 0 ; i <= N ; i ++ )
	{
		for( int j = 0 ; j < 2 ; j ++ )
			if( f[i][j] )
				for( int k = 0 ; k < 2 ; k ++ )
					if( nxt[i][k] <= N )
						f[nxt[i][k]][k] = Add( f[nxt[i][k]][k], f[i][j] );
		ans = Add( ans, f[i][1] );
	}
	write( Mul( Mul( lead + 1, las + 1 ), ans ) ), putchar( '\n' );
	
//	for( int i = 0 ; i <= N ; i ++ ) printf( "%d-th: (%d,%d)\n", i, nxt[i][0], nxt[i][1] );
	return 0;
}