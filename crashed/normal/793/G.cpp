#include <cstdio>
#include <algorithm>

const int INF = 0x3f3f3f3f;
const int MAXN = 1e4 + 5, MAXV = MAXN * 8, MAXE = MAXV * 10;

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

struct edge
{
	int to, nxt, c;
}Graph[MAXE << 2]; 

int q[MAXV];
int head[MAXV], dep[MAXV], cur[MAXV];

int id1[MAXV], id2[MAXV];

int X[MAXN * 3], Y[MAXN * 3];
int lx[MAXN], rx[MAXN], ly[MAXN], ry[MAXN];
int sx[MAXN], sy[MAXN], tx[MAXN], ty[MAXN];

int sta, tar;
int N, Q, tot, cnt = 1;

bool ban[MAXN][MAXN];

void addEdge( const int from, const int to, const int C )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from], Graph[cnt].c = C;
	head[from] = cnt;
}

void addE( const int from, const int to, const int C )
{
	addEdge( from, to, C ), addEdge( to, from, 0 );
}

bool BFS( const int S, const int T )
{
	for( int i = 1 ; i <= tot ; i ++ ) dep[i] = INF;
	int h = 1, t = 0, u, v; dep[q[++ t] = S] = 0;
	while( h <= t )
	{
		u = q[h ++];
		for( int i = head[u] ; i ; i = Graph[i].nxt )
			if( Graph[i].c && dep[v = Graph[i].to] == INF )
				dep[q[++ t] = v] = dep[u] + 1;
	}
	return dep[T] < INF;
}

int DFS( const int u, const int T, const int lin )
{
	if( u == T ) return lin;
	int ret, used = 0, v, c;
	for( int &i = cur[u] ; i ; i = Graph[i].nxt )
	{
		v = Graph[i].to, c = Graph[i].c;
		if( c && dep[v] == dep[u] + 1 && ( ret = DFS( v, T, MIN( lin - used, c ) ) ) )
		{
			used += ret, Graph[i].c -= ret, Graph[i ^ 1].c += ret;
			if( used == lin ) break;
		}
	}
	if( used < lin ) dep[u] = INF;
	return used;
}

int Dinic( const int S, const int T )
{
	int f = 0;
	while( BFS( S, T ) )
	{
		for( int i = 1 ; i <= tot ; i ++ ) cur[i] = head[i];
		f += DFS( S, T, INF );
	}
	return f;
}

bool build( const int x, const int l, const int r )
{
	if( l > r ) return false; 
	id1[x] = ++ tot, id2[x] = ++ tot;
	if( l == r )
	{
		addE( sta, id1[x], 1 );
		addE( id2[x], tar, 1 );
		return true;
	}
	int mid = l + r >> 1;
	if( build( x << 1, l, mid ) )
		addE( id1[x << 1], id1[x], INF ),
		addE( id2[x], id2[x << 1], INF );
	if( build( x << 1 | 1, mid + 1, r ) )
		addE( id1[x << 1 | 1], id1[x], INF ),
		addE( id2[x], id2[x << 1 | 1], INF );
	return true;
}

void update( const int x, const int l, const int r, const int segL, const int segR, const int fr )
{
	if( segL <= l && r <= segR ) { addE( fr, id2[x], INF ); return ; }
	int mid = l + r >> 1;
	if( segL <= mid ) update( x << 1, l, mid, segL, segR, fr );
	if( mid < segR ) update( x << 1 | 1, mid + 1, r, segL, segR, fr );
}

void update( const int x, const int l, const int r, const int segL, const int segR, const int limL, const int limR )
{
	if( segL <= l && r <= segR ) { update( 1, 1, N, limL, limR, id1[x] ); return ; }
	int mid = l + r >> 1;
	if( segL <= mid ) update( x << 1, l, mid, segL, segR, limL, limR );
	if( mid < segR ) update( x << 1 | 1, mid + 1, r, segL, segR, limL, limR );
}

int main()
{
	read( N ), read( Q );
	int totx = 0, toty = 0;
	for( int i = 1 ; i <= Q ; i ++ )
	{
		read( sx[i] ), read( sy[i] ), read( tx[i] ), read( ty[i] );
		sx[i] --, sy[i] --;
		X[++ totx] = sx[i], X[++ totx] = tx[i];
		Y[++ toty] = sy[i], Y[++ toty] = ty[i];
	}
	
	X[++ totx] = 0, X[++ totx] = N;
	Y[++ toty] = 0, Y[++ toty] = N;
	std :: sort( X + 1, X + 1 + totx );
	std :: sort( Y + 1, Y + 1 + toty );
	totx = std :: unique( X + 1, X + 1 + totx ) - X - 1;
	toty = std :: unique( Y + 1, Y + 1 + toty ) - Y - 1;
	for( int i = 1 ; i < totx ; i ++ ) lx[i] = X[i] + 1, rx[i] = X[i + 1];
	for( int i = 1 ; i < toty ; i ++ ) ly[i] = Y[i] + 1, ry[i] = Y[i + 1];
	for( int i = 1 ; i <= Q ; i ++ )
	{
		sx[i] = std :: lower_bound( X + 1, X + 1 + totx, sx[i] ) - X;
		sy[i] = std :: lower_bound( Y + 1, Y + 1 + toty, sy[i] ) - Y;
		tx[i] = std :: lower_bound( X + 1, X + 1 + totx, tx[i] ) - X - 1;
		ty[i] = std :: lower_bound( Y + 1, Y + 1 + toty, ty[i] ) - Y - 1;
		for( int j = sx[i] ; j <= tx[i] ; j ++ )
			for( int k = sy[i] ; k <= ty[i] ; k ++ )
				ban[j][k] = true;
	}
	
	sta = ++ tot, tar = ++ tot;
	build( 1, 1, N );
	for( int i = 1, limX ; i < totx ; i ++ )
		for( int j = 1, limY ; j < toty ; j ++ )
			if( ! ban[i][j] )
			{
				for( limY = j ; limY < toty && ! ban[i][limY] ; limY ++ );
				limY --;
				for( limX = i ; limX < totx ; limX ++ )
				{
					bool flg = false;
					for( int k = j ; k <= limY ; k ++ )
						if( ban[limX][k] ) { flg = true; break; }
					if( flg ) break;
					for( int k = j ; k <= limY ; k ++ )
						ban[limX][k] = true;
				}
				limX --;
				update( 1, 1, N, lx[i], rx[limX], ly[j], ry[limY] );
			}
	
	write( Dinic( sta, tar ) ), putchar( '\n' );
	return 0;
}