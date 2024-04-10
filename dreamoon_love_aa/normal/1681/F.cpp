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
const int SIZE = 1<<19;
map<int,PII>cols[SIZE];
LL one_sum[SIZE];
LL zero_add[SIZE];
int num[SIZE];
VPII e[SIZE];
int n;
LL an;
void merge_to(map<int,PII>&c1,int num_1,map<int,PII>&c2, int num_2){
    if(SZ(c1)>SZ(c2)){
        c1.swap(c2);
        swap(num_1,num_2);
    }
    for(auto &[x,pp]: c1){
        auto ret=c2.insert({x,pp});
        if(!ret.S){
            auto iter=ret.F;
            an-=iter->S.F*(LL)(pp.F+pp.S)+pp.F*(LL)(iter->S.F+iter->S.S);
            iter->S={iter->S.F+pp.F,iter->S.S+pp.S};
        }
    }
}
void dfs(int x, int lt){
    num[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        int c=e[x][i].S;
        if(y==lt)continue;
        dfs(y,x);
        auto it=cols[y].find(c);
        if(it==end(cols[y])){
            cols[y][c]=MP(num[y],0);
            one_sum[y]+=num[y];
        }else{
            one_sum[y]+=(num[y]-it->S.F-it->S.S)-it->S.F;
            it->S={(num[y]-it->S.F-it->S.S),it->S.F+it->S.S};
        }
        an+=(LL)one_sum[y]*num[x]+(LL)one_sum[x]*num[y];
        merge_to(cols[y],num[y],cols[x],num[x]-1);
        one_sum[x]+=one_sum[y];
        num[x]+=num[y];
    }
}
void solve() {
    dfs(1,1);
    W(an);
}
void input() {
    R(n);
    REPP(i,1,n){
        int u,v,x;
        R(u,v,x);
        e[u].PB({v,x});
        e[v].PB({u,x});
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}