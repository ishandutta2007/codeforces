#include <cstdio>

typedef long long LL;
typedef long double LB;

const int MAXN = 55;

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

LB fac[MAXN];
double f[MAXN][MAXN], g[MAXN], tmp[MAXN];
int head[MAXN], siz[MAXN];
int N, cnt;

void addEdge( const int from, const int to )
{
	Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
	head[from] = cnt;
}

void init()
{
	fac[0] = 1;
	for( int i = 1 ; i <= N ; i ++ )
		fac[i] = fac[i - 1] * i;
}

LB C( const int n, const int m ) { return fac[n] / fac[m] / fac[n - m]; }

void DFS( const int u, const int fa )
{
	siz[u] = 1;
	f[u][0] = 1; for( int i = 1 ; i <= N ; i ++ ) f[u][i] = 0;
	for( int i = head[u], v ; i ; i = Graph[i].nxt )
		if( ( v = Graph[i].to ) ^ fa )
		{
			DFS( v, u );
			for( int k = 0 ; k <= N ; k ++ ) tmp[k] = g[k] = 0;
			for( int k = 0 ; k <= siz[v] ; k ++ )
				for( int j = 0 ; j <= k ; j ++ )
				{
					if( k == j ) g[k] += ( siz[v] - k ) * f[v][j];
					else g[k] += 0.5 * f[v][j];
				}
			for( int j = 0 ; j < siz[u] ; j ++ )
				for( int k = 0 ; k <= siz[v] ; k ++ )
					tmp[j + k] += f[u][j] * g[k] * C( j + k, j ) * C( siz[u] - j - 1 + siz[v] - k, siz[v] - k );
			siz[u] += siz[v];
			for( int k = 0 ; k < siz[u] ; k ++ ) f[u][k] = tmp[k];
		}
}

int main()
{
	read( N );
	for( int i = 1, a, b ; i < N ; i ++ )
		read( a ), read( b ), addEdge( a, b ), addEdge( b, a );
	init();
	for( int i = 1 ; i <= N ; i ++ ) 
	{
		DFS( i, 0 );
		printf( "%.10lf\n", f[i][N - 1] / ( double ) fac[N - 1] );
	}
	return 0;
}