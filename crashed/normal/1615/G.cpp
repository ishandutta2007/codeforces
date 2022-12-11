#include <set>
#include <ctime>
#include <cstdio>
#include <vector>
#include <random>
#include <cassert>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 5e5 + 5, MAXC = 605;

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

std :: set<int> rem;
std :: vector<int> grph[MAXN];

bool itrnal[MAXC][MAXC];

int bstMat[MAXN], bst = 0;
int mat[MAXN], vis[MAXN];
int tim = 0;

int deg[MAXN], ntot = 0;
int fr[MAXN], to[MAXN], tot = 0;
int cor[MAXN];

int A[MAXN], rnk[MAXN];
bool alrd[MAXN], app[MAXN];

int N, M;

inline void AddE( const int &u, const int &v ) {
    tot ++;
    deg[fr[tot] = u] ++;
    deg[to[tot] = v] ++;
}

bool Augment( const int &u ) {
    static std :: mt19937 rng( 1919839 );

    if( ! deg[u] ) return false;
    vis[u] = tim;
    std :: shuffle( grph[u].begin(), grph[u].end(), rng );
    for( int i = 0, v, w ; i < deg[u] ; i ++ ) {
        w = mat[v = grph[u][i]];
        if( vis[w] == tim ) continue;
        mat[w] = 0, mat[u] = v, mat[v] = u;
        if( ! w || Augment( w ) ) return true;
        mat[w] = v, mat[v] = w, mat[u] = 0;
    }
    return false;
}

void RandomizedHungary() {
    bst = 0;
    clock_t begTime = clock(), edTime;
    while( true ) {
        edTime = clock();
        if( 1. * ( edTime - begTime ) / CLOCKS_PER_SEC > 2.50 ) break;
        rep( i, 1, ntot ) if( ! mat[i] )
            tim ++, Augment( i );
        int cur = 0;
        rep( i, 1, ntot )
            cur += ( bool ) mat[i];
        if( cur > bst ) {
            bst = cur;
            rep( i, 1, ntot ) 
                bstMat[i] = mat[i];
        }
    }
}

inline bool Chk( const int &e ) {
    if( ! e ) return false;
    return bstMat[fr[e]] == to[e] && bstMat[to[e]] == fr[e];
}

int main() {
    Read( N ); 
    rep( i, 1, N ) Read( A[i] ), app[A[i]] = true;
    rep( i, 1, N - 1 )
        if( A[i] == A[i + 1] )
            alrd[A[i]] = true;
    rep( i, 1, Min( N, 600 ) )
        if( ! alrd[i] && app[i] )
            rnk[i] = ++ ntot;
    for( int i = 1, j ; i <= N ; i ++ )
        if( ! A[i] ) {
            for( j = i ; j <= N && ! A[j] ; j ++ );
            if( ( j - i ) & 1 ) {
                ntot ++;
                if( j <= N && ! alrd[A[j]] ) 
                    AddE( rnk[A[j]], ntot ), cor[j] = tot;
                if( i > 1 && ! alrd[A[i - 1]] && A[i - 1] != A[j] ) 
                    AddE( rnk[A[i - 1]], ntot ), cor[i] = tot;
            } else if( i > 1 && ! alrd[A[i - 1]] && j <= N && ! alrd[A[j]] ) {
                int u = rnk[A[i - 1]], v = rnk[A[j]];
                if( u != v ) {
                    if( ! itrnal[u][v] ) 
                        AddE( u, v ), cor[i] = tot;
                    itrnal[u][v] = itrnal[v][u] = true;
                }
            }
            i = j - 1;
        }
    rep( i, 1, ntot ) 
        grph[i].reserve( deg[i] );
    rep( i, 1, tot )
        grph[fr[i]].push_back( to[i] ),
        grph[to[i]].push_back( fr[i] );
    RandomizedHungary();
    for( int i = 1, j ; i <= N ; i ++ )
        if( ! A[i] ) {
            for( j = i ; j <= N && ! A[j] ; j ++ );
            if( ( j - i ) & 1 ) {
                if( Chk( cor[i] ) ) alrd[A[i] = A[i - 1]] = true;
                if( Chk( cor[j] ) ) alrd[A[j - 1] = A[j]] = true;
            } else if( Chk( cor[i] ) )
                alrd[A[i] = A[i - 1]] = true,
                alrd[A[j - 1] = A[j]] = true; 
            i = j - 1;
        }
    rep( i, 1, N )
        if( ! app[i] )
            rem.insert( i );
    rep( i, 1, N ) if( ! A[i] ) {
        if( A[i + 1] ) A[i] = 1;
        else {
            int val = 1;
            if( ! rem.empty() )
                val = *rem.begin(), rem.erase( rem.begin() );
            A[i] = A[i + 1] = val, i ++;
        }
    }
    rep( i, 1, N ) Write( A[i] ), putchar( " \n"[i == N] );
    return 0;
}