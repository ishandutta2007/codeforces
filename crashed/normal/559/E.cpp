// LUOGU_RID: 92443672
#ifdef TIME_MESSURE
#include <ctime>
#endif

#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 1e9;
const int MAXN = 2005, MAXV = 6005;

template<typename _T>
inline void Read( _T &x ) {
	x = 0; char s = getchar(); bool f = false;
	while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
inline void Write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) Write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
inline _T Max( const _T &a, const _T &b ) {
	return a > b ? a : b; 
}

template<typename _T>
inline _T Min( const _T &a, const _T &b ) {
	return a < b ? a : b;
}

typedef std :: pair<int, int> Monitor;

int dp[MAXN][MAXV];

int mxRig[MAXN]; 
int cen[MAXN], lef[MAXN], rig[MAXN];

int val[MAXV], tot = 0;
int pos[MAXN], len[MAXN];
Monitor mon[MAXN];

int N;

inline void Upt( int &x, const int &v ) { x = Max( x, v ); } 

int main() {
	Read( N );
	rep( i, 1, N ) Read( mon[i].first ), Read( mon[i].second );
	std :: sort( mon + 1, mon + 1 + N );
	rep( i, 1, N ) {
		pos[i] = mon[i].first, len[i] = mon[i].second;
		val[++ tot] = pos[i];
		val[++ tot] = pos[i] + len[i];
		val[++ tot] = pos[i] - len[i];
	} 
	std :: sort( val + 1, val + 1 + tot );
	tot = std :: unique( val + 1, val + 1 + tot ) - val - 1;
	rep( i, 1, N ) {
		cen[i] = std :: lower_bound( val + 1, val + 1 + tot, pos[i] ) - val;
		lef[i] = std :: lower_bound( val + 1, val + 1 + tot, pos[i] - len[i] ) - val;
		rig[i] = std :: lower_bound( val + 1, val + 1 + tot, pos[i] + len[i] ) - val;
	}
	rep( j, 1, tot ) dp[1][j] = - INF;
	dp[1][cen[1]] = len[1], dp[1][rig[1]] = len[1];
	rep( i, 2, N ) {
		rep( j, 1, tot ) dp[i][j] = - INF;
		// to the right
		rep( j, 1, tot ) if( dp[i - 1][j] > - INF ) {
			int k = Max( j, rig[i] ), pls = 0;
			if( j <= cen[i] ) pls = len[i];
			else if( j <= rig[i] ) pls = val[rig[i]] - val[j];
			else pls = 0;
			Upt( dp[i][k], dp[i - 1][j] + pls );
		}
		// to the left
		int fir = 0;
		per( j, i - 1, 1 )
			if( pos[j] < pos[i] - len[i] ) {
				fir = j; break;
			}
		mxRig[i] = cen[i];
		per( j, i - 1, fir + 1 )
			mxRig[j] = Max( mxRig[j + 1], rig[j] );
		int r = mxRig[fir + 1];
		if( ! fir )
			Upt( dp[i][r], val[r] - val[lef[i]] );
		else {
			rep( j, 1, tot ) if( dp[fir][j] > - INF ) {
				int k = Max( j, r ), pls = 0;
				if( j <= lef[i] ) pls = val[r] - val[lef[i]];
				else if( j <= r ) pls = val[r] - val[j];
				else pls = 0;
				Upt( dp[i][k], dp[fir][j] + pls );
			}
		}
		rep( t, fir + 1, i - 1 ) 
			if( pos[t] - len[t] < pos[i] - len[i] ) {
				r = mxRig[t + 1];
				rep( j, 1, tot ) if( dp[t][j] > - INF ) {
					int k = Max( j, r ), pls = 0;
					// we can suppose that $t always is oriented left;
					// otherwise the result is worse than another possible one.
					if( j <= r ) pls = val[r] - val[j];
					else pls = 0;
//					pls -= val[cen[t]] - val[lef[i]];
					Upt( dp[i][k], dp[t][j] + pls );
				}
			}
	}
	int ans = - INF;
	rep( j, 1, tot ) ans = Max( ans, dp[N][j] );
	Write( ans ), putchar( '\n' );
	
	#ifdef TIME_MESSURE
	fprintf( stderr, "Run time: %.3fs.\n", 1. * clock() / CLOCKS_PER_SEC );
	#endif
	return 0;
}