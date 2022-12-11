#include <set>
#include <cstdio>
#include <utility>
using namespace std;

const int INF = 0x3f3f3f3f;
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

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

struct Edge
{
	int to, nxt;
}Graph[MAXN << 1], nGraph[MAXN * 10];

struct Node
{
	int first, second;
	Node() { first = second = 0; }
	Node( int F, int S ) { first = F, second = S; }
	bool operator < ( const Node &b ) const { return first < b.first; }
};

set<Node> s;

int fir[MAXN], sec[MAXN];
int snake[MAXN], len;

int ref[MAXN << 2], q[MAXN << 2];
int head[MAXN], nHead[MAXN << 2];
int N, cnt, nCnt, ntot, S, T;
bool occ[MAXN], able[MAXN], rea[MAXN << 2];

void AddEdge( Edge *G, int *h, int &count, const int from, const int to )
{
	G[++ count].to = to, G[count].nxt = h[from];
	h[from] = count;
}

bool Collect( const int u, const int fa, const int t )
{
	if( u == t ) return occ[snake[++ len] = u] = true;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
			if( Collect( v, u, t ) )
				return occ[snake[++ len] = u] = true;
	return false;
}

void Clean()
{
	nCnt = cnt = len = 0;
	for( int i = 1 ; i <= N ; i ++ ) able[i] = occ[i] = false, snake[i] = head[i] = 0;
	for( int i = 1 ; i <= N << 2 ; i ++ ) nHead[i] = 0, rea[i] = false;
}

void DFS( const int u, const int fa )
{
	int l; fir[u] = sec[u] = 0;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa && ! occ[v] )
		{
			DFS( v, u ), l = fir[v] + 1;
			if( fir[u] <= l ) sec[u] = fir[u], fir[u] = l;
			else if( sec[u] < l ) sec[u] = l;
			able[u] |= able[v];
		}
	able[u] |= ( fir[u] >= len - 1 ? sec[u] >= len - 1 : false );
}

void BFS( const int sta )
{
	int h = 1, t = 0, u, v;
	rea[q[++ t] = sta] = true;
	while( h <= t )
	{
		u = q[h ++];
		for( int i = nHead[u] ; i ; i = nGraph[i].nxt )
			if( ! rea[v = nGraph[i].to] )
				rea[q[++ t] = v] = true;
	}
}

int main()
{
	int cas;
	read( cas );
	while( cas -- )
	{
		read( N ), read( S ), read( T ), Clean();
		for( int i = 1, a, b ; i < N ; i ++ )
			read( a ), read( b ), 
			AddEdge( Graph, head, cnt, a, b ), 
			AddEdge( Graph, head, cnt, b, a );
		Collect( S, 0, T ), ntot = 2 * len + 1;
		for( int i = 1 ; i <= len ; i ++ ) DFS( snake[i], 0 );
		
		s.clear();
		for( int i = 1 ; i <= len ; i ++ )
		{
			AddEdge( nGraph, nHead, nCnt, ref[i << 1] = ++ ntot, i << 1 );
			AddEdge( nGraph, nHead, nCnt, ref[i << 1 | 1] = ++ ntot, i << 1 | 1 );
		}
		s.clear();
		for( int i = 1 ; i <= len ; i ++ )
		{
			set<Node> :: iterator it = s.upper_bound( Node( fir[snake[i]] + i, i ) );
			if( it != s.begin() )  
			{
				int j = ( -- it )->second;
				AddEdge( nGraph, nHead, nCnt, i << 1, ref[j << 1 | 1] );
				if( it->first == len - 1 + i ) s.erase( it );
			}
			if( i ) AddEdge( nGraph, nHead, nCnt, ref[i << 1 | 1], ref[i - 1 << 1 | 1] );
			s.insert( Node( len - 1 + i, i ) );
		}
		s.clear();
		for( int i = len ; i ; i-- )
		{
			set<Node> :: iterator it = s.upper_bound( Node( fir[snake[i]] - i, i ) );
			if( it != s.begin() ) 
			{
				int j = ( -- it )->second;
				AddEdge( nGraph, nHead, nCnt, i << 1 | 1, ref[j << 1] );
				if( it->first == len - 1 - i ) s.erase( it );
			}
			if( i < len ) AddEdge( nGraph, nHead, nCnt, ref[i << 1], ref[i + 1 << 1] );
			s.insert( Node( len - 1 - i, i ) );
		}
		int sta = 1; 
		AddEdge( nGraph, nHead, nCnt, sta, 1 << 1 | 1 ); 
		AddEdge( nGraph, nHead, nCnt, sta, len << 1 );
		BFS( sta ); bool flg = false;
		for( int i = 1 ; i <= len ; i ++ )
		{
			if( able[snake[i]] && ( rea[i << 1] || rea[i << 1 | 1] ) ) { flg = true; break; }
			if( fir[snake[i]] >= len - 1 && rea[i << 1] && rea[i << 1 | 1] ) { flg = true; break; }
		}
		puts( flg ? "YES" : "NO" );
	}
	return 0;
}
/*
len-1-fir[1]<t
len-1-suf[len]<len-t
fir[k]>=len-1-t+k
fir[k]-k>=len-1-t
fir[k]>=len-1-k+t
fir[k]+k>=len-1+t
fir[k]>=len-1-t+k

i->j
i<j:
1. i<k  k 
2. len-1-fir[i] <= j-i ==>> len-1-j<=fir[i]-i
i>j:
1. i>k  k 
2. len-1-fir[i] <= i-j ==>> len-1+j<=fir[i]+i
*/
/*
1
10 5 3
7 2
1 3
1 6
1 7
4 8
1 4
1 9
5 1
5 10
*/
/*
1
16 15 12
1 2
2 3
1 4
4 5
5 6
6 7
4 8
8 9
8 10
10 11
11 12
11 13
13 14
10 15
15 16
*/
/*
1
13 1 4
1 2
2 3
3 4
4 5
2 6
6 7
3 8
8 9
9 10
3 11
11 12
12 13
*/
/*
1
8 4 7
1 2
2 3
1 4
4 5
4 6
1 7
7 8
*/
/*
1
18 2 1
1 3
16 4
2 6
15 7
13 8
13 10
13 11
13 12
2 13
17 2
5 14
1 5
9 1
17 9
15 16
18 15
17 18
*/