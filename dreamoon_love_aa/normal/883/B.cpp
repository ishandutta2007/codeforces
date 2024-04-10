// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REP1(i, a, b) for (int i = (a); i <= int(b); i++)
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

namespace { namespace shik {

template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%" SCNd64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }

template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%" PRId64, x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }

#ifdef SHIK
#include "dump.hpp"
#else
#define dump(...)
#endif

template<class T, class F = less<T>> void sort_uniq(vector<T> &v, F f = F()) { sort(begin(v), end(v), f); v.resize(unique(begin(v), end(v)) - begin(v)); }
template<class T> inline T bit(T x, int i) { return (x >> i) & 1; }
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

// }}}

const int N=4e5+10;
int n,m,k,r[N],deg[N],dp[N],dq[N],sol[N];
VI e[N],re[N];

bool cmp( int a, int b ) {
    return tie(dp[a],dq[a])<tie(dp[b],dq[b]);
}

bool solve() {
    REP1(i,1,k-1) e[n+i+1].PB(n+i);
    REP1(i,1,n) if ( r[i] ) {
        if ( r[i]>1 ) e[i].PB(n+r[i]-1);
        if ( r[i]<k ) e[n+r[i]+1].PB(i);
    }
    REP1(i,1,n+k) for ( int j:e[i] ) re[j].PB(i);
    REP1(i,1,n+k) deg[i]=SZ(e[i]);
    vector<int> tp;
    REP1(i,1,n+k) if ( !deg[i] ) tp.PB(i);
    REP(i,SZ(tp)) {
        int p=tp[i];
        for ( int j:re[p] ) if ( --deg[j]==0 ) tp.PB(j);
    }
    if ( SZ(tp)!=n+k ) return 0;

    for ( int i:tp ) {
        int mx=0;
        for ( int j:e[i] ) chkmax(mx,dp[j]);
        dp[i]=mx+1;
    }
    if ( *max_element(dp+1,dp+n+1)>k ) return 0;

    auto rtp=tp;
    reverse(ALL(rtp));
    for ( int i:rtp ) {
        int mi=k+1;
        for ( int j:re[i] ) chkmin(mi,dq[j]);
        dq[i]=mi-1;
    }
    REP1(i,1,n) if ( r[i] ) {
        if ( r[i]!=dp[i] || r[i]!=dq[i] ) return 0;
    }
    // REP1(i,1,n) if ( r[i] ) assert(r[i]==dp[i] && r[i]==dq[i]);
    // REP1(i,1,n) dump(i,dp[i],dq[i]);

    auto ord=rtp;
    sort(ALL(ord),cmp);
    MinHeap<PII> h;
    for ( int i=1,jj=0; i<=k; i++ ) {
        while ( jj<n+k && dp[ord[jj]]<=i ) {
            h.push({dq[ord[jj]],jj});
            jj++;
        }
        // dump(i,jj);
        bool ok=0;
        while ( !h.empty() && h.top().first==i ) {
            int j=ord[h.top().second];
            h.pop();
            sol[j]=i;
            // dump(j);
            if ( j<=n ) ok=1;
        }
        if ( !ok ) {
            if ( h.empty() ) return 0;
            int j=ord[h.top().second];
            h.pop();
            sol[j]=i;
            // dump(j);
        }
    }
    // dump(VI(sol+1,sol+n+1));
    REP1(i,1,n) for ( int j:e[i] ) assert(sol[i]>sol[j]);
    W(VI(sol+1,sol+n+1));
    return 1;
}

void main() {
    R(n,m,k);
    REP1(i,1,n) R(r[i]);
    REP(i,m) {
        int a,b;
        R(a,b);
        e[a].PB(b);
        if ( r[a] && r[b] && r[a]<=r[b] ) {
            W(-1);
            return;
        }
    }
    if ( !solve() ) {
        W(-1);
        // assert(0);
    }
}

// {{{ main
}}
int main() { shik::main(); return 0; }
// }}}