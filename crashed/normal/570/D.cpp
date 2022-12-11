#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> query;

const int MAXN = 5e5 + 5;

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

vector<query> q[MAXN];

int cnt[MAXN];
int head[MAXN], dep[MAXN], siz[MAXN];
char S[MAXN];
int N, M, count, dis;
bool ans[MAXN];

int chk( const int s ) { return ! ( s & ( s - 1 ) ); }
void insert( int &s, const char c ) { s ^= 1 << ( c - 'a' ); }

void addEdge( const int from, const int to )
{
	Graph[++ count].to = to, Graph[count].nxt = head[from];
	head[from] = count;
}

void init( const int u, const int fa )
{
	siz[u] = 1, dep[u] = dep[fa] + 1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			init( v, u ), siz[u] += siz[v];
}

void edit( const int u, const int fa )
{
	if( u == dis ) return ;
	insert( cnt[dep[u]], S[u] );
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			edit( v, u );
}

void DFS( const int u, const int fa, const bool type )
{
	int heavy = -1;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			if( heavy == -1 || siz[heavy] < siz[v] )
				heavy = v;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && v ^ heavy )
			DFS( v, u, false );
	if( ~ heavy ) DFS( heavy, u, true ), dis = heavy;
	edit( u, fa ), dis = 0;
	for( int i = 0 ; i < ( int ) q[u].size() ; i ++ ) 
		ans[q[u][i].second] = chk( cnt[q[u][i].first] );
	if( ! type ) edit( u, fa );
}

int main()
{
	read( N ), read( M );
	for( int i = 2, f ; i <= N ; i ++ ) read( f ), addEdge( f, i ), addEdge( i, f );
	scanf( "%s", S + 1 );
	for( int i = 1, cur, d ; i <= M ; i ++ ) read( cur ), read( d ), q[cur].push_back( query( d, i ) );
	init( 1, 0 ); 
	DFS( 1, 0, true );
	for( int i = 1 ; i <= M ; i ++ ) puts( ans[i] ? "Yes" : "No" );
	return 0;
}