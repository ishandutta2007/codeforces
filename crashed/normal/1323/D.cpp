#include <cstdio>
#include <cstring>

typedef long long LL;

#define int LL

const int MAXN = 4e5 + 5, MAXV = 1e7 + 5;

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

struct bit
{
	int BIT[MAXV], siz;

	bit() { siz = 0; }
	bit( const int S ) { siz = S; for( int i = 1 ; i <= siz ; i ++ ) BIT[i] = 0; } 
	int lowbit( const int &x ) { return x & ( -x ); }
	void clear() { for( int i = 1 ; i <= siz ; i ++ ) BIT[i] = 0; }
	void update( const int x, const int v ) { for( int i = x ; i <= siz ; i += lowbit( i ) ) BIT[i] += v; }
	int getSum( int x ) 
	{ 
		x = x > siz ? siz : x;
		int ret = 0; 
		while( x ) 
			ret += BIT[x], x -= lowbit( x ); 
		return ret; 
	}
	int query( const int l, const int r ) { return getSum ( r ) - getSum ( l - 1 ); }
}T[2];

int a[MAXN];
int N, mx;

signed main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] ), mx = MAX( mx, a[i] );
	int ans = 0, up;
	T[0] = T[1] = bit( mx + 1 );
	for( int k = 0, tot, left ; ( 1 << k ) <= mx * 2 ; k ++ )
	{
		up = 1ll << k, tot = 0;
		T[0].clear(), T[1].clear();
		for( int i = 1 ; i <= N ; i ++ )
		{
			left = a[i] % up;
			if( ( a[i] >> k ) & 1 ) tot += T[0].getSum( up - left ) + T[1].query( up - left + 1, mx + 1 );
			else tot += T[1].getSum( up - left ) + T[0].query( up - left + 1, mx + 1 );
			T[( a[i] >> k ) & 1].update( left + 1, 1 );
		}
		if( tot & 1 ) ans += 1ll << k;
	}
	write( ans ), putchar( '\n' );
	return 0;
}
/*
3
4 5 6
*/