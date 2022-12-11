#include <cmath>
#include <cstdio>
#include <algorithm>

typedef long long LL;

#define int LL

const int MAXN = 1e5 + 5, MAXLOG = 17;

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

int mod;

void add( int& , const int );

struct matrix
{
	int mat[3][3] = {};
	int n, m;
	
	matrix() { n = m = 0; }
	matrix( const int N ) { n = m = N; }
	matrix( const int N, const int M ) { n = N, m = M; }
	
	int* operator [] ( const int indx ) { return mat[indx]; }
	
	matrix operator * ( matrix b ) const
	{
		matrix ret = matrix( n, b.m );
		for( int i = 1 ; i <= ret.n ; i ++ )
			for( int k = 1 ; k <= m ; k ++ )
				if( mat[i][k] )
					for( int j = 1 ; j <= ret.m ; j ++ )
						add( ret[i][j], 1ll * mat[i][k] * b[k][j] % mod );
		return ret;
	}
	
	void operator *= ( matrix b ) { *this = *this * b; }
};

matrix prod[MAXN][MAXLOG];
matrix whole, vec;

int seq[MAXN];
int ind[MAXN], val[MAXN];
int s[MAXN];
int N, M, lg2;
LL K;

int go( const LL x, const int stp ) { return ( x + stp ) % N; }
bool cmp( const int &x, const int &y ) { return ind[x] < ind[y]; }
void add( int &x, const int v ) { x = ( x + v >= mod ? x + v - mod : x + v ); }
matrix I( const int n ) { matrix ret( n ); for( int i = 1 ; i <= n ; i ++ ) ret[i][i] = 1; return ret; }

matrix gen( const int indx )
{
	matrix ret( 2, 2 );
	ret[1][1] = s[go( indx, 1 )], ret[1][2] = 1;
	ret[2][1] = s[indx], ret[2][2] = 0;
	return ret;
}

matrix qkpow( matrix base, LL indx )
{
	matrix ret = I( base.n );
	while( indx )
	{
		if( indx & 1 ) ret *= base;
		base *= base, indx >>= 1;
	}
	return ret;
}

void init()
{
	lg2 = log2( N );
	whole = matrix( 2 );
	vec = matrix( 1, 2 );
	vec[1][1] = 1, vec[1][2] = 0;
	whole[1][1] = whole[2][2] = 1; 
	for( int i = 0 ; i < N ; i ++ ) prod[i][0] = gen( i ), whole *= prod[i][0];
	for( int j = 1 ; j <= lg2 ; j ++ )
	{
		for( int i = 0 ; i < N ; i ++ ) prod[i][j] = I( 2 );
		for( int i = 0 ; i + ( 1 << j - 1 ) < N ; i ++ ) 
			prod[i][j] = prod[i][j - 1] * prod[i + ( 1 << j - 1 )][j - 1];
	}
}

//O(nlogn)

matrix get( LL l, LL r )
{
	matrix ret = I( 2 );
	for( int i = lg2 ; ~ i ; i -- )
		if( l + ( 1 << i ) <= r )
			ret *= prod[l][i], l += 1 << i;
	return ret;
}

//O(logn)

matrix calc( const LL l, const LL r )
{
	LL bL = l / N, bR = r / N;
	if( bL == bR ) return get( l % N, r % N );
	matrix ret = qkpow( whole, bR - bL - 1 );
	matrix lef = get( l % N, N );
	matrix rig = get( 0, r % N );
	return lef * ret * rig;
}

//O(logk+logn)

signed main()
{
	read( K ), read( mod );
	read( N ); for( int i = 0 ; i < N ; i ++ ) read( s[i] ), s[i] %= mod;
	read( M ); for( int i = 1 ; i <= M ; i ++ ) seq[i] = i, read( ind[i] ), read( val[i] ), val[i] %= mod;
	
	if( K == 0 ) return puts( "0" ), 0;
	if( K == 1 ) return puts( mod == 1 ? "0" : "1" ), 0;
	
	init();
	LL cur = 0;
	matrix trans;
	std :: sort( seq + 1, seq + 1 + M, cmp );
	for( int i = 1, p ; i <= M && ind[seq[i]] < K ; i ++ )
	{
		p = seq[i];
		trans = matrix( 2 );
		vec *= calc( cur, ind[p] - 1 );
		cur = ind[p] - 1;
		
		trans[1][1] = val[p], trans[1][2] = 1;
		trans[2][1] = ind[seq[i - 1]] == ( ind[p] - 1 ) ? val[seq[i - 1]] : s[go( ind[p], -1 )]; 
		trans[2][2] = 0; 
		vec *= trans, cur ++;
		
		if( ind[seq[i + 1]] != ind[p] + 1 && cur < K - 1 )
		{
			trans[1][1] = s[go( ind[p], 1 )], trans[1][2] = 1;
			trans[2][1] = val[p], trans[2][2] = 0;
			vec *= trans, cur ++;
		}
	}
	
	vec *= calc( cur, K - 1 );
	write( vec[1][1] ), putchar( '\n' );
	return 0;
}