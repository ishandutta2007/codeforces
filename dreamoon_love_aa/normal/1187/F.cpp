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
LL l[SIZE],r[SIZE],num[SIZE];
LL same[SIZE],dif[SIZE],dif_inv[SIZE],inv_num[SIZE];
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
int main(){
    int n; R(n);
    LL base=1;
    FOR(i,1,n)R(l[i]);
    FOR(i,1,n)R(r[i]);
    FOR(i,1,n){
        num[i]=r[i]-l[i]+1;
        inv_num[i]=inv(num[i]);
        base=base*num[i]%MOD;
    }
    LL dif_inv_sum=0;
    FOR(i,2,n){
        same[i]=max(0LL,min(r[i],r[i-1])-max(l[i],l[i-1])+1);
        dif[i]=(num[i]*num[i-1]-same[i])%MOD;
        dif_inv[i]=dif[i]*inv_num[i]%MOD*inv_num[i-1]%MOD;
        ADD(dif_inv_sum,dif_inv[i]);
    }
    LL an=base;
    FOR(i,2,n){
        ADD(an,base*dif_inv[i]*3);
        if(i>2){
            LL cnt=num[i]*num[i-1]%MOD*num[i-2]-same[i-1]*num[i]-same[i]*num[i-2]+max(0LL,min({r[i],r[i-1],r[i-2]})-max({l[i],l[i-1],l[i-2]})+1);
            cnt%=MOD;
            ADD(an,base*inv_num[i]%MOD*inv_num[i-1]%MOD*inv_num[i-2]%MOD*cnt*2);
        }
        ADD(an,base*(dif_inv_sum-dif_inv[i]-dif_inv[i-1]-dif_inv[i+1])%MOD*dif_inv[i]);
    }
    W(an*inv(base)%MOD);
    return 0;
}