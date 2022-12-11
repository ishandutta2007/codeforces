#include <cstdio>

const int mod = 1e9 + 7;
const int MAXS = 4e6 + 5, MAXN = 5005 + 5, MAXE = 5005 * 5005 >> 1;

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

struct edge
{
	int to, nxt;
}Graph[MAXE];

int fac[MAXS], ifac[MAXS];
int G[MAXN], GBeg[MAXN], count[MAXN];

int DFN[MAXN], LOW[MAXN], stk[MAXN], top;

int beg[MAXN], s[MAXN], mn[MAXN], mx[MAXN];
int head[MAXN], bel[MAXN];
int N, A, B, cnt, ID, tot, siz;
bool in[MAXN], bar[MAXS], GBar[MAXS];

bool *BA( const int i ) { return bar + beg[i]; }
bool *GB( const int i ) { return GBar + GBeg[i]; }

void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

int gcd( const int a, const int b ) { return b ? gcd( b, a % b ) : a; }

void Tarjan( const int u )
{
	DFN[u] = LOW[u] = ++ ID;
	in[stk[++ top] = u] = true;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
	{
		if( ! DFN[v = Graph[i].to] ) Tarjan( v ), LOW[u] = MIN( LOW[u], LOW[v] );
		else if( in[v] ) LOW[u] = MIN( LOW[u], DFN[v] );
	}
	if( LOW[u] == DFN[u] )
	{
		int v; ++ tot;
		do
		{
			in[v = stk[top --]] = false;
			G[tot] = gcd( s[v], G[tot] );
			bel[v] = tot;		
		}
		while( v ^ u );
		GBeg[tot] = siz;
		siz += 2 * G[tot];
	}
}

int qkpow( int base, int indx )
{
	int ret = 1;
	while( indx )
	{
		if( indx & 1 ) ret = 1ll * ret * base % mod;
		base = 1ll * base * base % mod, indx >>= 1;
	}
	return ret;
}

void init( const int S )
{
	fac[0] = 1;
	for( int i = 1 ; i <= S ; i ++ ) fac[i] = 1ll * fac[i - 1] * i % mod;
	ifac[S] = qkpow( fac[S], mod - 2 );
	for( int i = S - 1 ; ~ i ; i -- ) ifac[i] = 1ll * ifac[i + 1] * ( i + 1 ) % mod;
}

int C( const int n, const int m )
{
	if( n < m || m < 0 || n < 0 ) return 0;
	return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int main()
{
	scanf( "%d %d %d", &N, &A, &B );
	for( int i = 1, d ; i <= N ; i ++ )
		for( int j = 1 ; j <= N ; j ++ )
		{
			scanf( "%1d", &d );
			if( d ) addEdge( i, j );
		}
	for( int i = 1, d ; i <= N ; i ++ )
	{
		scanf( "%d", &s[i] ); beg[i] = siz + 1;
		for( int j = 1 ; j <= s[i] ; j ++ )
			scanf( "%1d", &d ), bar[++ siz] = d, mn[i] += d;
	}
	init( N + 5 );
	
	siz = 1;
	for( int i = 1 ; i <= N ; i ++ ) if( ! DFN[i] ) Tarjan( i );
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = 0 ; j < s[i] ; j ++ )
			GB( bel[i] )[j % G[bel[i]]] |= BA( i )[j];
	for( int i = tot ; i > 1 ; i -- )
	{
		int d = gcd( G[i], G[i - 1] );
		for( int j = 0 ; j < G[i] ; j ++ )
			GB( i - 1 )[j % d] |= GB( i )[j];
	}
	
	for( int i = 1 ; i <= tot ; i ++ )
		for( int k = 0 ; k < G[i] ; k ++ ) 
			count[i] += GB( i )[k];
	for( int i = 1 ; i <= N ; i ++ )
		mx[i] = 1ll * s[i] * count[bel[i]] / G[bel[i]];
	
	int ans = 0, cnt1, cnt2;
	for( int i = 1 ; i <= N ; i ++ )
	{
		cnt1 = cnt2 = 0;
		for( int j = 1 ; j <= N ; j ++ )
			if( i ^ j )
			{
				if( mn[j] > mx[i] ) cnt1 ++;
				else if( mx[j] > mx[i] || ( mx[j] == mx[i] && j < i ) ) cnt2 ++;
			}
		if( cnt1 > A - 1 ) continue;
		for( int j = MIN( B, MIN( A - 1 - cnt1, cnt2 ) ) ; j + cnt1 + 1 >= B ; -- j )
			ans = ( ans + 1ll * C( cnt2, j ) * C( cnt1, B - j - 1 ) % mod ) % mod;
	}
	printf( "%d\n", ans );
	return 0;
}