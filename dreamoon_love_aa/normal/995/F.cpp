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
void _R(int &x) { scanf("%d", &x); }
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
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
const int AA = 3056;
LL fac[SIZE];
LL mypow(LL x,LL y){
    x%=MOD;
    LL a=1%MOD;
    while(y){
        if(y&1)a=a*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return a;
}
//1-base
struct Difference{
    LL a[SIZE],cc[SIZE];
    int n;
    void build(LL _a[],int _n){
        fac[0]=1;
        REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
        n=_n;
        REPP(i,1,n+1)a[i]=_a[i];
        REPP(i,1,n+1){
            cc[i]=mypow(fac[i-1]*fac[n-i],MOD-2)*a[i]%MOD;
            if((n-i)%2==1)cc[i]=(MOD-cc[i])%MOD;
        }
    }
    LL get(LL x){
        x%=MOD;
        if(x<=n)return a[x];
        LL an=0;
        LL tmp=1;
        REPP(i,1,n+1)tmp=tmp*(x-i)%MOD;
        REPP(i,1,n+1){
            ADD(an,tmp*mypow(x-i,MOD-2)%MOD*cc[i]);
        }
        return an;
    }
}D;
LL a[SIZE];
/*
int main(){
    DRII(n,k);
    REPP(i,1,k+5){
        a[i]=(a[i-1]+mypow(i,k))%MOD;
    }
    D.build(a,k+4);
    cout<<D.get(n);
    return 0;
}*/
LL dp[AA][AA];
VI e[AA];
void dfs(int x){
    if(SZ(e[x])==0){
        REPP(i,1,AA)dp[x][i]=i;
        return;
    }
    REPP(i,1,AA)dp[x][i]=1;
    for(int y:e[x]){
        dfs(y);
        REPP(i,1,AA){
            dp[x][i]*=dp[y][i];
            dp[x][i]%=MOD;
        }
    }
    REPP(i,1,AA)ADD(dp[x][i],dp[x][i-1]);
}
int main(){
    int n,m;
    R(n,m);
    FOR(i,2,n){
        int x;
        R(x);
        e[x].PB(i);
    }
    dfs(1);
    REPP(i,1,AA){
        a[i]=dp[1][i];
    }
    D.build(a,AA-1);
    W(D.get(m));
    return 0;
}