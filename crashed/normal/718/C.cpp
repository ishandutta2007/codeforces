//RESUBMIT
#include <cstdio>
#include <cstring>

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5, MAXSIZ = 3;

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ){ f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ){ x = ( x << 3 ) + ( x << 1 ) + s - '0', s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ), x = -x; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

struct matrix
{
    int mat[MAXSIZ][MAXSIZ], n, m;
    matrix(){ n = m = 0, memset( mat, 0, sizeof mat ); }
    matrix( const int N, const int M ) { n = N, m = M, memset( mat, 0, sizeof mat ); }
    int* operator [] ( const int indx ) { return mat[indx]; }
    matrix operator * ( matrix other ) const 
    {
        matrix ret = matrix( n, other.m );
        for( int i = 1 ; i <= n ; i ++ )
            for( int j = 1 ; j <= m ; j ++ )
                if( mat[i][j] )
                    for( int k = 1 ; k <= ret.m ; k ++ ) 
                    {
                        ret[i][k] += 1ll * mat[i][j] * other[j][k] % mod;
                        if( ret[i][k] > mod ) ret[i][k] -= mod;
                    }
        return ret;
    }
    bool operator == ( matrix other ) const
    {
        if( n ^ other.n || m ^ other.m ) return false;
        for( int i = 1 ; i <= n ; i ++ )
            for( int j = 1 ; j <= m ; j ++ )
                if( mat[i][j] ^ other[i][j] ) return false;
        return true;
    }
    bool operator != ( matrix other ) const { return ! ( *this == other ); }
    void operator *= ( matrix other ) { *this = *this * other; }
};

struct vector
{
    int vec[MAXSIZ], n;
    vector(){ n = 0, memset( vec, 0, sizeof vec ); }
    vector( const int N ) { n = N, memset( vec, 0, sizeof vec ); }
    int& operator [] ( const int indx ) { return vec[indx]; }
    vector operator * ( matrix other ) const
    {
        vector ret = vector( n );
        for( int i = 1 ; i <= n ; i ++ )
            for( int j = 1 ; j <= ret.n ; j ++ ) 
            {
                ret[i] += 1ll * vec[j] * other[j][i] % mod;
                if( ret[i] > mod ) ret[i] -= mod;
            }
        return ret;
    }
    vector operator + ( vector other ) const 
    {
        vector ret = *this;
        for( int i = 1 ; i <= n ; i ++ ) 
        {
            ret[i] += other[i];
            if( ret[i] > mod ) ret[i] -= mod;
        }
        return ret;
    }
    void operator *= ( matrix other ) { *this = *this * other; }
    void operator += ( vector other ) { *this = *this + other; }
};

struct segmentTreeNode
{
	vector s; matrix tag;
	#define s( a ) ( segTree[a].s )
	#define tag( a ) ( segTree[a].tag )
}segTree[MAXN << 2];

matrix I, B;
vector A;

int a[MAXN];
int N, M;

void upt( const int x ) { s( x ) = s( x << 1 ) + s( x << 1 | 1 ); }
void prod( const int x, const matrix v ) { s( x ) *= v, tag( x ) *= v; }
void normalize( const int x ) { if( tag( x ) != I ) prod( x << 1, tag( x ) ), prod( x << 1 | 1, tag( x ) ), tag( x ) = I; }

void init()
{ 
	I = matrix( 2, 2 ); for( int i = 1 ; i <= 2 ; i ++ ) I[i][i] = 1; 
	B = matrix( 2, 2 ); B[1][1] = B[2][1] = B[1][2] = 1;
	A = vector( 2 ); A[1] = 1;
}

matrix qkpow( matrix base, int indx )
{
	if( indx < 0 ) return I;
	matrix ret = I;
	while( indx )
	{
		if( indx & 1 ) ret *= base;
		base *= base, indx >>= 1;
	}
	return ret;
}

void build( const int u, const int l, const int r )
{
	if( l > r ) return ;
	tag( u ) = I; int mid = l + r >> 1;
	if( l == r ) { s( u ) = A * qkpow( B, a[l] - 1 ); return; }
	build( u << 1, l, mid ), build( u << 1 | 1, mid + 1, r );
	upt( u );
}

void update( const int x, const int l, const int r, const int segL, const int segR, const matrix v )
{
	#ifdef _DEBUG
	segmentTreeNode &node1 = segTree[x];
	#endif
	int mid = l + r >> 1;
	if( segL <= l && r <= segR ) { prod( x, v ); return; }
	if( l == r ) return; normalize( x );
	if( segL <= mid ) update( x << 1, l, mid, segL, segR, v );
	if( segR > mid ) update( x << 1 | 1, mid + 1, r, segL, segR, v );
	upt( x ); 
}

int query( const int x, const int l, const int r, const int segL, const int segR )
{
	#ifdef _DEBUG
	segmentTreeNode &node2 = segTree[x];
	#endif
	int mid = l + r >> 1, ret = 0;
	if( segL <= l && r <= segR ) return s( x )[1];
	if( l == r ) return 0; normalize( x );
	if( segL <= mid ) ( ret += query( x << 1, l, mid, segL, segR ) ) %= mod;
	if( segR > mid ) ( ret += query( x << 1 | 1, mid + 1, r, segL, segR ) ) %= mod;
	return ret;
}

int main()
{
	matrix tmp;
	int opt, optL, optR, optV;
	init();
	read( N ), read( M );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] );
	build( 1, 1, N );
	while( M -- )
	{
		read( opt ), read( optL ), read( optR );
		if( opt == 1 ) 
		{
			read( optV );
			tmp = qkpow( B, optV );
			update( 1, 1, N, optL, optR, tmp );
		}
		else write( query( 1, 1, N, optL, optR ) ), putchar( '\n' );
	}
	return 0;
}