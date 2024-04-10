#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
using namespace std;

typedef pair<int, int> Info;

const int MAXN = 1005, MAXLOG = 10;

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

struct Edge
{
	int to, nxt;
}Graph[MAXN << 1];

vector<int> pnt[MAXN];

int head[MAXN], dep[MAXN];
int N, cnt, mxdep;

void AddEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void Clean()
{
	mxdep = cnt = 0;
	for( int i = 0 ; i <= N ; i ++ )
		pnt[i].clear(), head[i] = 0;
}

void DFS( const int u, const int fa )
{
	pnt[dep[u] = dep[fa] + 1].push_back( u );
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			DFS( v, u );
	mxdep = MAX( mxdep, dep[u] );
}

namespace API
{
	Info Ask( vector<int> num, const int aband = 0 )
	{
		printf( "? %d", num.size() );
		for( int i = 0 ; i < ( int ) num.size() ; i ++ )
			if( num[i] ^ aband )
				putchar( ' ' ), write( num[i] );
		putchar( '\n' ), fflush( stdout );
		
		Info ret; 
		read( ret.first ), read( ret.second );
		return ret;
	}
	
	void Answer( const int a, const int b )
	{
		printf( "! %d %d\n", a, b ); 
		fflush( stdout );
		char ret[100]; scanf( "%s", ret );
		if( ! strcmp( ret, "Incorrect" ) ) exit( 0 );
	}
}

int main()
{
	int T;
	read( T );
	while( T -- )
	{
		read( N ), Clean();
		for( int i = 1, a, b ; i < N ; i ++ ) 
			read( a ), read( b ), AddEdge( a, b ), AddEdge( b, a );
		
		vector<int> all; all.clear();
		for( int i = 1 ; i <= N ; i ++ ) all.push_back( i );
		Info fir = API :: Ask( all ), lst, tmp;
		int cur = fir.first, d = fir.second;
		
		dep[0] = -1, DFS( cur, 0 );
		int l = MIN( ( d - 1 >> 1 ) + 1, mxdep ), r = MIN( d, mxdep ), mid;
		
		while( l <= r )
		{
			mid = l + r >> 1;
			if( ( tmp = API :: Ask( pnt[mid] ) ).second > d ) r = mid - 1;
			else l = mid + 1, lst = tmp;
		}
		
		all.clear();
		int x = lst.first; DFS( x, 0 );
		for( int i = 1 ; i <= N ; i ++ )
			if( dep[i] == d ) all.push_back( i );
		int y = API :: Ask( all ).first;
		
		API :: Answer( x, y );
	}
	return 0;
}