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
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<20;
int k;
map<LL,int>AA;
LL dp0[64];
int getAA(LL x){
    if(AA.count(x))return AA[x];
    return -1;
}
VL get(LL x, int lv){
    VL ret(6);
    if(lv==1){
        int ty=getAA(x);
        REP(i,6){
            ret[i]=(ty==-1||ty==i);
        }
        return ret;
    }
    auto it=AA.find(x);
    if(it==AA.end()){
        REP(i,6)ret[i]=dp0[lv];
        return ret;
    }
    int ty=it->S;
    VL l_dp=get(x*2,lv-1);
    VL r_dp=get(x*2+1,lv-1);
    REP(i,6){
        if(ty==-1||ty==i){
            LL lv=0,rv=0;
            REP(j,6){
                if(i==j||i+j==5)continue;
                ADD(lv,l_dp[j]);
                ADD(rv,r_dp[j]);
            }
            ADD(ret[i],lv*rv);
        }else ret[i]=0;
    }
    return ret;
}
void solve() {
    dp0[1]=1;
    FOR(i,2,60){
        dp0[i]=dp0[i-1]*dp0[i-1]%MOD*4*4%MOD;
    }
    auto ret=get(1,k);
    LL an=0;
    for(auto v: ret) {
        ADD(an,v);
    }
    W(an);
}
map<char,int> to{
    {'w',0},
    {'g',1},
    {'r',2},
    {'o',3},
    {'b',4},
    {'y',5},
};
void input() {
    R(k);
    int n;
    R(n);
    FOR(i,1,n){
        LL v;
        string s;
        R(v,s);
        AA[v]=to[s[0]];
        if(v!=1){
            do{
                v>>=1;
                if(!AA.count(v))AA[v]=-1;
            }while(v!=1);
        }
    }
}
int main(){
    input();
    solve();
    return 0;
}