#include <cstdio>
#include <cstring>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e5 + 5, MAXS = 1e6 + 5;

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

char buf[MAXS];
int nxt[MAXS];

int seq[MAXS << 1], buc[MAXS << 1];
int ch[MAXS << 1][26], mx[MAXS << 1], fa[MAXS << 1], edp[MAXS << 1];
int rt, ntot, lst;

int N;

inline void Copy( const int &a, const int &b ) {
    mx[a] = mx[b], fa[a] = fa[b];
    memcpy( ch[a], ch[b], sizeof ch[b] );
}

inline void Expand( const char &c ) {
    int x = c - 'a', p = lst, cur = ++ ntot;
    mx[cur] = mx[lst] + 1, lst = cur;
    while( p && ! ch[p][x] ) ch[p][x] = cur, p = fa[p];
    if( ! p ) { fa[cur] = rt; return ; }
    int q = ch[p][x];
    if( mx[q] == mx[p] + 1 ) { fa[cur] = q; return ; }
    int nq = ++ ntot; Copy( nq, q );
    mx[nq] = mx[p] + 1, fa[q] = fa[cur] = nq;
    while( p && ch[p][x] == q ) ch[p][x] = nq, p = fa[p];
}

int main() {
    rt = lst = ntot = 1;
    scanf( "%s", buf + 1 );
    for( int i = 1 ; buf[i] ; i ++ )
        Expand( buf[i] ), edp[lst] ++;
    rep( i, 1, ntot ) buc[mx[i]] ++;
    rep( i, 1, ntot ) buc[i] += buc[i - 1];
    per( i, ntot, 1 ) seq[buc[mx[i]] --] = i;
    per( i, ntot, 2 ) edp[fa[seq[i]]] += edp[seq[i]];
    for( Read( N ) ; N -- ; ) {
        scanf( "%s", buf + 1 );
        int L = strlen( buf + 1 );
        
        nxt[1] = 0;
        for( int i = 2, j = 0 ; i <= L ; i ++ ) {
            while( j && buf[j + 1] != buf[i] ) j = nxt[j];
            if( buf[j + 1] == buf[i] ) j ++;
            nxt[i] = j;
        }
        int lim = ( 2 * nxt[L] >= L ) && ( L % ( L - nxt[L] ) == 0 ) ? L - nxt[L] : L;
        int p = rt, len = 0, res = 0;
        rep( i, 1, L ) {
            int x = buf[i] - 'a';
            while( p && ! ch[p][x] ) len = mx[p = fa[p]];
            if( ch[p][x] ) len ++, p = ch[p][x];
        }
        rep( i, 1, lim ) {
            if( len == L ) res += edp[p];

            int x = buf[i] - 'a';
            while( p && ! ch[p][x] ) len = mx[p = fa[p]];
            if( ch[p][x] ) len ++, p = ch[p][x];
            if( len > L )
                if( ( -- len ) == mx[fa[p]] )
                    p = fa[p];
        }
        Write( res ), putchar( '\n' );
    }
    return 0;
}