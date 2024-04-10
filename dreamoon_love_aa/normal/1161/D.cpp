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
const int SIZE = 2e3+10;
char s[SIZE];
LL an;
bool match(char x,char y){
    if(x=='?'||y=='?')return 1;
    return x==y;
    
}
LL mypow(LL x,LL y){
    x%=MOD;
    LL res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
struct Union_Find{
    int d[SIZE],num[SIZE],v[SIZE],t[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1,v[i]=0,t[i]=-1;
    }
    bool is_root(int x){return d[x]==x;}
    bool make(int x,int now){
        while(x!=d[x]){
            now^=v[x];
            x=d[x];
        }
        if(t[x]==-1){
            t[x]=now;
            return 1;
        }
        return t[x]==now;
    }
    bool uu(int x,int y,int now){
        while(x!=d[x]){
            now^=v[x];
            x=d[x];
        }
        while(y!=d[y]){
            now^=v[y];
            y=d[y];
        }
        if(x==y){
            return !now;
        }
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        v[x]=now;
        d[x]=y;
        return 1;
    }
}U;
int main(){
    MOD = 998244353;
    RS(s);
    int n=LEN(s);
    reverse(s,s+n);
    REPP(i,1,n){
        U.init(n+i);
        bool err=0;
        REP(j,i){
            if(s[j]!='?'){
                if(!U.uu(min(j,n-1-j),min(j,i-1-j)+n,int(s[j]-'0')))err=1;
            }
        }
        REPP(j,i,n){
            if(s[j]!='?'&&!U.make(min(j,n-1-j),int(s[j]-'0')))err=1;
        }
        if(!U.make(0,1))err=1;
        if(!U.make(n,1))err=1;
        if(err)continue;
        LL tmp=1;
        REP(j,n){
            if(j<=n-1-j&&U.is_root(j)){
                if(U.t[j]==-1)ADD(tmp,tmp);
            }
        }
        REP(j,i){
            if(j<=i-1-j&&U.is_root(n+j)){
                if(U.t[n+j]==-1)ADD(tmp,tmp);
            }
        }
        ADD(an,tmp);
    }
    W(an);
    return 0;
}