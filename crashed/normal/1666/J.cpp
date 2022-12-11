#include <cstdio>

typedef long long LL;

const LL INF = 1e18;
const int MAXN = 205;

template<typename _T>
_T Min( const _T &a, const _T &b ) {
	return a < b ? a : b;
}

template<typename _T>
_T Max( const _T &a, const _T &b ) {
	return a > b ? a : b;
}

int fath[MAXN];

LL su[MAXN][MAXN], dp[MAXN][MAXN];
int C[MAXN][MAXN];

int N;

int Build( const int &l, const int &r ) {
	if( l > r ) return 0;
	int rt;
	for( int k = l ; k <= r ; k ++ )
		if( dp[l][r] == ( dp[l][k - 1] + su[l][k - 1] ) + ( dp[k + 1][r] + su[k + 1][r] ) ) {
			rt = k; break;
		}
	int lch = Build( l, rt - 1 ),
		rch = Build( rt + 1, r );
	if( lch ) fath[lch] = rt;
	if( rch ) fath[rch] = rt;
	return rt;
}

int main() {
	scanf( "%d", &N );
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = 1 ; j <= N ; j ++ )
			scanf( "%d", &C[i][j] );
	for( int i = 1 ; i <= N ; i ++ )
		for( int j = i ; j <= N ; j ++ ) {
			su[i][j] = su[i][j - 1];
			for( int k = i ; k < j ; k ++ )
				su[i][j] -= C[k][j];
			for( int k = 1 ; k < i ; k ++ )
				su[i][j] += C[j][k];
			for( int k = j + 1 ; k <= N ; k ++ )
				su[i][j] += C[j][k];
		}
	for( int i = 0 ; i <= N ; i ++ ) dp[i + 1][i] = 0;
	for( int i = N ; i ; i -- )
		for( int j = i ; j <= N ; j ++ ) {
			dp[i][j] = INF;
			for( int k = i ; k <= j ; k ++ )
				dp[i][j] = Min( dp[i][j], ( dp[i][k - 1] + su[i][k - 1] ) + ( dp[k + 1][j] + su[k + 1][j] ) );
		}
	Build( 1, N );
	for( int i = 1 ; i <= N ; i ++ )
		printf( "%d%c", fath[i], " \n"[i == N] );
	return 0;
}