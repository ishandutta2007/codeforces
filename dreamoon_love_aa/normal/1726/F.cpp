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
void ins(map<int, int> &AA, int l, int r,int id) {
    auto it_l = AA.find(l);
    auto it_r = AA.find(r);
    for(auto it = it_l; it != it_r; it++);
    AA.erase(it_l, it_r);
    AA[l] = id;
}
void split(map<int, int> &AA, int pos) {
    auto it = AA.lower_bound(pos);
    if(it->first != pos) {
        int tmp = prev(it)->second;
        AA[pos] = tmp;
    }
}
int n,t;
int g[SIZE],c[SIZE],d[SIZE];
LL dsum[SIZE];
LL dp[SIZE];
map<int,int>AA;
void add_red(int id){
    LL ll=g[id]-c[id];
    ll-=dsum[id-1];
    ll%=t;
    if(ll<0)ll+=t;
    LL rr=ll+(t-g[id]);
    if(id==4)DEBUG("sddd",ll,rr);
    if(rr<=t){
        split(AA,ll);
        split(AA,rr);
        ins(AA,ll,rr,id);
    }else{
        split(AA,ll);
        split(AA,rr-t);
        ins(AA,ll,t,id);
        ins(AA,0,rr-t,id);
    }
}
LL calc(int id, int block_id){
    LL need=dsum[block_id-1]-dsum[id-1];
    LL arrive_t=(c[block_id]-c[id]+need)%t;
    if(arrive_t<0)arrive_t+=t;
    DEBUG("in",need,arrive_t);
    return need+(t-arrive_t)%t;
}
void solve() {
    AA[0]=0;
    AA[t]=0;
    FOR(i,1,n-1){
        dsum[i]=dsum[i-1]+d[i];
    }
    dp[n]=0;
    add_red(n);
    for(int i=n-1;i>0;i--){
        LL me=(-dsum[i-1]-c[i])%t;
        if(me<0)me+=t;
        auto it=AA.lower_bound(me);
        int block_id=0;
        if(it->F==me){
            block_id=it->S;
        }else{
            block_id=prev(it)->S;
        }
        DEBUG("block",i,block_id);
        if(!block_id){
            dp[i]=dsum[n-1]-dsum[i-1];
        }else{
            DEBUG("calc",i,block_id);
            dp[i]=dp[block_id]+calc(i,block_id);
        }
        add_red(i);
        DEBUG("dp",i,dp[i]);
    }
    LL an=1e18;
    DEBUG("-----");
    for(auto it=AA.begin();it->F!=t;it++){
        if(!it->S){
            W(dsum[n-1]);
            return;
        }
        int id=it->S;
        LL sp_t=next(it)->F-1;
        LL arrive_t=(dsum[id-1]+sp_t+c[id])%t;
        DEBUG("id",id,"sp_t",sp_t,arrive_t);
        an=min(an,dsum[id-1]+dp[id]+(t-arrive_t)%t);
    }
    W(an);
}
void input() {
    R(n,t);
    FOR(i,1,n)R(g[i],c[i]);
    FOR(i,1,n-1)R(d[i]);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}