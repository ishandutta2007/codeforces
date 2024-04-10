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
int calc(int t,int low1,int low2,int n1,int n2,int a,int b){
    if(t<=0)return 0;
    if((LL)low1*a+(LL)low2*b>t)return 0;
    //W(t,low1,low2,n1,n2,a,b);
    int res=low1+low2;
    n1-=low1;
    n2-=low2;
    t-=low1*a+low2*b;
    int v=min(n1,t/a);
    res+=v;
    t-=a*v;
    v=min(n2,t/b);
    res+=v;
    return res;
}
void solve(){
    int n,T,a,b;
    R(n,T,a,b);
    VI p(n);
    REP(i,n)R(p[i]);
    VI gg[2];
    int mi=1e9;
    REP(i,n){
        int t;
        R(t);
        gg[p[i]].PB(t);
        mi=min(mi,t);
    }
    REP(i,2)sort(ALL(gg[i]));
    int it[2]={};
    int an=calc(mi-1,0,0,SZ(gg[0]),SZ(gg[1]),a,b);
    while(it[0]<SZ(gg[0])||it[1]<SZ(gg[1])){
        mi=1e9;
        REP(i,2)
            if(it[i]<SZ(gg[i]))mi=min(mi,gg[i][it[i]]);
        REP(i,2){
            if(it[i]<SZ(gg[i])&&mi==gg[i][it[i]]){
                it[i]++;
            }
        }
        int t=T;
        REP(i,2){
            if(it[i]<SZ(gg[i]))t=min(t,gg[i][it[i]]-1);
        }
        an=max(an,calc(t,it[0],it[1],SZ(gg[0]),SZ(gg[1]),a,b));
    }
    W(an);
}
int main(){
    CASET{solve();}
    return 0;
}