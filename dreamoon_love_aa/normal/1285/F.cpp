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
const int SIZE = 1e5+10;
int mu[SIZE], p[SIZE], pcnt, np[SIZE];
VI fac[SIZE];
const int MAX_N = 100000;
void init(int n) {
    mu[1]=1;
    for(int i=2; i<=n; ++i) {
        if(!np[i]) {
            p[pcnt++]=i;
            mu[i]=-1;
        }
        for(int j=0; j<pcnt; ++j) {
            int t=p[j]*i;
            if(t>n) break;
            np[t]=1;
            if(i%p[j]==0) {
                mu[t]=0;
                break;
            }
            mu[t]=-mu[i];
        }
    }
    FOR(i,1,MAX_N){
        if(mu[i]){
            for(int j=i;j<=MAX_N;j+=i)fac[j].PB(i);
        }
    }
}
int cnt[SIZE];
bool c[SIZE];
int qq[SIZE],ll,rr;
int BASE;
LL an;
void pop(){
    for(int v:fac[qq[ll]]){
        cnt[v]--;
    }
    ll++;
    if(ll==rr||qq[ll]==1)return;
    bool suc=0;
    while(1){
        int now=0;
        for(int v:fac[qq[ll]]){
            now+=cnt[v]*mu[v];
        }
        if(now){
            an=max(an,BASE*(LL)qq[ll]*qq[rr-1]);
            suc=1;
            rr--;
            for(int v:fac[qq[rr]]){
                cnt[v]--;
            }
        }
        else break;
    }
    if(suc)pop();
}
void add(int x){
    if(x==1)return;
    for(int v:fac[x]){
        cnt[v]++;
    }
    qq[rr++]=x;
    int me=qq[ll];
    int now=0;
    for(int v:fac[me]){
        now+=cnt[v]*mu[v];
    }
    if(now){
        an=max(an,(LL)BASE*me*x);
        for(int v:fac[x]){
            cnt[v]--;
        }
        rr--;
        pop();
    }
}
int main(){
    init(MAX_N);
    int n;
    R(n);
    FOR(i,1,n){
        int x;
        R(x);
        c[x]=1;
        an=max(an,(LL)x);
    }
    FOR(i,1,MAX_N){
        BASE=i;
        ll=rr=0;
        memset(cnt,0,sizeof(int)*(MAX_N/i+1));
        for(int j=MAX_N/i;j>0;j--){
            if(c[j*i]){
                add(j);
            }
        }
        while(ll<rr)pop();
    }
    W(an);
    return 0;
}