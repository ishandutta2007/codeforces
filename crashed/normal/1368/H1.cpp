#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ); s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

char S[MAXN];
int up[MAXN], down[MAXN], lef[MAXN], rig[MAXN];
int N, M, Q;

void Get( const int n, int *a )
{
	scanf( "%s", S + 1 );
	for( int i = 1 ; i <= n ; i ++ ) 
		a[i] = S[i] == 'R';
}

int Calc()
{
	int f0 = 0, f1 = 0, n0, n1;
	for( int i = 1 ; i <= M ; i ++ ) f0 += up[i], f1 += ! up[i];
	for( int i = 1 ; i <= N ; i ++ )
	{
		n0 = MIN( f0, f1 + M ) + lef[i] + rig[i];
		n1 = MIN( f0 + M, f1 ) + ( ! lef[i] ) + ( ! rig[i] );
		f0 = n0, f1 = n1;
	}
	for( int i = 1 ; i <= M ; i ++ ) f0 += down[i], f1 += ! down[i]; 
	return MIN( f0, f1 );
}

int main()
{
	read( N ), read( M ), read( Q );
	Get( N, lef ), Get( N, rig );
	Get( M, up ), Get( M, down );
	
	int ans1 = Calc(), ans2;
	swap( N, M ), swap( up, lef ), swap( down, rig );
	ans2 = Calc();
	
	write( MIN( ans1, ans2 ) ), putchar( '\n' );
	return 0;
}