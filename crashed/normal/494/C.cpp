#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXM = 5005, MAXN = 1e5 + 5, MAXLOG = 18;

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

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

struct interval
{
	int l, r; double p;
	
	interval() { l = r = p = 0; }
	interval( const int L, const int R, const double P ) { l = L, r = R, p = P; }
}I[MAXM];

vector<int> ins[MAXN];

int ST[MAXN][MAXLOG], lg[MAXN];

double f[MAXM][MAXM];
int mx[MAXM], stk[MAXM];
int a[MAXN];
int N, M, top;
bool inS[MAXM];

void read( interval &in )
{
	in = interval();
	read( in.l ), read( in.r ), scanf( "%lf", &in.p );
}

void init()
{
	lg[1] = 0;
	for( int i = 2 ; i <= N ; i ++ )
		lg[i] = lg[i - 1] + ( i == ( 1 << lg[i - 1] + 1 ) );
	
	for( int i = 1 ; i <= N ; i ++ ) ST[i][0] = a[i];
	for( int j = 1 ; j <= lg[N] ; j ++ )
		for( int i = 1 ; i + ( 1 << j - 1 ) <= N ; i ++ )
			ST[i][j] = MAX( ST[i][j - 1], ST[i + ( 1 << j - 1 )][j - 1] );
}

int query( const int l, const int r )
{
	int k = lg[r - l + 1];
	return MAX( ST[l][k], ST[r - ( 1 << k ) + 1][k] );
}

void insert( const int id ) { ins[I[id].l].push_back( id ); }
bool cmp( const int &x, const int &y ) { return I[x].r > I[y].r; }

int main()
{
	read( N ), read( M );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	for( int i = 1 ; i <= M ; i ++ ) read( I[i] ), insert( i );
	init();
	for( int i = 1 ; i <= N ; i ++ ) sort( ins[i].begin(), ins[i].end(), cmp );
	for( int i = 1 ; i <= M ; i ++ ) mx[i] = query( I[i].l, I[i].r );
	for( int i = 0 ; i <= M ; i ++ ) f[0][i] = 1;
	stk[top] = 0, mx[0] = query( 1, N );
	for( int i = 1, fa, u ; i <= N ; i ++ )
	{
		for( int j = 0 ; j < ins[i].size() ; j ++ )
		{
			inS[stk[++ top] = u = ins[i][j]] = true;
			for( int k = 0 ; k <= M ; k ++ ) f[u][k] = 1;
		}
		while( I[stk[top]].r == i )
		{
			u = stk[top];
			for( int k = M ; ~ k ; k -- )
			{
				f[u][k] *= ( 1 - I[u].p );
				if( k ) f[u][k] += I[u].p * f[u][k - 1];
			}
			fa = stk[-- top];
			for( int k = 0 ; k + mx[fa] - mx[u] <= M ; k ++ )
				f[fa][k] *= f[u][k + mx[fa] - mx[u]];
		}
	}
	double ans = f[0][0] * mx[0];
	for( int k = 1 ; k <= M ; k ++ ) ans += ( f[0][k] - f[0][k - 1] ) * ( mx[0] + k );
	printf( "%.9lf\n", ans );
	return 0;
}