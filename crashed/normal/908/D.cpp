#include <cstdio>

typedef long long LL;

const int mod = 1e9 + 7;
const int MAXN = 1005;

template<typename _T>
inline void read( _T &x )
{
	x = 0;char s = getchar();int f = 1;
	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
	x *= f;
}

template<typename _T>
inline void write( _T x )
{
	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

int f[MAXN][MAXN];
int K, pa, pb;

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

int inv( const int x ) { return qkpow( x, mod - 2 ); }
void add( int &x, const int v ) { x = ( x + v >= mod ? x + v - mod : x + v ); }

int main()
{
	read( K ), read( pa ), read( pb );
	
	int t = inv( pa + pb ); 
	pa = 1ll * pa * t % mod, pb = 1ll * pb * t % mod;
	
	for( int i = K ; ~ i ; i -- )
		for( int j = K ; j ; j -- )
			if( i + j >= K ) f[i][j] = ( i + j + 1ll * pa * inv( pb ) % mod ) % mod;
			else f[i][j] = ( 1ll * pa * f[i][j + 1] % mod + 1ll * pb * f[i + j][j] % mod ) % mod;
	write( f[0][1] ), putchar( '\n' );
	return 0;
}