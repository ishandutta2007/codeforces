#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353;
const int MAXN = 1e5 + 5, MAXB = 325;

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

int tag[MAXB], su[MAXB], each[MAXB][MAXN];
int lef[MAXB], rig[MAXB];
int bel[MAXN], coe[MAXN], val[MAXN], tot = 0;

int A[MAXN], lst[MAXN][2], dp[MAXN];

int N, K, THRE;

inline int Mul( int x, const int &v ) { return 1ll * x * v % mod; }
inline int Sub( int x, const int &v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, const int &v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int& MulEq( int &x, const int &v ) { return x = 1ll * x * v % mod; }
inline int& SubEq( int &x, const int &v ) { return ( x -= v ) < 0 ? ( x += mod ) : x; }
inline int& AddEq( int &x, const int &v ) { return ( x += v ) >= mod ? ( x -= mod ) : x; }

void Build() {
	THRE = 317;
	for( int i = 1 ; i <= N ; i += THRE ) {
		tot ++, lef[tot] = i, rig[tot] = Min( N, i + THRE - 1 );
		for( int j = lef[tot] ; j <= rig[tot] ; j ++ ) bel[j] = tot;
	}
}

inline void TagAdd( const int &id, int delt ) {
	if( delt > 0 ) {
		for( int i = 1 ; i <= delt ; i ++ ) {
			if( K - tag[id] >= 0 )
				SubEq( su[id], each[id][K - tag[id]] );
			tag[id] ++;
		}
	} 
	if( delt < 0 ) {
		for( int i = 1 ; i <= -delt ; i ++ ) {
			if( K - tag[id] + 1 >= 0 )
				AddEq( su[id], each[id][K - tag[id] + 1] );
			tag[id] --;
		}
	}
}

inline void Normalize( const int &id ) {
	if( ! tag[id] ) return ;
	su[id] = 0;
	rep( i, lef[id], rig[id] ) {
		SubEq( each[id][coe[i]], val[i] );
		if( ( coe[i] += tag[id] ) <= K )
			AddEq( su[id], val[i] );
		AddEq( each[id][coe[i]], val[i] );
	}
	tag[id] = 0;
}

inline void BlockAdd( const int &id, const int &l, const int &r, const int &delt ) {
	Normalize( id );
	rep( i, l, r ) {
		SubEq( each[id][coe[i]], val[i] );
		if( coe[i] <= K ) SubEq( su[id], val[i] );
		AddEq( each[id][coe[i] += delt], val[i] );
		if( coe[i] <= K ) AddEq( su[id], val[i] );
	}
}

inline void GlobalAdd( const int &l, const int &r, const int &delt ) {
	int bL = bel[l], bR = bel[r];
	if( bL == bR ) { BlockAdd( bL, l, r, delt ); return ; }
	if( l ^ lef[bL] ) BlockAdd( bL, l, rig[bL], delt ), bL ++;
	if( r ^ rig[bR] ) BlockAdd( bR, lef[bR], r, delt ), bR --;
	rep( i, bL, bR ) TagAdd( i, delt );
}

inline int Query( const int &r ) {
	int ret = 0, bR = bel[r];
	if( r ^ rig[bR] ) {
		rep( i, lef[bR], r )
			if( coe[i] + tag[bR] <= K )
				AddEq( ret, val[i] );
		bR --;
	}
	rep( i, 1, bR ) AddEq( ret, su[i] );
	return ret;
}

inline void ChangeVal( const int &x, const int &delt ) {
	int id = bel[x];
	AddEq( val[x], delt );
	AddEq( each[id][coe[x]], delt );
	if( coe[x] <= K - tag[id] )
		AddEq( su[id], delt );
}

int main() {
	read( N ), read( K );
	rep( i, 1, N ) read( A[i] );
	Build(), ChangeVal( 1, 1 );
	rep( i, 1, N ) {
		GlobalAdd( 1, i, +1 );
		if( lst[A[i]][1] ) 
			GlobalAdd( 1, lst[A[i]][1], +1 );
		if( lst[A[i]][0] )
			GlobalAdd( 1, lst[A[i]][0], -2 );
		dp[i] = Query( i );
		if( i < N ) ChangeVal( i + 1, dp[i] );
		lst[A[i]][1] = lst[A[i]][0];
		lst[A[i]][0] = i;
	}
	write( dp[N] ), putchar( '\n' );
	return 0;
}