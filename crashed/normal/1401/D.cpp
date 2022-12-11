#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;
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

struct edge
{
	int to, nxt;
}Graph[MAXN << 1];

LL w[MAXN];
int p[MAXN];
int head[MAXN], siz[MAXN];
int N, M, cnt;

void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void init()
{
	cnt = 1;
	for( int i = 1 ; i <= N ; i ++ )
		head[i] = 0;
}

void DFS( const int u, const int fa )
{
	siz[u] = 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
		{
			DFS( v, u ), siz[u] += siz[v];
			w[i >> 1] = 1ll * ( N - siz[v] ) * siz[v];
		}
}

int main()
{
	int T;
	read( T );
	while( T -- )
	{
		read( N ); init();
		for( int i = 1, a, b ; i < N ; i ++ )
			read( a ), read( b ), addEdge( a, b ), addEdge( b, a );
		read( M );
		for( int i = 1 ; i <= M ; i ++ ) read( p[i] );
		DFS( 1, 0 );
		std :: sort( w + 1, w + N );
		std :: sort( p + 1, p + 1 + M );
		int ans = 0;
		if( M < N - 1 )
		{
			for( int i = N - 1 ; i ; i -- )
			{
				int tar = M - ( N - 1 - i );
				if( tar <= 0 ) ans = ( ans + w[i] ) % mod;
				else ans = ( ans + 1ll * w[i] * p[tar] % mod ) % mod;
			}
		}
		else
		{
			int tmp = 1;
			for( int i = N - 1 ; i <= M ; i ++ )
				tmp = 1ll * tmp * p[i] % mod;
			ans = ( ans + 1ll * w[N - 1] * tmp % mod ) % mod;
			for( int i = N - 2 ; i ; i -- )
				ans = ( ans + 1ll * w[i] * p[i] % mod ) % mod;
		}
		write( ans ), putchar( '\n' );
	}
	return 0;
}