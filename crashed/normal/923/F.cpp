#include <set>
#include <cstdio>
#include <utility>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 10005;

template<typename _T>
void read( _T &x ) {
    x = 0; char s = getchar(); bool f = false;
    while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
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
_T MAX( const _T a, const _T b ) {
    return a > b ? a : b;
}

struct MyGraph { 
    std :: set<int> nei[MAXN], exi;
    std :: set<int> leaf[MAXN], nearLeaf;
    std :: set<std :: pair<int, int> > mxDeg;

    int deg[MAXN];

    int n;

    MyGraph(): deg{}, n( 0 ) {}

    void AddE( const int from, const int to ) {
        nei[from].insert( to ), deg[from] ++;
        nei[to].insert( from ), deg[to] ++;
    }

    void Init( const int N ) {
        exi.clear(), n = N;
        rep( i, 1, n ) {
            exi.insert( i );
            nei[i].clear(), leaf[i].clear();
        }
    }

    void Prepare() {
        mxDeg.clear(), nearLeaf.clear();
        rep( i, 1, n ) {
            mxDeg.insert( { deg[i], i } );
            for( const int& v : nei[i] )
                if( deg[v] == 1 ) leaf[i].insert( v );
            if( ! leaf[i].empty() ) nearLeaf.insert( i );
        }
    }

    void Remove( const int x ) {
        if( exi.find( x ) == exi.end() ) return ;
        exi.erase( x );
        for( const int& v : nei[x] ) {
            mxDeg.erase( { deg[v], v } );
            nei[v].erase( x ), deg[v] --;
            mxDeg.insert( { deg[v], v } );
            if( deg[v] == 1 )
            // let v be a new leaf
                for( const int& w : nei[v] ) {
                    // can visit x no more
                    leaf[w].insert( v );
                    if( leaf[w].size() == 1u )
                        nearLeaf.insert( w );
                }
        }
        if( deg[x] == 1 ) {
            // remove x that used to be a leaf
            int v = * nei[x].begin();
            leaf[v].erase( x );
            if( leaf[v].empty() )
                nearLeaf.erase( v );
        }
    }    

    int Size() const { return exi.size(); }

    inline int GetStarness() const {
        return Size() - mxDeg.rbegin() -> first - 1;
    }

    std :: pair<int, int> GetPair() const {
        int cen = mxDeg.rbegin() -> second;
        if( GetStarness() == 2 ) 
            return std :: make_pair( * leaf[cen].begin(), 
                * leaf[* nearLeaf.begin() == cen ? * nearLeaf.rbegin() : * nearLeaf.begin()].begin() );
        return std :: make_pair( * leaf[* nearLeaf.begin()].begin(), 
                                 * leaf[* nearLeaf.rbegin()].begin() );
    }
};

MyGraph T1, T2;

bool g1[10][10], g2[10][10];
int q1[10], q2[10], tmp[10];
int ref1[MAXN], ref2[MAXN];

int ans[MAXN];

int N;

void Construct() {
    if( T1.Size() <= 5 ) {
        int t1 = 0, t2 = 0, n = T1.Size();
        rep( i, 1, n ) rep( j, 1, n ) g1[i][j] = g2[i][j] = false;
        for( const int& u : T1.exi ) q1[ref1[u] = ++ t1] = u;
        for( const int& u : T2.exi ) q2[ref2[u] = ++ t2] = u;
        for( const int& u : T1.exi )
            for( const int& v : T1.nei[u] )
                g1[ref1[u]][ref1[v]] = true;
        for( const int& u : T2.exi )
            for( const int &v : T2.nei[u] )
                g2[ref2[u]][ref2[v]] = true;
        rep( i, 1, n ) tmp[i] = i;
        do {
            bool flg = true;
            for( int i = 1 ; i <= n && flg ; i ++ )
                for( int j = 1 ; j <= n && flg ; j ++ )
                    if( ( g1[i][j] || g1[j][i] ) && ( g2[tmp[i]][tmp[j]] || g2[tmp[j]][tmp[i]] ) )
                        flg = false;
            if( flg ) break;
        } while( std :: next_permutation( tmp + 1, tmp + 1 + n ) );
        rep( i, 1, n ) ans[q1[i]] = q2[tmp[i]];
        return ;
    }
    bool swp = false;
    if( T2.GetStarness() == 1 )
        std :: swap( T1, T2 ), swp = true;
    if( T1.GetStarness() == 1 ) {
        // | /
        // u - w - v
        int u = T1.mxDeg.rbegin() -> second;
        int v = * T1.leaf[* T1.nearLeaf.begin() == u ? 
                            * T1.nearLeaf.rbegin() : * T1.nearLeaf.begin()].begin();
        int w = * T1.nei[v].begin();
        int u_ = * T2.leaf[* T2.nearLeaf.begin()].begin();
        int v_ = * T2.nei[u_].begin(), w_;
        for( const int& x : T2.exi )
            if( T2.nei[v_].find( x ) == T2.nei[v_].end() && v_ ^ x )
            { w_ = x; break; }
        if( ! swp ) ans[u] = u_, ans[v] = v_, ans[w] = w_;
        else ans[u_] = u, ans[v_] = v, ans[w_] = w;
        for( std :: set<int> :: const_iterator
               p1 = T1.exi.begin(), p2 = T2.exi.begin() ;
             p1 != T1.exi.end() && p2 != T2.exi.end() ; 
             p1 ++, p2 ++ ) {
            while( * p1 == u || * p1 == v || * p1 == w ) p1 ++;
            while( * p2 == u_ || * p2 == v_ || * p2 == w_ ) p2 ++;
            if( ! swp ) ans[* p1] = * p2;
            else ans[* p2] = * p1;
        }
        if( swp ) std :: swap( T1, T2 );
    } else {
        std :: pair<int, int>
            p1 = T1.GetPair(),
            p2 = T2.GetPair();
        T1.Remove( p1.first ), T1.Remove( p1.second );
        T2.Remove( p2.first ), T2.Remove( p2.second );
        Construct();
        int npu = * T1.nei[p1.first].begin(),
            npv = * T1.nei[p1.second].begin(),
            npu_ = * T2.nei[p2.first].begin(),
            npv_ = * T2.nei[p2.second].begin();
        if( ans[npu] == npu_ || ans[npv] == npv_ )
            ans[p1.first] = p2.second, ans[p1.second] = p2.first;
        else ans[p1.first] = p2.first, ans[p1.second] = p2.second;
    }
}

int main() {
    read( N );
    T1.Init( N ), T2.Init( N );
    rep( i, 1, N - 1 ) {
        int u, v;
        read( u ), read( v );
        T1.AddE( u, v );
    }
    rep( i, 1, N - 1 ) {
        int u, v;
        read( u ), read( v );
        T2.AddE( u - N, v - N );
    }
    T1.Prepare(), T2.Prepare();
    if( T1.GetStarness() == 0 || T2.GetStarness() == 0 )
        return puts( "No" ), 0;
    puts( "Yes" );
    Construct();
    rep( i, 1, N )
        write( ans[i] + N ), putchar( i == N ? '\n' : ' ' );
    return 0;
}