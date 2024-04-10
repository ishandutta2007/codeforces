#include <bits/stdc++.h>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 25, MAXS = ( 1 << 20 ) + 5, MAXL = 4e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); bool f = false;
	while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = - x;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

std :: vector<int> con[MAXN];

int dp[MAXS];

char str[MAXL];
int lead[MAXN], last[MAXN], coe[MAXN];

int N;

int main()
{
	read( N );
	for( int i = 0 ; i < N ; i ++ )
	{
		scanf( "%s", str );
		int L = strlen( str ), top = 0, scr = 0;
		for( int j = 0 ; j < L ; j ++ )
		{
			bool chk = true;
			if( str[j] == '(' ) top ++;
			if( str[j] == ')' )
			{
				if( top ) top --;
				else chk = false, lead[i] ++, con[i].push_back( scr ), scr = 0;
			}
			if( chk && ! top ) scr ++;
		}
		con[i].push_back( scr );
		last[i] = top, coe[i] = last[i] - lead[i];
	}
	int ans = 0xc0c0c0c0;
	memset( dp, 0xc0, sizeof dp ), dp[0] = 0;
	for( int S = 0 ; S < ( 1 << N ) ; S ++ )
	{
		if( dp[S] == ( int ) 0xc0c0c0c0 ) continue;
		int su = 0;
		for( int i = 0 ; i < N ; i ++ )
			if( S >> i & 1 ) su += coe[i];
		for( int i = 0 ; i < N ; i ++ )
		{
			if( S >> i & 1 ) continue;
			int contri = 0;
			if( su <= lead[i] ) contri = con[i][su] + ( bool ) su;
			ans = MAX( ans, contri + dp[S] );
			if( su >= lead[i] ) dp[S | 1 << i] = MAX( dp[S | 1 << i], contri + dp[S] );
		}
	}
	write( ans ), putchar( '\n' );
	return 0;
}