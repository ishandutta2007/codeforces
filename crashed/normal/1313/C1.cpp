#include <cstdio>

typedef long long LL;

const int MAXN = 5e5 + 5;

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

int sta1[MAXN], sta2[MAXN], ans[MAXN], top1, top2;
LL m[MAXN], tmp[MAXN], mx;
int N, mxIndx;

void build1( const int up )
{
	top1 = 0;
	LL ans1 = 0;
	for( int i = 1 ; i <= up ; i ++ )
	{
		while( top1 && m[sta1[top1]] >= m[i] )
			ans1 -= 1ll * ( sta1[top1] - sta1[top1 - 1] ) * m[sta1[top1]], top1 --;
		ans1 += 1ll * ( i - sta1[top1] ) * m[i], sta1[++ top1] = i;
		tmp[i] = ans1;
	}
}

void build2( const int low )
{
	sta2[0] = N + 1;
	mxIndx = N, mx = tmp[N];
	top2 = 0;
	LL ans2 = 0;
	for( int i = N ; i >= low ; i -- )
	{
		while( top2 && m[sta2[top2]] >= m[i] )
			ans2 -= 1ll * ( sta2[top2 - 1] - sta2[top2] ) * m[sta2[top2]], top2 --;
		ans2 += 1ll * ( sta2[top2] - i ) * m[i], sta2[++ top2] = i;
		if( mx < ans2 + tmp[i - 1] ) mx = ans2 + tmp[i - 1], mxIndx = i;
	}
}

int main()
{
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) read( m[i] );
	build1( N );
	build2( 1 );
	int t = mxIndx;
	build1( t - 1 );
	build2( t );
	for( int i = 1 ; i <= top1 ; i ++ )
		for( int j = sta1[i - 1] + 1 ; j <= sta1[i] ; j ++ )
			ans[j] = m[sta1[i]];
	for( int i = 1 ; i <= top2 ; i ++ )
		for( int j = sta2[i] ; j < sta2[i - 1] ; j ++ )
			ans[j] = m[sta2[i]];
	for( int i = 1 ; i <= N ; i ++ ) write( ans[i] ), putchar( i == N ? '\n' : ' ' );
	return 0;
}