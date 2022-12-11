#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1.5e5 + 5;

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

typedef std :: pair<int, int> Number;
typedef std :: vector<Number> Candi;

Candi tre[MAXN << 2];
int tag[MAXN << 2], siz[MAXN << 2];

int A[MAXN];

int N, M, P, K;

inline Candi operator + ( Candi c, Candi b ) {
	Candi a = c;
	int n = a.size(), m = b.size();
	for( int j = 0 ; j < m ; j ++ ) {
		n = a.size(); bool flg = true;
		for( int i = 0 ; i < n ; i ++ )
			if( b[j].first == a[i].first ) {
				a[i].second += b[j].second;
				flg = false; break;
			}
		if( flg ) {
			if( n < K ) a.push_back( b[j] );
			else {
				if( a[n - 1].second < b[j].second )
					std :: swap( a[n - 1], b[j] );
				for( int i = 0 ; i < n ; i ++ )
					a[i].second -= b[j].second;
			}
		}
		std :: sort( a.begin(), a.end(),
			[] ( const Number &p, const Number &q ) -> bool {
				return p.second == q.second ? p.first < q.first : p.second > q.second;
			} );
		while( ! a.empty() && a.back().second <= 0 ) a.pop_back();
	}
	return a;
}

void Build( const int &x, const int &l, const int &r ) {
	if( l > r ) return ;
	tag[x] = -1, siz[x] = r - l + 1;
	if( l == r ) {
		tre[x].clear();
		tre[x].push_back( { A[l], 1 } );
		return ;
	}
	int mid = ( l + r ) >> 1;
	Build( x << 1, l, mid );
	Build( x << 1 | 1, mid + 1, r );
	tre[x] = tre[x << 1] + tre[x << 1 | 1];
}

inline void Cover( const int &x, const int &nw ) {
	tre[x].clear();
	tre[x].push_back( { nw, siz[x] } );
	tag[x] = nw;
}

inline void Normalize( const int &x ) {
	if( tag[x] == -1 ) return ;
	Cover( x << 1, tag[x] );
	Cover( x << 1 | 1, tag[x] );
	tag[x] = -1;
}

void Update( const int &x, const int &l, const int &r, const int &segL, const int &segR, const int &nw ) {
	if( segL <= l && r <= segR ) { Cover( x, nw ); return ; }
	int mid = ( l + r ) >> 1; Normalize( x );
	if( segL <= mid ) Update( x << 1, l, mid, segL, segR, nw );
	if( mid  < segR ) Update( x << 1 | 1, mid + 1, r, segL, segR, nw );
	tre[x] = tre[x << 1] + tre[x << 1 | 1];
}

Candi Query( const int &x, const int &l, const int &r, const int &segL, const int &segR ) {
	if( segL <= l && r <= segR ) return tre[x];
	int mid = ( l + r ) >> 1; Normalize( x );
	if( segR <= mid ) return Query( x << 1, l, mid, segL, segR );
	if( mid  < segL ) return Query( x << 1 | 1, mid + 1, r, segL, segR );
	return Query( x << 1, l, mid, segL, segR ) + Query( x << 1 | 1, mid + 1, r, segL, segR );
}

int main() {
	read( N ), read( M ), read( P ), K = 100 / P;
	rep( i, 1, N ) read( A[i] );
	Build( 1, 1, N );
	while( M -- ) {
		int opt, l, r;
		read( opt ), read( l ), read( r );
		if( opt == 1 ) {
			int x; read( x );
			Update( 1, 1, N, l, r, x );
		}
		if( opt == 2 ) {
			Candi ans = Query( 1, 1, N, l, r );
			int n = ans.size();
			write( n ), putchar( ' ' );
			rep( i, 0, n - 1 ) write( ans[i].first ), putchar( " \n"[i == n - 1] );
		}
	}
	return 0;
}