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
const LL MAX_N = 10000000000LL;
LL mypow(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1){
            res*=x;
            res=min(res,MAX_N);
        }
        y>>=1;
        x=x*x;
        x=min(x,MAX_N);
    }
    return res;
}
string an;
char tmp[SIZE];
void update(){
    string ss(tmp);
    if(SZ(ss)<SZ(an))an=ss;
}
int dc[SIZE];
int main(){
    REPP(i,1,SIZE){
        dc[i]=1+dc[i/10];
    }
    LL n; R(n);
    if(n==MAX_N){
        W("100^5");
        return 0;
    }
    an=to_string(n);
    FOR(a,1,9)FOR(b,1,9)FOR(c,1,9)FOR(d,1,9)FOR(e,1,9){
        if(a*mypow(b,c)+mypow(d,e)==n){
            if(a!=1){
                sprintf(tmp,"%d*%d^%d+%d^%d",a,b,c,d,e);
            }
            else{
                sprintf(tmp,"%d^%d+%d^%d",b,c,d,e);
            }
            update();
        }
    }
    FOR(a,1,9)FOR(b,1,9)FOR(c,1,9)FOR(d,1,9)FOR(e,1,9){
        if(mypow(a,b)*mypow(c,d)+e==n){
            sprintf(tmp,"%d^%d*%d^%d+%d",a,b,c,d,e);
            update();
        }
    }
    for(LL b=2;b*b<=n;b++){
        if(n%(b*b)==0){
            LL now=b*b;
            int c=2;
            while(n%now==0){
                if(n==now){
                    sprintf(tmp,"%lld^%d",b,c);
                }
                else{
                    sprintf(tmp,"%lld*%lld^%d",n/now,b,c);
                }
                now*=b;
                c++;
            }
            update();
        }
    }
    for(LL b=2;b<1000;b++){
        LL v=b*b;
        for(LL c=2;v<=n;c++,v*=b){
            for(LL a=1;a<1000&&a*v<=n;a++){
                sprintf(tmp,"%lld*%lld^%lld+%lld",a,b,c,n-a*v);
                update();
            }
        }
    }
    for(LL b=2;b*b<=n;b++){
        LL v=b*b;
        for(LL c=2;v<=n;c++,v*=b){
            sprintf(tmp,"%lld^%lld+%lld",b,c,n-v);
            update();
        }
    }
    for(LL a=2;a<1000;a++){
        LL v1=a*a;
        for(LL b=2;v1<n;b++,v1*=a){
            for(LL c=a;c<1000;c++){
                LL v2=c*c;
                LL d=2;
                while(v1+v2<n){
                    d++;
                    v2*=c;
                }
                if(v1+v2==n){
                    sprintf(tmp,"%lld^%lld+%lld^%lld",a,b,c,d);
                    update();
                }
            }
        }
    }
    W(an);
    return 0;
}