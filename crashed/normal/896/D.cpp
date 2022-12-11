#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 2e5 + 5, MAXLOG = 50;

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

LL prm[MAXLOG];
int idx[MAXLOG];
int tot = 0;

int N, L, R; LL P;

inline LL Exgcd( const LL &a, const LL &b, LL &x, LL &y ) {
    if( ! b ) return x = 1, y = 0, a;
    LL d = Exgcd( b, a % b, y, x );
    y -= x * ( a / b ); return d;
} 

inline LL Inv( const LL &a, const LL &p ) {
    static LL x, y;
    Exgcd( a, p, x, y );
    return ( x % p + p ) % p;
}

namespace LargeMod {
    LL fac[MAXN], ifac[MAXN];

    LL mod;

    inline LL Qkpow( LL, LL );
    inline LL Inv( const LL &a ) { return Qkpow( a, mod - 2 ); }
    inline LL Mul( LL x, const LL &v ) { return x * v % mod; }
    inline LL Sub( LL x, const LL &v ) { return ( x -= v ) < 0 ? x + mod : x; }
    inline LL Add( LL x, const LL &v ) { return ( x += v ) >= mod ? x - mod : x; }

    inline LL MulEq( LL &x, const LL &v ) { return ( x *= v ) %= mod; }
    inline LL SubEq( LL &x, const LL &v ) { return ( x -= v ) < 0 ? ( x += mod ) : x; }
    inline LL AddEq( LL &x, const LL &v ) { return ( x += v ) >= mod ? ( x -= mod ) : x; }

    inline LL Qkpow( LL base, LL indx ) {
        LL ret = 1;
        while( indx ) {
            if( indx & 1 ) MulEq( ret, base );
            MulEq( base, base ), indx >>= 1;
        }
        return ret;
    }

    inline LL C( int n, int m ) { return n < m ? 0 : Mul( fac[n], Mul( ifac[m], ifac[n - m] ) ); }

    inline LL Solve( const LL &p, const int &e ) {
        // mod=p^e must be a prime and larger than $n
        mod = p;
        fac[0] = 1; rep( i, 1, N ) fac[i] = Mul( fac[i - 1], i );
        ifac[N] = Inv( fac[N] ); per( i, N - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );

        LL ans = 0;
        rep( i, L, N ) {
            LL r = Min( i, R );
            AddEq( ans, Mul( C( N, i ), Sub( C( i, ( i + L + 1 ) / 2 ), C( i, ( i + r ) / 2 + 1 ) ) ) );
        }
        return ans;
    }
}

namespace SmallMod {
    struct RetType {
        LL x, y, z;
        // x * p^y * pref[mod]^z

        RetType(): x( 1 ), y( 0 ), z( 0 ) {}
        RetType( LL X, LL Y, LL Z ): x( X ), y( Y ), z( Z ) {}
    };

    LL pref[MAXN];
    RetType each[MAXN];

    LL pwBas[MAXN], pwPref[MAXN];

    LL mod, lim, bas;
    int tims;

    inline LL Qkpow( LL, LL );
    inline LL Mul( LL x, const LL &v ) { return x * v % mod; }
    inline LL Sub( LL x, const LL &v ) { return ( x -= v ) < 0 ? x + mod : x; }
    inline LL Add( LL x, const LL &v ) { return ( x += v ) >= mod ? x - mod : x; }

    inline LL MulEq( LL &x, const LL &v ) { return ( x *= v ) %= mod; }
    inline LL SubEq( LL &x, const LL &v ) { return ( x -= v ) < 0 ? ( x += mod ) : x; }
    inline LL AddEq( LL &x, const LL &v ) { return ( x += v ) >= mod ? ( x -= mod ) : x; }

    inline LL Qkpow( LL base, LL indx ) {
        LL ret = 1;
        while( indx ) {
            if( indx & 1 ) MulEq( ret, base );
            MulEq( base, base ), indx >>= 1;
        }
        return ret;
    }

    inline LL C( const int &n, const int &m ) {
        if( n < m ) return 0;
        RetType u = each[n], v = each[m], w = each[n - m];
        LL ans = Mul( u.x, Inv( Mul( v.x, w.x ), mod ) );
        MulEq( ans, pwBas[u.y - v.y - w.y] );
        if( u.z > v.z + w.z ) MulEq( ans, pwPref[u.z - v.z - w.z] );

        // #ifdef _DEBUG
        // printf( "C(%d, %d) mod %lld = %lld\n", n, m, mod, ans );
        // #endif
        return ans;
    }

    inline LL Solve( const LL &p, const int &e ) {
        bas = p, tims = e;
        mod = 1; rep( i, 1, e ) mod *= p;

        pref[0] = 1;
        lim = Min( ( LL ) N, mod );
        rep( i, 1, lim ) {
            pref[i] = pref[i - 1];
            if( i % p ) pref[i] = Mul( pref[i], i );
        }
        each[0] = RetType();
        rep( i, 1, N ) {
            each[i] = each[i / p];
            MulEq( each[i].x, pref[i % mod] );
            each[i].y += i / p, each[i].z += i / mod;
        }
        pwBas[0] = 1;
        rep( i, 1, 2 * N ) 
            pwBas[i] = Mul( pwBas[i - 1], bas );
        pwPref[0] = 1, pwPref[1] = lim >= mod ? pref[mod] : 0;
        rep( i, 2, 2 * N )
            pwPref[i] = Mul( pwPref[i - 1], pwPref[1] );

        LL ans = 0;
        rep( i, L, N ) {
            LL r = Min( i, R );
            AddEq( ans, Mul( C( N, i ), Sub( C( i, ( i + L + 1 ) / 2 ), C( i, ( i + r ) / 2 + 1 ) ) ) );
        }
        return ans;
    }
}

inline void Decompose( LL x ) {
    for( int i = 2 ; 1ll * i * i <= x ; i ++ )
        if( ! ( x % i ) ) {
            tot ++, prm[tot] = i, idx[tot] = 0;
            while( ! ( x % i ) ) x /= i, idx[tot] ++;
        }
    if( x > 1 ) tot ++, prm[tot] = x, idx[tot] = 1;
}

int main() {
    Read( N ), Read( P ), Read( L ), Read( R );
    Decompose( P ); LL ans = 0;
    rep( i, 1, tot ) {
        LL cur, pw = 1;
        if( idx[i] == 1 && prm[i] > N )
            cur = LargeMod :: Solve( prm[i], idx[i] );
        else 
            cur = SmallMod :: Solve( prm[i], idx[i] );
        rep( j, 1, idx[i] ) pw *= prm[i];
        ( ans += cur * Inv( P / pw % pw, pw ) % P * ( P / pw ) % P ) %= P;
    }
    Write( ans ), putchar( '\n' );
    return 0;
}