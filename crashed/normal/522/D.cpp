#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> Query;
typedef pair<int, int> number;

const int INF = 0x3f3f3f3f;
const int MAXN = 5e5 + 5, MAXM = 5e5 + 5;

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

vector<Query> q[MAXN];
number num[MAXN];

int mn[MAXN << 2];

int ans[MAXM];
int a[MAXN], lst[MAXN];
int N, M;

void upt( int x ) { mn[x] = MIN( mn[x << 1], mn[x << 1 | 1] ); }

void build( int u, int l, int r )
{
	if( l > r ) return ;
	int mid = l + r >> 1; mn[u] = INF;
	if( l == r ) return ;
	build( u << 1, l, mid ), build( u << 1 | 1, mid + 1, r );
}

void update( int u, int l, int r, int pos, int v )
{
	if( l == r ) { mn[u] = v; return ; }
	int mid = l + r >> 1;
	if( pos <= mid ) update( u << 1, l, mid, pos, v );
	else update( u << 1 | 1, mid + 1, r, pos, v );
	upt( u );
}

int query( int u, int l, int r, int segL, int segR )
{
	if( segL <= l && r <= segR ) return mn[u];
	if( l == r ) return INF;
	int mid = l + r >> 1, ret = INF;
	if( segL <= mid ) ret = MIN( ret, query( u << 1, l, mid, segL, segR ) );
	if( segR > mid ) ret = MIN( ret, query( u << 1 | 1, mid + 1, r, segL, segR ) );
	return ret;
}

int main()
{
	int tot = 0, l, r;
	read( N ), read( M );
	for( int i = 1 ; i <= N ; i ++ ) read( num[i].first ), num[i].second = i;
	sort( num + 1, num + 1 + N );
	for( int i = 1 ; i <= N ; i ++ ) a[num[i].second] = ( tot += ( num[i].first != num[i - 1].first ) );
	for( int i = 1 ; i <= M ; i ++ ) read( l ), read( r ), q[r].push_back( Query( l, i ) );
	build( 1, 1, N );
	for( int i = 1 ; i <= N ; i ++ )
	{
		if( lst[a[i]] ) update( 1, 1, N, lst[a[i]], i - lst[a[i]] );
		lst[a[i]] = i;
		for( int j = 0 ; j < q[i].size() ; j ++ ) ans[q[i][j].second] = query( 1, 1, N, q[i][j].first, i );
	}
	for( int i = 1 ; i <= M ; i ++ ) write( ans[i] == INF ? -1 : ans[i] ), putchar( '\n' );
	return 0;
}