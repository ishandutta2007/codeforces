#include <cstdio>

#define rep( x, a, b ) for( int ( x ) = a ; x <= b ; x ++ )
#define per( x, a, b ) for( int ( x ) = a ; x >= b ; x -- )

typedef long long LL;

const int MAXN = 1e6 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
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

int stk1[MAXN], stk2[MAXN];

int a[MAXN];
int N;

int main()
{
	read( N );
	int top1 = 0, top2 = 0;
	LL su = 0, mn = 0, mx = 0;
	rep( i, 1, N ) read( a[i] );
	rep( i, 1, N ) 
	{
		while( top1 && a[stk1[top1]] > a[i] )
			mn -= 1ll * ( a[stk1[top1]] - a[stk1[top1 - 1]] ) * ( i - stk1[top1 - 1] - 1 ), top1 --;
		mn += 1ll * ( a[i] - a[stk1[top1]] ) * ( i - stk1[top1] - 1 ) + a[i], stk1[++ top1] = i;
		while( top2 && a[stk2[top2]] < a[i] )
			mx += 1ll * ( a[stk2[top2 - 1]] - a[stk2[top2]] ) * ( i - stk2[top2 - 1] - 1 ), top2 --;
		mx -= 1ll * ( a[stk2[top2]] - a[i] ) * ( i - stk2[top2] - 1 ) - a[i], stk2[++ top2] = i;
		su += mx - mn;
	}
	write( su ), putchar( '\n' );
	return 0;
}