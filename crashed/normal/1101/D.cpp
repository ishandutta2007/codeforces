#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 5, MAXP = 15;

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

vector<int> dec[MAXN];

int f[MAXN][MAXP];
int head[MAXN], w[MAXN];
int N, ans, cnt;

void upt( int &x, const int v ) { x = ( x > v ? x : v ); }

void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void decompose( const int u )
{
	int t = w[u];
	for( int i = 2 ; i * i <= t ; i ++ )
		if( ! ( t % i ) )
		{
			dec[u].push_back( i );
			while( ! ( t % i ) ) t /= i;
		}
	if( t > 1 ) dec[u].push_back( t );
}

void DFS( const int u, const int fa )
{
	decompose( u );
	if( w[u] > 1 ) upt( ans, 1 );
	for( int i = 0 ; i < dec[u].size() ; i ++ ) f[u][i] = 1; 
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
		{
			DFS( v, u );
			for( int j = 0 ; j < dec[u].size() ; j ++ )
			{
				int q = -1;
				for( int k = 0 ; k < dec[v].size() ; k ++ )
					if( dec[v][k] == dec[u][j] ) { q = k; break; }
				if( q == -1 ) continue;
				upt( ans, f[u][j] + f[v][q] );
				upt( f[u][j], f[v][q] + 1 );
			}
		}
}

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) read( w[i] );
	for( int i = 1, a, b ; i < N ; i ++ )
		read( a ), read( b ), addEdge( a, b ), addEdge( b, a );
	DFS( 1, 0 );
	write( ans ), putchar( '\n' );
	return 0;
}