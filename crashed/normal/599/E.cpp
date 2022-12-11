#include <cstdio>
#include <cstring>

typedef long long LL;

const int MAXN = 15, MAXM = 105, MAXS = ( 1 << 13 ) + 5;

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

LL f[MAXN][MAXS];
int LCARis[MAXM], LCAc[MAXM];
int Eu[MAXM], Ev[MAXM], ERis[MAXN];
int bit[MAXS], ref[MAXN];
int N, M, Q;

int mono( const int u ) { return 1 << u - 1; }
int lowbit( const int x ) { return x & ( -x ); }
int inter( const int S, const int T ) { return S & T; }
bool chk( const int S ) { return ! ( S - lowbit( S ) ); }
bool in( const int S, const int T ) { return ( S & T ) == T; }
bool onE( const int u, const int id ) { return Eu[id] == u || Ev[id] == u; }

LL DFS( const int u, const int S )
{
	LL& ret = f[u][S];

	if( ~ ret ) return ret; ret = 0;
	if( ! in( S, ref[u] ) ) return ret = 0;
	
	int pos; bool flag;
	for( pos = 1 ; pos <= N ; pos ++ ) 
		if( pos ^ u && in( S, ref[pos] ) ) break;
	for( int T = ( S - 1 ) & S ; T ; T = ( T - 1 ) & S )
		if( in( T, ref[pos] ) && ! in( T, ref[u] ) )
		{
			flag = true;
			for( int i = 1 ; i <= Q ; i ++ )
				if( LCAc[i] == u && in( T, LCARis[i] ) )
					{ flag = false; break; }
			if( ! flag ) continue;
			for( int i = 1 ; i <= Q ; i ++ )
				if( in( T, ref[LCAc[i]] ) && ! in( T, LCARis[i] ) )
					{ flag = false; break; }
			if( ! flag ) continue;
			for( int i = 1 ; i <= M ; i ++ )
				if( ! onE( u, i ) && ( in( T, ref[Eu[i]] ) ^ in( T, ref[Ev[i]] ) ) )
					{ flag = false; break; }
			if( ! flag ) continue;
			if( ! inter( T, ERis[u] ) )
			{
				for( int i = 1 ; i <= N ; i ++ )
					if( in( T, ref[i] ) )
						ret += DFS( u, S ^ T ) * DFS( i, T );
			}
			else if( chk( T & ERis[u] ) )
				ret += DFS( u, S ^ T ) * DFS( bit[lowbit( T & ERis[u] )], T );
		}
	return ret;
}

int main()
{
	read( N ), read( M ), read( Q );
	memset( f, -1, sizeof f );
	for( int i = 1 ; i <= N ; i ++ ) f[i][1 << i - 1] = 1, bit[ref[i] = ( 1 << i - 1 )] = i;
	for( int i = 1 ; i <= M ; i ++ ) 
		read( Eu[i] ), read( Ev[i] ), 
		ERis[Eu[i]] |= ref[Ev[i]], ERis[Ev[i]] |= ref[Eu[i]];
	for( int i = 1, a, b ; i <= Q ; i ++ ) 
		read( a ), read( b ), read( LCAc[i] ), 
		LCARis[i] = ref[a] | ref[b];
	write( DFS( 1, ( 1 << N ) - 1 ) ), putchar( '\n' );
	return 0;
}