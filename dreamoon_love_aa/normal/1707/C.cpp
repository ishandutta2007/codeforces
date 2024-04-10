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
#define UnionFindSIZE 1234567
struct Union_Find {
    int d[UnionFindSIZE], num[UnionFindSIZE];
    void init(int n){
        for(int i = 0; i < n; i++) {
            d[i] = i;
            num[i] = 1;
        }
    }
    int find(int x){
        int y = x, z = x;
        while(y != d[y]) { y = d[y]; }
        while(x != y) {
            x = d[x];
            d[z] = y;
            z = x;
        }
        return y;
    }
    bool is_root(int x) { return d[x] == x; }
    bool uu(int x,int y) {
        x = find(x);
        y = find(y);
        if(x == y) { return 0; }
        if(num[x] > num[y]) { swap(x,y); }
        num[y] += num[x];
        d[x] = y;
        return 1;
    }
}U;
// 0-based
#define MAX_LV 18
const int SIZE = 1 << MAX_LV;
int jump[MAX_LV+1][SIZE], lv[SIZE];
VPII e[SIZE];
bool in_MST[SIZE];
void __init(int x,int lt) {
    jump[0][x] = lt;
    for(auto &[y,_eid]: e[x]) {
        if(y != lt) {
            lv[y] = lv[x] + 1;
            __init(y, x);
        }
    }
}
int adv(int x,int v){
    for(int i = 0; v >> i; i++) {
        if((v >> i) & 1) { 
            x = jump[i][x];
        }
    }
    return x;
}
int lca(int x, int y) {
    if(lv[x] > lv[y]) { x = adv(x,lv[x] - lv[y]); }
    else { y = adv(y, lv[y] - lv[x]); }
    if(x == y) { return x; }
    for(int i = MAX_LV; i >= 0; i--) {
        if(jump[i][x] != jump[i][y]) {
            x = jump[i][x];
            y = jump[i][y];
        }
    }
    return jump[0][x];
}
int dis(int x, int y) {
    int z = lca(x, y);
    return lv[x] + lv[y] - lv[z] * 2;
}
void build(int root,int N) {
    __init(root, root);
    for(int i = 1; i <= MAX_LV; i++) {
        for(int x = 1; x <= N; x++) {
            jump[i][x] = jump[i - 1][jump[i - 1][x]];
        }
    }
}
int u[SIZE],v[SIZE],n,m;
int _id;
int ll[SIZE],rr[SIZE],fr[SIZE];
void dfs(int x, int lt){
    ll[x]=++_id;
    fr[_id]=x;
    for(auto &[y,eid]: e[x]){
        if(y==lt)continue;
        if(!in_MST[eid])continue;
        dfs(y,x);
    }
    rr[x]=_id;
}
int dp[SIZE];
void solve() {
    U.init(n+1);
    REP(i,m){
        if(U.uu(u[i],v[i])){
            e[u[i]].PB({v[i],i});
            e[v[i]].PB({u[i],i});
            in_MST[i]=1;
        }
    }
    dfs(1,1);
    build(1,n);
    REP(i,m){
        if(!in_MST[i]){
            int z=lca(u[i],v[i]);
            if(z!=u[i]&&z!=v[i]){
                dp[1]++;
                dp[ll[u[i]]]--;
                dp[rr[u[i]]+1]++;
                dp[ll[v[i]]]--;
                dp[rr[v[i]]+1]++;
            }else{
                if(lv[u[i]]>lv[v[i]]){
                    swap(u[i],v[i]);
                }
                int ss=adv(v[i],lv[v[i]]-lv[u[i]]-1);
                dp[ll[ss]]++;
                dp[rr[ss]+1]--;
                dp[ll[v[i]]]--;
                dp[rr[v[i]]+1]++;
            }
        }
    }
    string ans(n,'0');
    int now=0;
    FOR(i,1,n){
        now+=dp[i];
        if(!now){
            ans[fr[i]-1]='1';
        }
    }
    W(ans);
}
void input() {
    R(n,m);
    REP(i,m)R(u[i],v[i]);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}