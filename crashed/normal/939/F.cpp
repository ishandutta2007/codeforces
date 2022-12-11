#include <cstdio>
#include <iostream>

//#define CHK

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5, MAXK = 105;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar();int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + s - '0', s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) { putchar( '-' ), x = -x; }
	if( 9 < x ) { write( x / 10 ); }
	putchar( x % 10 + '0' );
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int deq[MAXN], h, t;
int pre[MAXN][2], nxt[MAXN][2];
int l[MAXK], r[MAXK];
int N, K;

int main()
{
	#ifdef CHK
	freopen( "cut.out", "w", stdout );
	#endif
	read( N ), read( K );
	for( int i = 1 ; i <= K ; i ++ ) read( l[i] ), read( r[i] );
	for( int i = 0 ; i <= N ; i ++ ) pre[i][0] = pre[i][1] = INF;
	pre[0][0] = 0;
	int rig;
	for( int i = 1 ; i <= K ; i ++ )
	{
		for( int j = 0 ; j <= N ; j ++ ) nxt[j][0] = INF, nxt[j][1] = pre[j][1];
		for( int j = r[i] - r[i - 1] ; j <= N ; j ++ ) nxt[j][0] = pre[j - ( r[i] - r[i - 1] )][0];
		// 
		h = 1, t = 0, rig = 0;
		for( int j = 0 ; j <= N ; j ++ )
		{
//			for( int k = MAX( l[i], r[i] - j ) ; k <= r[i] ; k ++ )
//				nxt[j][0] = MIN( nxt[j][0], pre[j - r[i] + k][1] + 1 );
			while( rig <= j ) 
			{ while( h <= t && pre[deq[t]][1] >= pre[rig][1] ) t --; deq[++ t] = rig ++; }
			while( h <= t && deq[h] < MAX( 0, j - r[i] + l[i] ) ) h ++;
			if( h <= t ) nxt[j][0] = MIN( nxt[j][0], pre[deq[h]][1] + 1 );
		}
		h = 1, t = 0, rig = 0;
		for( int j = 0 ; j <= N ; j ++ )
		{
//			for( int k = l[i] ; k <= MIN( r[i], j + r[i - 1] ) ; k ++ )
//				nxt[j][1] = MIN( nxt[j][1], pre[j - k + r[i - 1]][0] + 1 );
			while( rig <= j - l[i] + r[i - 1] )
			{ while( h <= t && pre[deq[t]][0] >= pre[rig][0] ) t --; deq[++ t] = rig ++; }
			while( h <= t && deq[h] < MAX( 0, j - r[i] + r[i - 1] ) ) h ++;
			if( h <= t ) nxt[j][1] = MIN( nxt[j][1], pre[deq[h]][0] + 1 );
		}
		//
		h = 1, t = 0, rig = 0;
		for( int j = 0 ; j <= N ; j ++ )
		{
//			for( int k = MAX( l[i] + 1, l[i] - r[i - 1] + r[i] - j ) ; k <= r[i] ; k ++ )
//				nxt[j][0] = MIN( nxt[j][0], pre[j - r[i] + k - l[i] + r[i - 1]][0] + 2 );
			while( rig <= j - l[i] + r[i - 1] )
			{ while( h <= t && pre[deq[t]][0] >= pre[rig][0] ) t --; deq[++ t] = rig ++; }
			while( h <= t && deq[h] < MAX( 0, j - r[i] + r[i - 1] + 1 ) ) h ++;
			if( h <= t ) nxt[j][0] = MIN( nxt[j][0], pre[deq[h]][0] + 2 );
		}
		h = 1, t = 0, rig = 0;
		for( int j = 0 ; j <= N ; j ++ )
		{
//			for( int k = l[i] + 1 ; k <= MIN( r[i], j + l[i] ) ; k ++ )
//				nxt[j][1] = MIN( nxt[j][1], pre[j - k + l[i]][1] + 2 ); 
			while( rig <= j - 1 )
			{ while( h <= t && pre[deq[t]][1] >= pre[rig][1] ) t --; deq[++ t] = rig ++; }
			while( h <= t && deq[h] < MAX( 0, j - r[i] + l[i] ) ) h ++;
			if( h <= t ) nxt[j][1] = MIN( nxt[j][1], pre[deq[h]][1] + 2 );
		}
		// 
		std :: swap( pre, nxt );
		#ifdef CHK
		printf( "--------------------%d-----------------------\n", i );
		for( int j = 0 ; j < 2 ; j ++ )
			for( int i = 1 ; i <= N ; i ++ )
				write( pre[i][j] == INF ? -1 : pre[i][j] ), putchar( i == N ? '\n' : ' ' );
		#endif
	}
	
	int res = pre[N][1];
	if( 2 * N - r[K] <= N ) res = MIN( res, pre[N - ( 2 * N - r[K] )][0] );
	if( res == INF ) { puts( "Hungry" ); return 0; }
	puts( "Full" ), write( res ), putchar( '\n' );
	return 0;
}
/*
15 8
1 1
2 2
4 4
6 6
10 10
14 14
22 22
30 30
*/
/*
511 18
1 1
2 2
4 4
6 6
10 10
14 14
22 22
30 30
46 46
62 62
94 94
126 126
190 190
254 254
382 382
510 510
766 766
1022 1022
*/
/*

*/