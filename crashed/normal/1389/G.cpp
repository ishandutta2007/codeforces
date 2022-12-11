#include <cstdio>
#include <algorithm>

typedef long long LL;

const int MAXN = 3e5 + 5, MAXM = 3e5 + 5;

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

struct EdgeOnG
{
	int to, nxt, w;
}Graph[MAXM << 1];

struct Edge
{
	int u, v, w, id;
	bool operator < ( const Edge &b ) const { return w < b.w; }
}E[MAXM];

LL f[MAXN], ans[MAXN];
bool subImp[MAXN];

int fa[MAXN];

int c[MAXN];
int head[MAXN], DFN[MAXN], LOW[MAXN];
int N, M, K, cnt = 1, ID;
bool cut[MAXM], imp[MAXN], onT[MAXM];

void AddEdge( const int from, const int to, const int W )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from], Graph[cnt].w = W;
	head[from] = cnt;
}

void Tarjan( const int u, const int fa )
{
	DFN[u] = LOW[u] = ++ ID;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
	{
		v = Graph[i].to;
		if( ! DFN[v] )
		{
			Tarjan( v, u ), LOW[u] = MIN( LOW[u], LOW[v] );
			if( LOW[v] > DFN[u] ) cut[i >> 1] = true;
		}
		else if( v ^ fa ) LOW[u] = MIN( LOW[u], DFN[v] );
	}
}

void MakeSet( const int siz ) { for( int i = 1 ; i <= siz ; i ++ ) fa[i] = i; }
int FindSet( const int u ) { return fa[u] = ( fa[u] == u ? u : FindSet( fa[u] ) ); }

bool UnionSet( int u, int v )
{
	u = FindSet( u ), v = FindSet( v );
	if( u == v ) return false; fa[u] = v; return true;
}

void Init( const int u, const int fa )
{
	subImp[u] = imp[u];
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( onT[i >> 1] && ( v = Graph[i].to ) ^ fa )
			Init( v, u ), subImp[u] |= subImp[v];
}

void DFS1( const int u, const int fa, const bool faImp )
{
	int ttot = faImp; f[u] = c[u];
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( onT[i >> 1] && ( v = Graph[i].to ) ^ fa )
			ttot += subImp[v];
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( onT[i >> 1] && ( v = Graph[i].to ) ^ fa )
		{
			bool nwImp = ( ttot > 1 || ( ttot == 1 && ! subImp[v] ) ) || imp[u];
			DFS1( v, u, nwImp );
			if( cut[i >> 1] && subImp[v] ) 
				f[u] += MAX( f[v] - Graph[i].w, nwImp ? 0ll : f[v] );
			else f[u] += f[v];
			subImp[u] |= subImp[v];
		}
}

void DFS2( const int u, const int fa, const LL faVal, const bool faImp )
{
	int ttot = faImp;
	ans[u] = f[u] + faVal;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( onT[i >> 1] && ( v = Graph[i].to ) ^ fa )
			ttot += subImp[v];
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( onT[i >> 1] && ( v = Graph[i].to ) ^ fa )
		{
			bool nwImp = ( ttot > 1 || ( ttot == 1 && ! subImp[v] ) ) || imp[u];
			LL tmp = faVal + f[u];
			if( cut[i >> 1] && subImp[v] ) 
				tmp -= MAX( f[v] - Graph[i].w, nwImp ? 0ll : f[v] );
			else tmp -= f[v];
			if( cut[i >> 1] && nwImp ) 
				tmp = MAX( tmp - Graph[i].w, subImp[v] ? 0ll : tmp );
			DFS2( v, u, tmp, nwImp );
		}
}

int main()
{
	read( N ), read( M ), read( K );
	for( int i = 1, t ; i <= K ; i ++ ) read( t ), imp[t] = true;
	for( int i = 1 ; i <= N ; i ++ ) read( c[i] );
	for( int i = 1 ; i <= M ; i ++ ) read( E[i].w );
	for( int i = 1 ; i <= M ;i ++ ) 
		read( E[i].u ), read( E[i].v ), E[i].id = i,
		AddEdge( E[i].u, E[i].v, E[i].w ), AddEdge( E[i].v, E[i].u, E[i].w );

	std :: sort( E + 1, E + 1 + M ), MakeSet( N );
	for( int i = 1, tot = 0 ; i <= M && tot < N - 1 ; i ++ )
		if( UnionSet( E[i].u, E[i].v ) ) 
			tot ++, onT[E[i].id] = true;
	
	Tarjan( 1, 0 ), Init( 1, 0 );
	DFS1( 1, 0, false ); 
	DFS2( 1, 0, 0, false );
	for( int i = 1 ; i <= N ; i ++ ) write( ans[i] ), putchar( i == N ? '\n' : ' ' );
	return 0;
}