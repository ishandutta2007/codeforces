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
const int MUL = 137;
bool PRE_DONE=0;
int mul[SIZE],inv[SIZE];
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
void pre_do(){
    if(PRE_DONE)return;
    PRE_DONE=1;
    mul[0]=1;
    REPP(i,1,SIZE){
        mul[i]=(LL)mul[i-1]*MUL%MOD;
    }
    LL tmp=mypow(MUL,MOD-2);
    inv[0]=1;
    REPP(i,1,SIZE)inv[i]=inv[i-1]*tmp%MOD;
}
struct string_hash{
    VI dp;
    void build(string _s){
        pre_do();
        dp=VI(SZ(_s)+1);
        REP(i,SZ(_s)){
            dp[i+1]=(dp[i]+(LL)mul[i]*_s[i])%MOD;
        }
    }
    int get(int L,int R){
        if(L>R)return 0;
        R++;
        LL v=(LL)(dp[R]-dp[L])*inv[L]%MOD;
        if(v<0)v+=MOD;
        return v;
    }
};
int main(){
    string s1,s2;
    R(s1,s2);
    int cnt[2]={};
    REP(i,SZ(s1)){
        cnt[s1[i]-'0']++;
    }
    string_hash hh;
    int an=0;
    hh.build(s2);
    for(int i=1;i*cnt[0]<SZ(s2);i++){
        if((SZ(s2)-cnt[0]*i)%cnt[1])continue;
        int j=(SZ(s2)-cnt[0]*i)/cnt[1];
        int v[2]={-1,-1};
        int now=0;
        bool err=0;
        REP(k,SZ(s1)){
            if(s1[k]=='0'){
                if(v[0]==-1){
                    v[0]=hh.get(now,now+i-1);
                }
                else{
                    if(v[0]!=hh.get(now,now+i-1))err=1;
                }
                now+=i;
            }
            else{
                if(v[1]==-1){
                    v[1]=hh.get(now,now+j-1);
                }
                else{
                    if(v[1]!=hh.get(now,now+j-1))err=1;
                }
                now+=j;
            }
            if(err)break;
        }
        if(v[0]==v[1]&&i==j)err=1;
        if(!err)an++;
    }
    W(an);
    return 0;
}