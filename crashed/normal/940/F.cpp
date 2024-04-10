#include <cmath>
#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e5 + 5, MAXV = 2e5 + 5, MAXB = 340;

template<typename _T>
inline void Read( _T &x ) {
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
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
inline _T Min( const _T &a, const _T &b ) {
	return a < b ? a : b;
}

int B, T;

struct Question {
	int l, r, t, lB, rB, id;

	Question(): l( 0 ), r( 0 ), t( 0 ), lB( 0 ), rB( 0 ), id( 0 ) {}
	Question( int L, int R, int T, int I ): 
		l( L ), r( R ), t( T ),
		lB( ( L - 1 ) / B + 1 ), rB( ( R - 1 ) / B + 1 ), id( I ) {}

	inline bool operator < ( const Question &q ) const {
		return lB == q.lB ? ( rB == q.rB ? t < q.t : rB < q.rB ) : lB < q.lB;
	}
};

Question qry[MAXN];

int app[MAXN], bel[MAXN], cnt[MAXV];
int siz[MAXB], lef[MAXB], rig[MAXB];
int bTot;

int chgPos[MAXN], chgVal[MAXN], old[MAXN];
int ans[MAXN];

int val[MAXV], tot;
int A[MAXN];

int N, M, C, Q;

inline void Discrete() {
	rep( i, 1, N ) val[++ tot] = A[i];
	rep( i, 1, C ) val[++ tot] = chgVal[i];
	std :: sort( val + 1, val + 1 + tot );
	tot = std :: unique( val + 1, val + 1 + tot ) - val - 1;
	rep( i, 1, N ) A[i] = std :: lower_bound( val + 1, val + 1 + tot, A[i] ) - val;
	rep( i, 1, C ) chgVal[i] = std :: lower_bound( val + 1, val + 1 + tot, chgVal[i] ) - val;
}

inline void Build( const int &n ) {
	T = sqrt( n );
	for( int i = 1 ; i <= n ; i += T ) {
		bTot ++, lef[bTot] = i, rig[bTot] = Min( n, i + T - 1 );
		for( int j = lef[bTot] ; j <= rig[bTot] ; j ++ ) bel[j] = bTot;
	} 
}

inline void Incre( const int &x ) {
	if( ! ( app[x] ++ ) ) siz[bel[x]] ++;
}

inline void Decre( const int &x ) {
	if( ! ( -- app[x] ) ) siz[bel[x]] --;
}

inline int QueryMex() {
	rep( i, 1, bTot )
		if( siz[i] < rig[i] - lef[i] + 1 ) {
			rep( j, lef[i], rig[i] )
				if( ! app[j] ) return j;
		}
	return -1;
}

inline void Modify( const int &c, const int &v ) {
	if( cnt[c] > 0 ) Decre( cnt[c] );
	if( ( cnt[c] += v ) > 0 ) Incre( cnt[c] );
}

int main () {
	Read( N ), Read( M );
	rep( i, 1, N ) Read( A[i] );
	B = pow( N, 2. / 3 );
	rep( i, 1, M ) {
		int opt, x, y;
		Read( opt ), Read( x ), Read( y );
		if( opt == 1 ) Q ++, qry[Q] = { x, y, C, Q };
		if( opt == 2 ) C ++, chgPos[C] = x, chgVal[C] = y;
	}
	Discrete();
	Build( N + 1 );
	std :: sort( qry + 1, qry + 1 + Q );
	int l = 1, r = 0, t = 0;
	rep( i, 1, Q ) {
		int qL = qry[i].l, qR = qry[i].r, qT = qry[i].t;
		while( r < qR ) Modify( A[++ r], +1 );
		while( r > qR ) Modify( A[r --], -1 );
		while( l < qL ) Modify( A[l ++], -1 );
		while( l > qL ) Modify( A[-- l], +1 );
		while( t < qT ) {
			t ++, old[t] = A[chgPos[t]];
			if( qL <= chgPos[t] && chgPos[t] <= qR )
				Modify( old[t], -1 ), Modify( chgVal[t], +1 );
			A[chgPos[t]] = chgVal[t];
		}
		while( t > qT ) {
			if( qL <= chgPos[t] && chgPos[t] <= qR )
				Modify( chgVal[t], -1 ), Modify( old[t], +1 );
			A[chgPos[t]] = old[t], t --;
		}
		ans[qry[i].id] = QueryMex();
	}
	rep( i, 1, Q ) Write( ans[i] ), putchar( '\n' );
	return 0;
}