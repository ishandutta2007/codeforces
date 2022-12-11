#include <cstdio>

const int mod = 1e9 + 7;
const int MAXN = 305;

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

int fac[MAXN], ifac[MAXN];
int f[MAXN][MAXN], C[MAXN][MAXN];
int val[MAXN], cnt[MAXN];
int N, tot;

int qkpow( int, int );
int inv( const int a ) { return qkpow( a, mod - 2 ); }
void sub( int &x, const int v ) { x = ( x < v ? x - v + mod : x - v ); }
void add( int &x, const int v ) { x = ( x + v >= mod ? x + v - mod : x + v ); }

void insert( int v )
{
	int nw = 1;
	for( int i = 2 ; i * i <= v ; i ++ )
		if( ! ( v % i ) )
		{
			int indx = 0;
			while( ! ( v % i ) ) 
				v /= i, indx ++;
			if( indx & 1 ) nw *= i;
		}
	if( v > 1 ) nw *= v;
	for( int i = 1 ; i <= tot ; i ++ )
		if( val[i] == nw )
			{ cnt[i] ++; return ; }
	val[++ tot] = nw, cnt[tot] ++;
}

int qkpow( int base, int indx )
{
	int ret = 1;
	while( indx )
	{
		if( indx & 1 ) ret = 1ll * ret * base % mod;
		base = 1ll * base * base % mod, indx >>= 1;
	}
	return ret;
}

int main()
{
	read( N );
	for( int i = 1, a ; i <= N ; i ++ ) read( a ), insert( a );
	
	for( int i = 0 ; i <= N ; i ++ )
	{
		C[i][0] = C[i][i] = 1;
		for( int j = 1 ; j < i ; j ++ )
			C[i][j] = ( C[i - 1][j] + C[i - 1][j - 1] ) % mod;
	}
	ifac[0] = fac[0] = 1;
	for( int i = 1 ; i <= N ; i ++ )
		fac[i] = 1ll * fac[i - 1] * i % mod,
		ifac[i] = inv( fac[i] );
		
	f[0][0] = 1;
	for( int i = 1 ; i <= tot ; i ++ )
		for( int j = N ; ~ j ; j -- )
			for( int k = 1 ; k <= cnt[i] ; k ++ )
				add( f[i][j + k], 1ll * f[i - 1][j] * C[cnt[i] - 1][k - 1] % mod * ifac[k] % mod * fac[cnt[i]] % mod );
	
	int ans = 0;
	for( int i = 0 ; i <= N ; i ++ )
	{
		if( ( N - i ) & 1 ) sub( ans, 1ll * fac[i] * f[tot][i] % mod );
		else add( ans, 1ll * fac[i] * f[tot][i] % mod );
	}
	write( ans ), putchar( '\n' );
	return 0;
}