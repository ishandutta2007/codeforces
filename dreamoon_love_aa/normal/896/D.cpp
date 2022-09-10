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
typedef int64_t LL;
typedef uint64_t ULL;
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
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e5+10;
struct Combination{
    int a[12],xb,s[SIZE][12],j,jf[SIZE],vf[SIZE],mod;
    void init(int _mod){
        mod=_mod;
        int x=mod,y=mod;
        for(int i=2;i*i<=x;++i)
            if(x%i==0){
                a[++xb]=i;y=y/i*(i-1);
                while(x%i==0)x/=i;
            }
        if(x>1)a[++xb]=x,y=y/x*(x-1);
        *jf=*vf=1;
        REPP(i,1,SIZE){
            for(x=i,memcpy(s[i],s[i-1],48),j=1;j<=xb;++j)
                if(x%a[j]==0)
                    while(x%a[j]==0)x/=a[j],++s[i][j];
            jf[i]=1ll*jf[i-1]*x%mod;
            vf[i]=1ll*vf[i-1]*pow(x,y-1)%mod;
        }
    }
    int pow(int x,int y){
        int ans=1;
        for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)ans=1ll*ans*x%mod;
        return ans;
    }
    LL C(int x,int y){
        int i,ans=1ll*jf[x]*vf[y]%mod*vf[x-y]%mod;
        for(i=1;i<=xb;++i)
            ans=1ll*ans*pow(a[i],s[x][i]-s[y][i]-s[x-y][i])%mod;
        return ans;
    }
}cal;
LL solve(int n,int x){
    LL v=0;
    FOR(i,x,n){
        ADD(v,cal.C(n,i)*cal.C(i,(i-x)/2));
    }
    return v;
}
int main(){
    int n,l,r;
    R(n,MOD,l,r);
    cal.init(MOD);
    LL an=solve(n,l);
    ADD(an,-solve(n,r+1));
    W(an);
    return 0;
}