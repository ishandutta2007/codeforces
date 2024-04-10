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
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
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
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
VI e[SIZE];
int a[SIZE];
VI lv[SIZE];
int ma[SIZE],mi[SIZE];
LL dp[SIZE];
int max_lv;
void dfs(int x, int dd) {
    max_lv = max(max_lv, dd);
    ma[dd]=max(ma[dd],a[x]);
    mi[dd]=min(mi[dd],a[x]);
    for(int y: e[x]) {
        lv[dd+1].PB(y);
        dfs(y, dd+1);
    }
}
void solve() {
    dfs(1,0);
    for(int x:lv[1]){
        dp[x]=max(a[x]-mi[1],ma[1]-a[x]);
    }
    REPP(now_lv,1,max_lv){
        map<int,LL>AA[2];
        for(int x:lv[now_lv]){
            int my_ma=0;
            int my_mi=MOD;
            for(int y:e[x]){
                my_ma=max(my_ma,a[y]);
                my_mi=min(my_mi,a[y]);
                dp[y]=max(dp[y],dp[x]+max(ma[now_lv+1]-a[y],a[y]-mi[now_lv+1]));
            }
            auto it=AA[1].lower_bound(my_ma);
            if(it==AA[1].end()||it->S<my_ma+dp[x]){
                auto it2=it;
                while(it2!=AA[1].begin()&&prev(it2)->S<=dp[x]+my_ma){
                    it2--;
                }
                AA[1].erase(it2,it);
                AA[1][my_ma]=dp[x]+my_ma;
            }
            it=AA[0].lower_bound(-my_mi);
            if(it==AA[0].end()||it->S<dp[x]-my_mi){
                auto it2=it;
                while(it2!=AA[0].begin()&&prev(it2)->S<=dp[x]-my_mi){
                    it2--;
                }
                AA[0].erase(it2,it);
                AA[0][-my_mi]=dp[x]-my_mi;
            }
        }
        for(int x: lv[now_lv+1]){
            auto it=AA[1].lower_bound(a[x]);
            if(it!=AA[1].end()){
                dp[x]=max(dp[x],it->S-a[x]);
            }
            it=AA[0].lower_bound(-a[x]);
            if(it!=AA[0].end()){
                dp[x]=max(dp[x],it->S+a[x]);
            }
        }
    }
    LL an=0;
    for(int x:lv[max_lv]){
        an=max(an,dp[x]);
    }
    W(an);
}
void input() {
    int n;
    R(n);
    max_lv=0;
    FOR(i,1,n){
        dp[i]=0;
        lv[i].clear();
        e[i].clear();
        ma[i]=0;
        mi[i]=MOD;
    }
    FOR(i,2,n){
        int x;
        R(x);
        e[x].PB(i);
    }
    FOR(i,2,n)R(a[i]);
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}