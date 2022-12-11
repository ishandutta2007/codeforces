#include <cstdio>
#include <iostream>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
const int MAXN = 5e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( ! ( '0' <= s && s <= '9' ) ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

struct Lady
{
	int b, i, r;
	
	Lady(): b( 0 ), i( 0 ), r( 0 ) {}
	Lady( int B, int I, int R ): b( B ), i( I ), r( R ) {}
	bool operator < ( const Lady &q ) const { return b < q.b; }
};

int mx[MAXN << 2];

Lady ladies[MAXN];
int N, tot;

inline void Upt( const int &x ) { mx[x] = std :: max( mx[x << 1], mx[x << 1 | 1] ); }

void Build( const int x, const int l, const int r )
{
	if( l > r ) return ; mx[x] = - INF;
	if( l == r ) return ;
	int mid = ( l + r ) >> 1;
	Build( x << 1, l, mid );
	Build( x << 1 | 1, mid + 1, r );
	Upt( x );
}

void Update( const int x, const int l, const int r, const int p, const int v )
{
	if( l == r ) { mx[x] = std :: max( mx[x], v ); return ; }
	int mid = ( l + r ) >> 1;
	if( p <= mid ) Update( x << 1, l, mid, p, v );
	else Update( x << 1 | 1, mid + 1, r, p, v );
	Upt( x );
}

int Query( const int x, const int l, const int r, const int segL, const int segR )
{
	if( segL <= l && r <= segR ) return mx[x];
	int mid = ( l + r ) >> 1, ret = - INF;
	if( segL <= mid ) ret = std :: max( ret, Query( x << 1, l, mid, segL, segR ) );
	if( mid  < segR ) ret = std :: max( ret, Query( x << 1 | 1, mid + 1, r, segL, segR ) );
	return ret;
}

void Discrete()
{
	static int val[MAXN]; tot = 0;
	rep( i, 1, N ) val[++ tot] = ladies[i].i;
	std :: sort( val + 1, val + 1 + tot );
	tot = std :: unique( val + 1, val + 1 + tot ) - val - 1;
	rep( i, 1, N ) ladies[i].i = std :: lower_bound( val + 1, val + 1 + tot, ladies[i].i ) - val;
}

int main()
{
	read( N );
	rep( i, 1, N ) read( ladies[i].b );
	rep( i, 1, N ) read( ladies[i].i );
	rep( i, 1, N ) read( ladies[i].r );
	
	Discrete();
	std :: sort( ladies + 1, ladies + 1 + N );
	
	int ans = 0;
	for( int i = N, j ; i ; i = j )
	{
		for( j = i ; j && ladies[j].b == ladies[i].b ; j -- );
		for( int k = i ; k > j ; k -- )
			if( Query( 1, 1, tot, ladies[k].i + 1, tot ) > ladies[k].r )
				ans ++;
		for( int k = i ; k > j ; k -- )
			Update( 1, 1, tot, ladies[k].i, ladies[k].r );
	}
	write( ans ), putchar( '\n' );
	return 0;
}