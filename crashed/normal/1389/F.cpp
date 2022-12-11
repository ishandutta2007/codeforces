#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = -0xc0c0c0c0;
const int MAXN = 2e5 + 5;

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

vector<int> seg[2][MAXN << 1];

int pos[MAXN << 1];
int l[MAXN], r[MAXN], t[MAXN];
int N, len;

struct SegmentTree
{
	int mx[MAXN << 3], tag[MAXN << 3] = {};
	
	SegmentTree() { memset( mx, 0xc0, sizeof mx ); }
	void Upt( const int x ) { mx[x] = MAX( mx[x << 1], mx[x << 1 | 1] ); }
	void Add( const int x, const int v ) { if( x ) mx[x] += v, tag[x] += v; }
	void Normalize( const int x ) { if( x && tag[x] ) Add( x << 1, tag[x] ), Add( x << 1 | 1, tag[x] ), tag[x] = 0; }
	
	void Set( const int x, const int l, const int r, const int p, const int v )
	{
		if( l == r ) { mx[x] = MAX( mx[x], v ); return ; }
		int mid = l + r >> 1; Normalize( x );
		if( p <= mid ) Set( x << 1, l, mid, p, v );
		else Set( x << 1 | 1, mid + 1, r, p, v );
		Upt( x );
	}
	
	void Update( const int x, const int l, const int r, const int segL, const int segR, const int delt )
	{
		if( segL <= l && r <= segR ) { Add( x, delt ); return ; }
		int mid = l + r >> 1; Normalize( x );
		if( segL <= mid ) Update( x << 1, l, mid, segL, segR, delt );
		if( mid < segR ) Update( x << 1 | 1, mid + 1, r, segL, segR, delt );
		Upt( x );
	}
	
	int Query( const int x, const int l, const int r, const int segL, const int segR )
	{
		if( segL <= l && r <= segR ) return mx[x];
		int mid = l + r >> 1, ret = -1; Normalize( x );
		if( segL <= mid ) ret = MAX( ret, Query( x << 1, l, mid, segL, segR ) );
		if( mid < segR ) ret = MAX( ret, Query( x << 1 | 1, mid + 1, r, segL, segR ) );
		return ret;
	}
	
	void Set( const int p, const int v ) { Set( 1, 0, len, p, v ); }
	int Query( const int L, const int R ) { return L > R ? -1 : Query( 1, 0, len, L, R ); }
	void Update( const int L, const int R, const int delt ) { if( L <= R ) Update( 1, 0, len, L, R, delt ); }
};

SegmentTree f[2];

void Discrete()
{
	len = 0;
	for( int i = 1 ; i <= N ; i ++ )
		pos[++ len] = l[i], pos[++ len] = r[i];
	sort( pos + 1, pos + 1 + len );
	len = unique( pos + 1, pos + 1 + len ) - pos - 1;
	for( int i = 1 ; i <= N ; i ++ )
		l[i] = lower_bound( pos + 1, pos + 1 + len, l[i] ) - pos,
		r[i] = lower_bound( pos + 1, pos + 1 + len, r[i] ) - pos;
}

int main()
{
	read( N ); 
	for( int i = 1 ; i <= N ; i ++ ) 
		read( l[i] ), read( r[i] ), read( t[i] ), t[i] --;
	Discrete();
	
	for( int i = 1 ; i <= N ; i ++ )
		seg[t[i]][r[i]].push_back( i );
	f[0].Set( 0, 0 ), f[1].Set( 0, 0 );
	for( int i = 1 ; i <= len ; i ++ )
	{
		for( int c = 0 ; c < 2 ; c ++ )
			for( int k = 0 ; k < ( int ) seg[c][i].size() ; k ++ )
				f[c ^ 1].Update( 0, l[seg[c][i][k]] - 1, 1 );
		for( int c = 0 ; c < 2 ; c ++ )
		{
			int val = 0;
			for( int k = 0 ; k < ( int ) seg[c][i].size() ; k ++ )
				val = MAX( val, f[c ^ 1].Query( 0, l[seg[c][i][k]] - 1 ) );
			f[c].Set( i, val );
		}
	}
	write( MAX( f[0].Query( 0, len ), f[1].Query( 0, len ) ) ), putchar( '\n' );
	return 0;
}