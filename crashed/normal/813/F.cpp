#include <map>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> Edge;

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
void swapp( _T &x, _T &y )
{
	_T t = x; x = y, y = t;
}

struct edge
{
	int u, v, l, r;
	edge() {}
	edge( const int U, const int V, const int L, const int R ) { u = U, v = V, l = L, r = R; }
};

vector<edge> E;
map<Edge, int> mp;

int ch[MAXN][2], fa[MAXN], siz[MAXN];
int N, Q;
bool rev[MAXN];

bool chk( const int u ) { return ch[fa[u]][1] == u; }
bool isRt( const int u ) { return ch[fa[u]][0] ^ u && ch[fa[u]][1] ^ u; }
bool nrt( const int u ) { return ! isRt( u ); }
void upt( const int u ) { if( u ) siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1; }
void rever( const int u ) { if( u ) swapp( ch[u][0], ch[u][1] ), rev[u] ^= 1; }
void normalize( const int u ) { if( u && rev[u] ) rever( ch[u][0] ), rever( ch[u][1] ), rev[u] = false; }
void tagClean( const int u ) { if( nrt( u ) ) tagClean( fa[u] ); normalize( u ); }

void rotate( const int x )
{
	if( ! x || isRt( x ) ) return ;
	int y = fa[x], z = fa[y], side = chk( x ), son = ch[x][! side];
	if( z && nrt( y ) ) ch[z][chk( y )] = x; ch[x][! side] = y, ch[y][side] = son;
	if( son ) fa[son] = y; fa[y] = x, fa[x] = z;
	upt( y ), upt( x ), upt( z );
}

void splay( const int x )
{
	tagClean( x );
	for( int y ; nrt( x ) ; rotate( x ) )
		if( nrt( y = fa[x] ) ) rotate( chk( y ) == chk( x ) ? y : x );
}

void access( int x ) { for( int y = 0 ; x ; x = fa[y = x] ) splay( x ), ch[x][1] = y, upt( x ); }
void makeRt( const int x ) { access( x ), splay( x ), rever( x ); }
int findRt( int x ) { access( x ), splay( x ); while( ch[x][0] ) normalize( x ), x = ch[x][0]; splay( x ); return x; }
bool link( const int x, const int y ) { makeRt( x ); if( findRt( y ) == x ) return false; fa[x] = y; return true; }
void cut( const int x, const int y ) { makeRt( x ), access( y ), splay( x ); ch[x][1] = fa[y] = 0, upt( x ); }
int query( const int x, const int y ) { makeRt( x ), access( y ), splay( y ); return siz[y]; }

void divide( const int l, const int r, vector<edge> cur )
{
	vector<edge> L, R; vector<int> sta; int siz = cur.size(), len, mid = l + r >> 1;
	for( int i = 0 ; i < siz ; i ++ )
	{
		#ifdef _DEBUG
		edge now = cur[i];
		#endif
		if( cur[i].l <= l && r <= cur[i].r )
		{
			if( link( cur[i].u, cur[i].v ) ) { sta.push_back( i ); continue; }
			len = query( cur[i].u, cur[i].v );
			if( len & 1 )
			{
				for( int j = l ; j <= r ; j ++ ) puts( "NO" );
				for( int j = 0 ; j < sta.size() ; j ++ ) cut( cur[sta[j]].u, cur[sta[j]].v );
				return ;
			}
		}
		if( cur[i].l <= mid ) L.push_back( cur[i] );
		if( cur[i].r > mid ) R.push_back( cur[i] );
	}
	if( l == r ) puts( "YES" );
	else divide( l, mid, L ), 
		 divide( mid + 1, r, R );
	for( int i = 0 ; i < sta.size() ; i ++ ) cut( cur[sta[i]].u, cur[sta[i]].v );
}

int main()
{
	Edge in;
	read( N ), read( Q );
	for( int i = 1 ; i <= N ; i ++ ) siz[i] = 1;
	for( int i = 1, l ; i <= Q ; i ++ )
	{
		read( in.first ), read( in.second );
		if( l = mp[in] ) E.push_back( edge( in.first, in.second, l, i - 1 ) ), mp[in] = 0;
		else mp[in] = i;
	}
	for( map<Edge, int> :: iterator it = mp.begin() ; it != mp.end() ; it ++ )
		if( it->second ) E.push_back( edge( it->first.first, it->first.second, it->second, Q ) );
	divide( 1, Q, E );
	return 0;
}