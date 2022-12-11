#include <cstdio>
#include <cstring>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod1 = 998244853, mod2 = 1e9 + 9;
const int MAXN = 1e6 + 5, MAXLOG = 21;

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
inline _T Min( const _T &a, const _T &b ) {
    return a < b ? a : b;
}

struct MinPrefix {
    int s, m;

    MinPrefix(): s( 0 ), m( 0 ) {}
    MinPrefix( int S ): s( S ), m( Min( S, 0 ) ) {}
    MinPrefix( int S, int M ): s( S ), m( Min( M, 0 ) ) {}
};

struct HashValue {
    int x, y;

    HashValue(): x( 0 ), y( 0 ) {}
    HashValue( int X ): x( X % mod1 ), y( X % mod2 ) {}
    HashValue( int X, int Y ): x( X % mod1 ), y( Y % mod2 ) {}
};

struct String {
    int x, p, y;

    String(): x( 0 ), p( 0 ), y( 0 ) {}
    String( int X, int P, int Y ): x( X ), p( P ), y( Y ) {}

    inline int GetChar( const int& ) const; 
    inline HashValue GetHash( const int& ) const;
};

const HashValue BASE( 5, 11 );

HashValue pref[MAXN], pw[MAXN];
HashValue pref0[MAXN], pref1[MAXN];

MinPrefix mnPre[MAXN], mnSuf[MAXN];

char str[MAXN];
int seq[MAXN];

int N;

inline MinPrefix operator + ( const MinPrefix &a, const MinPrefix &b ) {
    return MinPrefix( a.s + b.s, Min( a.m, b.m + a.s ) );
}

inline HashValue operator + ( const HashValue &a, const HashValue &b ) {
    return HashValue( ( a.x + b.x ) % mod1, ( a.y + b.y ) % mod2 );
}

inline HashValue operator - ( const HashValue &a, const HashValue &b ) {
    return HashValue( ( a.x + mod1 - b.x ) % mod1, ( a.y + mod2 - b.y ) % mod2 );
}

inline HashValue operator * ( const HashValue &a, const HashValue &b ) {
    return HashValue( 1ll * a.x * b.x % mod1, 1ll * a.y * b.y % mod2 );
}

inline bool operator == ( const HashValue &a, const HashValue &b ) {
    return a.x == b.x && a.y == b.y;
}

inline HashValue GetHash( const int &l, const int &r ) {
    return pref[r] - pref[l - 1] * pw[r - l + 1];
}

inline int String :: GetChar( const int &l ) const {
    if( l <= x ) return 0;
    if( l > x + N ) return 1;
    return l <= x + N - p ? seq[p + l - x] : seq[l - x - N + p];
}

inline HashValue String :: GetHash( const int &l ) const {
    HashValue ret;
    if( l <= x ) return pref0[l];
    ret = pref0[x];
    if( l <= x + N - p ) 
        return ret * pw[l - x] + :: GetHash( p + 1, p + l - x );
    ret = ret * pw[N - p] + :: GetHash( p + 1, N );
    if( l <= x + N )
        return ret * pw[l - x - N + p] + :: GetHash( 1, l - x - N + p );
    ret = ret * pw[p] + :: GetHash( 1, p );
    ret = ret * pw[l - x - N] + pref1[l - x - N];
    return ret;
}

inline bool operator < ( const String &a, const String &b ) {
    if( a.x + a.y < b.x + b.y ) return true;
    if( a.x + a.y > b.x + b.y ) return false;
    int l = 0, r = a.x + a.y + N, mid;
    while( l < r ) {
        mid = ( l + r + 1 ) >> 1;
        if( a.GetHash( mid ) == b.GetHash( mid ) ) l = mid;
        else r = mid - 1;
    }
    return a.GetChar( l + 1 ) < b.GetChar( l + 1 );
}

inline String Acquire( const int &p ) {
    MinPrefix tmp = mnSuf[p + 1] + mnPre[p];
    return String( - tmp.m, p, tmp.s - tmp.m );
}

inline void Print( const String &s ) {
    rep( i, 1, s.x ) putchar( '(' );
    rep( i, s.p + 1, N ) putchar( str[i] );
    rep( i, 1, s.p ) putchar( str[i] );
    rep( i, 1, s.y ) putchar( ')' );
}

int main() {
    scanf( "%s", str + 1 );
    N = strlen( str + 1 );
    rep( i, 1, N ) seq[i] = str[i] == ')';
    pw[0] = HashValue( 1 );
    rep( i, 1, N ) {
        pw[i] = pw[i - 1] * BASE;
        pref0[i] = pref0[i - 1] * BASE + HashValue( 0 );
        pref1[i] = pref1[i - 1] * BASE + HashValue( 1 );
        pref[i] = pref[i - 1] * BASE + HashValue( seq[i] );
    }
    rep( i, 1, N ) mnPre[i] = mnPre[i - 1] + MinPrefix( seq[i] ? -1 : 1 );
    per( i, N, 1 ) mnSuf[i] = MinPrefix( seq[i] ? -1 : 1 ) + mnSuf[i + 1];
    String ans = Acquire( 0 ), tmp;
    rep( i, 1, N - 1 ) 
        if( ( tmp = Acquire( i ) ) < ans )
            ans = tmp;
    Print( ans ), puts( "" );
    return 0;
}