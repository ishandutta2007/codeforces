/*{{{*/
#include <bits/stdc++.h>
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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
int p[SIZE];
void build(){
    REPP(i,2,SIZE){
        if(!p[i]){
            for(int j=i;j<SIZE;j+=i){
                if(!p[j])p[j]=i;
            }
        }
    }
}
VPII n_fac,m_fac,s_fac;
LL n,m,s;
void read(VPII &fac,LL & v,int add=0){
    LL x,y,z;
    R(x,y,z);
    v=x*y*z;
    LL d[3]={x,y,z};
    map<int,int>gg;
    REP(i,3){
        while(d[i]!=1){
            gg[p[d[i]]]++;
            d[i]/=p[d[i]];
        }
    }
    if(add)gg[2]++;
    fac=VPII(ALL(gg));
}
void dfs2(int idx,LL v,LL &an){
    if(idx==SZ(s_fac)){
        if(v<=n){
            an++;
        }
        return;
    }
    dfs2(idx+1,v,an);
    REP(i,s_fac[idx].S){
        v*=s_fac[idx].F;
        dfs2(idx+1,v,an);
    }
}
LL dp[SIZE];
LL an;
void dfs1(VL &gg,int id,LL v,int ng){
    if(id==SZ(gg)){
        an+=ng*(m/v);
        return;
    }
    dfs1(gg,id+1,v*gg[id],-ng);
    dfs1(gg,id+1,v,ng);
}
void solve(){
    read(n_fac,n);
    read(m_fac,m);
    read(s_fac,s,1);
    an=0;
    VL gg;
    REP(i,SZ(n_fac)){
        LL now=1;
        FOR(j,1,n_fac[i].S){
            now*=n_fac[i].F;
            if(2*s%now){
                gg.PB(now);
                break;
            }
        }
    }
    dfs1(gg,0,1,1);
    dfs2(0,1,an);
    W(an);
}
int main(){
    build();
    CASET{
        solve();
    }
    return 0;
}