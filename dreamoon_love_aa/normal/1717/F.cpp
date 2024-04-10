/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<iomanip>
#include<limits.h>
#include<assert.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; cin >> ___T; for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
template<class T,class U> void _R(pair<T,U> &x) {cin >> x.F >> x.S;}
void R() {}
template<class T, class... U> void R(T &head, U &... tail) {_R(head); R(tail...);}
template<class T> void _W(const T &x) {cout << x;}
void _W(const double &x) {cout << fixed << setprecision(16) << x;}
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); cout << ' '; _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) cout << ' '; }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); cout << (sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {cout << "[DEBUG] "; W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
#define FN 500010
#define FM 2000010
#define INF 1000000000000000
struct E {
    int k;
    long long c;
    E() {}
    E( int _k, long long _c ) : k(_k), c(_c) {}
} es[FM];

struct Flow {
    int n, m, dis[FN];
    int qq[FN], qr, ql;
    int ptr[FN];
    vector<int> e[FN];
    void init( int _n ) {
        n = _n; m=0;
    }
    void add_edge(int a, int b, long long c) {
        e[a].push_back(m); es[m]=E(b, c); m++;
        e[b].push_back(m); es[m]=E(a, 0); m++;
    }
    bool BFS() {
        memset(dis, -1, n * sizeof(int));
        ql = qr = 0;
        qq[qr++] = 0;
        dis[0] = 0;
        while ( ql != qr && dis[n-1] == -1 ) {
            int p = qq[ql++];
            for(int i = 0; i < e[p].size(); i++){
                int it = e[p][i];
                E ee = es[it];
                if ( ee.c == 0 || dis[ee.k] != -1 ) continue;
                dis[ee.k] = dis[p] + 1;
                qq[qr++] = ee.k;
            }
        }
        return dis[n-1] != -1;
    }
    long long go(int p, long long c) {
        if (p == n - 1) { return c; }
        long long ret = 0, tmp;
        for(int &i = ptr[p]; i < SZ(e[p]); i++) {
            int it = e[p][i];
            E &ee = es[it];
            if (ee.c == 0 || dis[p] + 1 != dis[ee.k]) { continue; }
            tmp = go(ee.k, min(c - ret, (long long)ee.c));
            ret += tmp; ee.c -= tmp; es[it ^ 1].c += tmp;
            if (ret == c) { break; }
        }
        if (ret == 0) { dis[p] = -1; }
        return ret;
    }
    long long maxflow() {
        long long ret = 0;
        while (BFS()) {
            memset(ptr,0,n * sizeof(int));
            ret += go(0, 1LL << 60);
        }
        return ret;
    }
} flow;
int n,m;
int s[SIZE],a[SIZE];
int u[SIZE],v[SIZE];
int deg[SIZE];
void solve() {
    flow.init(3+n+m);
    FOR(i,1,m){
        flow.add_edge(0,i,1);
        flow.add_edge(i,u[i]+m,1);
        flow.add_edge(i,v[i]+m,1);
    }
    int sum=0;
    FOR(i,1,n){
        if(s[i]){
            if(deg[i]<a[i]||-deg[i]>a[i]||(deg[i]-a[i])%2){
                W("NO");
                return;
            }
            sum+=(a[i]+deg[i])/2;
            flow.add_edge(m+i,n+m+2,(a[i]+deg[i])/2);
        }else{
            flow.add_edge(m+i,n+m+1,deg[i]);
        }
    }
    if(sum>m){
        W("NO");
        return;
    }
    flow.add_edge(n+m+1,n+m+2,m-sum);
    if(flow.maxflow()!=m){
        W("NO");
        return;
    }
    W("YES");
    FOR(i,1,m){
        if(!es[6*i-2].c){
            W(u[i],v[i]);
        }else{
            W(v[i],u[i]);
        }
    }
}
void input() {
    R(n,m);
    FOR(i,1,n)R(s[i]);
    FOR(i,1,n)R(a[i]);
    FOR(i,1,m){
        R(u[i],v[i]);
        deg[u[i]]++;
        deg[v[i]]++;
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}