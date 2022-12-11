#include <cstdio>
#include <cstring>
#include <utility>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;

template<typename _T>
void read( _T &x ) {
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
void write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
_T Min( const _T &a, const _T &b ) {
	return a < b ? a : b;
}

std :: pair<int, int> dp[MAXN];
std :: pair<int, int> chn[MAXN];

int dif[MAXN], slk[MAXN];
int ch[MAXN][26], len[MAXN], fa[MAXN];
int lst, ntot;

char S[MAXN], T[MAXN], str[MAXN];

int N, L;

void Print( const int &r ) {
	if( ! r ) return ;
	Print( dp[r].second );
	if( dp[r].second < r - 2 ) {
		write( ( dp[r].second + 2 ) >> 1 ), putchar( ' ' );
		write( r >> 1 ), putchar( '\n' );
	}
}

int main() {
	scanf( "%s%s", S + 1, T + 1 );
	L = strlen( S + 1 );
	rep( i, 1, L ) {
		str[++ N] = S[i];
		str[++ N] = T[i];
	}
	len[fa[0] = ++ ntot] = -1;
	rep( i, 1, N ) {
		int x = str[i] - 'a';
		while( str[i - len[lst] - 1] ^ str[i] ) lst = fa[lst];
		if( ! ch[lst][x] ) {
			int cur = ++ ntot, p = fa[lst];
			while( str[i - len[p] - 1] ^ str[i] ) p = fa[p];
			fa[cur] = ch[p][x], len[cur] = len[lst] + 2, ch[lst][x] = cur;

			dif[cur] = len[cur] - len[fa[cur]];
			slk[cur] = fa[cur] > 1 && dif[fa[cur]] == dif[cur] ? slk[fa[cur]] : fa[cur];
		}
		lst = ch[lst][x], dp[i] = { INF, INF };
		for( int p = lst ; p ; p = slk[p] ) {
			int dt = len[slk[p]] + dif[p];
			chn[p] = { dp[i - dt].first + 1, i - dt };
			if( fa[p] != slk[p] ) chn[p] = Min( chn[p], chn[fa[p]] );
			dp[i] = Min( dp[i], chn[p] );
		}
		if( i & 1 ) dp[i] = { INF, INF };
		else {
			if( str[i] == str[i - 1] )
				dp[i] = Min( dp[i], { dp[i - 2].first, i - 2 } );
		}
	}
	if( dp[N].first >= INF )
		return puts( "-1" ), 0;
	write( dp[N].first ), putchar( '\n' );
	Print( N );
	return 0;
}