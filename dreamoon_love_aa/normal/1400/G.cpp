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
const int SIZE = 300010;
LL fac[SIZE],inv[SIZE];
LL mypow(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
LL C(int x,int y){
    if(y<0||y>x)return 0;
    return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
void build(){
    assert(MOD>=SIZE);
    fac[0]=1;
    REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
    inv[SIZE-1]=mypow(fac[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
int num[SIZE];
int l[SIZE],r[SIZE];
int a[20],b[20],al[20],ar[20];
VI AA;
int n,m;
vector<pair<PII,int>>lv[41];
void dfs(int x,LL mask,int ll,int rr,int ng){
    if(ll>rr)return;
    if(x==m){
        lv[__builtin_popcountll(mask)].PB(MP(MP(ll,rr),ng));
        return;
    }
    dfs(x+1,mask,ll,rr,ng);
    dfs(x+1,mask|(1LL<<a[x])|(1LL<<b[x]),max(al[x],ll),min(ar[x],rr),-ng);
}
LL dp[SIZE];
LL get(int x,int y){
    return dp[y]-dp[x-1];
}
void solve() {
    MOD=998244353;
    build();
    R(n,m);
    FOR(i,1,n){
        R(l[i],r[i]);
        num[l[i]]++;
        num[r[i]+1]--;
    }
    FOR(i,1,n)num[i]+=num[i-1];
    REP(i,m){
        R(a[i],b[i]);
        al[i]=max(l[a[i]],l[b[i]]);
        ar[i]=min(r[a[i]],r[b[i]]);
        AA.PB(a[i]);
        AA.PB(b[i]);
    }
    SORT_UNIQUE(AA);
    REP(i,m){
        a[i]=GET_POS(AA,a[i]);
        b[i]=GET_POS(AA,b[i]);
    }
    dfs(0,0,1,n,1);
    LL an=0;
    FOR(i,0,2*m){
        if(!SZ(lv[i]))continue;
        FOR(j,1,n){
            dp[j]=dp[j-1];
            if(j>=i)ADD(dp[j],C(num[j]-i,j-i));
        }
        for(auto &x: lv[i]){
            ADD(an,get(x.F.F,x.F.S)*x.S);
        }
    }
    W(an);
}
int main(){
#define MULTITEST 0
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}