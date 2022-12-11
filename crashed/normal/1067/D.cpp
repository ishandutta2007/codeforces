// LUOGU_RID: 95171890
#include <cmath>
#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const double eps = 1e-10;
const int MAXN = 1e5 + 5, MAXLOG = 70;

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

struct Matrix {
    double mat[3][3];

    Matrix(): mat{{}} {}
};

struct Vector {
    double x, y;

    Vector(): x( 0 ), y( 0 ) {}
    Vector( double X, double Y ): x( X ), y( Y ) {}

    inline Vector& operator += ( const Vector &q ) { return *this = *this + q; }
    inline Vector& operator -= ( const Vector &q ) { return *this = *this - q; }
    inline Vector operator * ( const double &l ) const { return Vector( x * l, y * l ); }
    inline Vector operator + ( const Vector &q ) const { return Vector( x + q.x, y + q.y ); }
    inline Vector operator - ( const Vector &q ) const { return Vector( x - q.x, y - q.y ); }
};

struct Line {
    Vector p, d;

    Line(): p(), d() {}
    Line( Vector P, Vector D ): p( P ), d( D ) {}
};

Matrix pw[MAXLOG];

double lim[MAXN];
int stk[MAXN], top = 0;
Vector its[MAXN];

Line lin[MAXN];
double A[MAXN], P[MAXN];
int seq[MAXN];

int N, lg2; LL T;

inline int Sgn( const double &x ) {
    if( fabs( x ) < eps ) return 0;
    return x < 0 ? -1 : 1;
}

inline Matrix operator * ( const Matrix &a, const Matrix &b ) {
    Matrix ret;
    rep( i, 0, 2 ) rep( j, 0, 2 )
        if( a.mat[i][j] ) rep( k, 0, 2 )
            ret.mat[i][k] += a.mat[i][j] * b.mat[j][k];
    return ret;
}

inline double Cross( const Vector &u, const Vector &v ) {
    return u.x * v.y - u.y * v.x;
}

inline Vector Intersect( const Line &l1, const Line &l2 ) {
    double n = Cross( l2.d, l2.p - l1.p ) / Cross( l2.d, l1.d );
    return l1.p + l1.d * n;
}

int main() {
    double V;
    Read( N ), Read( T );
    rep( i, 1, N ) {
        double b; seq[i] = i;
        scanf( "%lf %lf %lf", A + i, &b, P + i );
        V = Max( V, b * P[i] ); 
        lin[i] = Line( Vector( 0, P[i] * A[i] ),
                       Vector( 1, P[i] ) );
    }
    std :: sort( seq + 1, seq + 1 + N,
        [] ( const int &a, const int &b ) -> bool {
            Line l1 = lin[a], l2 = lin[b];
            int s = Sgn( Cross( l1.d, l2.d ) );
            return s == 0 ? Cross( l1.d, l2.p - l1.p ) < 0 : s > 0;
        } );
    stk[++ top] = seq[1];
    rep( i, 2, N ) {
        int x = seq[i];
        if( Sgn( Cross( lin[stk[top]].d, lin[x].d ) ) == 0 ) continue;
        while( top > 1 && Cross( lin[x].d, its[top] - lin[x].p ) <= 0 ) top --;
        ++ top, its[top] = Intersect( lin[stk[top - 1]], lin[stk[top] = x] );
    }
    lim[top] = 1e18, lg2 = log2( T );
    rep( i, 2, top ) lim[i - 1] = its[i].x;
    double f = 0; LL cur = 0;
    rep( i, 1, top ) {
        if( lim[i] <= V * cur - f ) continue;
        int q = stk[i];
        pw[0] = Matrix();
        pw[0].mat[1][1] = pw[0].mat[1][2] = pw[0].mat[2][2] = 1;
        pw[0].mat[0][0] = 1 - P[q], pw[0].mat[0][1] = P[q] * V, pw[0].mat[0][2] = P[q] * A[q];
        rep( i, 1, lg2 ) pw[i] = pw[i - 1] * pw[i - 1];

        for( int k = lg2 ; ~ k ; k -- )
            if( cur + ( 1ll << k ) <= T ) {
                double tF = pw[k].mat[0][0] * f + pw[k].mat[0][1] * cur + pw[k].mat[0][2];
                if( V * ( cur + ( 1ll << k ) ) - tF < lim[i] ) cur += 1ll << k, f = tF;
            }
        if( cur < T )
            f = ( 1 - P[q] ) * f + P[q] * V * cur + P[q] * A[q], cur ++;
    }
    printf( "%.10f\n", f );
    return 0;
}