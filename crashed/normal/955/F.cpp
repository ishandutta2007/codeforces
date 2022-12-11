#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<int, int> Point;

#define xx first
#define yy second

const int MAXN = 3e5 + 5, MAXLOG = 20;

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

struct Edge
{
	int to, nxt;
}Graph[MAXN << 1];

vector<Point> upt[MAXN];

int mx[MAXN];

int f[MAXN][MAXLOG];
int f1[MAXN], seq[MAXN];

int head[MAXN], fath[MAXN];
int N, cnt, lg2;
LL ans = 0, res = 0;

bool Cmp( const int &x, const int &y ) { return x > y; }

void AddEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void DFS( const int u, const int fa )
{
	int siz = 0;
	f[u][1] = N; fath[u] = fa;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			DFS( v, u ), f1[u] = MAX( f1[u], f1[v] );
	for( int j = 2 ; j <= lg2 ; j ++ )
	{
		siz = 0;
		for( int i = head[u], v ; i ; i = Graph[i].nxt )
			if( ( v = Graph[i].to ) ^ fa && f[v][j - 1] )
				seq[++ siz] = f[v][j - 1];
		std :: sort( seq + 1, seq + 1 + siz, Cmp );
		for( int k = siz ; k ; k -- )
			if( seq[k] >= k )
			{ f[u][j] = k; break; }
		if( f[u][j] ) upt[f[u][j]].push_back( Point( u, j ) );
	}
	ans += ++ f1[u];
}

void Update( int x, int val )
{
	for( ; x && mx[x] < val ; x = fath[x] )
		res += val - mx[x], mx[x] = val;
}

int main()
{
//	freopen( "heap.in", "r", stdin );
//	freopen( "heap.out", "w", stdout );
	
	read( N );
	for( int i = 1, a, b ; i < N ; i ++ )
		read( a ), read( b ), AddEdge( a, b ), AddEdge( b, a );
	
	lg2 = log2( N ); 
	DFS( 1, 0 );
	for( int i = 1 ; i <= N ; i ++ ) mx[i] = 1;
	res = N;
	for( int k = N ; k > 1 ; k -- )
	{
		for( int i = 0 ; i < ( int ) upt[k].size() ; i ++ )
			Update( upt[k][i].xx, upt[k][i].yy );
		ans += res;
	}
	
	write( ans ), putchar( '\n' );
	return 0;
}