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
void my_mul(LL& x,LL v){x=x*v%MOD;}
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
LL inv(LL x){
    return mypow(x,MOD-2);
}
LL dp1[SIZE],dp2[SIZE];
LL get(int x,int y){
    LL qq=dp1[y]*inv(dp1[x-1])%MOD;
    LL pp=1;
    if(x!=y){
        y--;
        pp=(dp2[y]-dp2[x-1])*inv(dp1[x-1])%MOD+1;
    }
    if(pp<0)pp+=MOD;
    return pp*inv(qq)%MOD;
}
int main(){
    MOD = 998244353;
    int n,q; R(n,q);
    int inv100=inv(100);
    set<int>AA{1,n+1};
    dp2[0]=1;
    dp1[0]=1;
    LL now=1;
    FOR(i,1,n){
        LL x;
        R(x);
        my_mul(x,inv100);
        dp1[i]=dp1[i-1]*x%MOD;
        my_mul(now,x);
        ADD(dp2[i],dp2[i-1]+now);
    }
    LL ans=get(1,n);
    while(q--){
        int id;
        R(id);
        if(AA.count(id)){
            auto it=AA.find(id);
            int x=*prev(it);
            int y=*next(it);
            ADD(ans,get(x,y-1));
            ADD(ans,-get(x,id-1));
            ADD(ans,-get(id,y-1));
            AA.erase(it);
        }
        else{
            auto it=AA.lower_bound(id);
            int x=*prev(it);
            int y=*it;
            AA.insert(id);
            ADD(ans,-get(x,y-1));
            ADD(ans,get(x,id-1));
            ADD(ans,get(id,y-1));
            AA.insert(id);
        }
        W(ans);
    }
    return 0;
}