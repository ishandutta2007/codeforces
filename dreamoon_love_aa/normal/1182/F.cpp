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
// a*x+b*y=z
struct gcd_t {long long x,y,z;};
gcd_t gcd(long long a,long long b) {
    if(b==0)return (gcd_t){1,0,a};
    gcd_t t=gcd(b,a%b);
    return (gcd_t){t.y,t.x-t.y*(a/b),t.z};
}
LL a,b,p,q;
LL check(LL v){
    gcd_t gg=gcd(p,q);
    if(v%gg.z)return -1;
    LL x=gg.x*(v/gg.z);
    LL dd=q/abs(gg.z);
    if(x>a)x-=(x-a)/dd*dd;
    if(x<a)x+=(a-x)/dd*dd;
    while(x-dd>=a)x-=dd;
    while(x<a)x+=dd;
    if(x>=b)return -1;
    return x;
}
int main(){
    CASET{
        R(a,b,p,q);
        LL gg=__gcd(p,q);
        p/=gg;
        q/=gg;
        p%=q;
        if(q&1){
            p<<=1;
            q<<=1;
        }
        LL half_q=q/2;
        if(b-a<=2000000){
            LL now=a*p%q;
            LL mi=q;
            LL an=-1;
            FOR(x,a,b){
                LL AA=abs(now-half_q);
                if(AA<mi){
                    mi=AA;
                    an=x;
                }
                now+=p;
                if(now>=q)now-=q;
            }
            W(an);
        }
        else{
            LL v=check(half_q);
            if(v!=-1)W(v);
            else{
                LL an=0;
                REPP(i,1,half_q){
                    LL v1=check(half_q-i);
                    LL v2=check(half_q+i);
                    if(v1==-1&&v2==-1)continue;
                    if(v1==-1)an=v2;
                    else if(v2==-1)an=v1;
                    else an=min(v1,v2);
                    break;
                }
                W(an);
            }
        }
    }
    return 0;
}