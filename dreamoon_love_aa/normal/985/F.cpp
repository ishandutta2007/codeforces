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
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 2e5+10;
const int MUL = 2333333;
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
    void build(VI& _s){
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
}hh;
char input[SIZE];
int nxt[SIZE][26];
VI tmp;
int main(){
    int n,m; R(n,m);
    RS(input);
    REP(i,26)nxt[n][i]=n;
    for(int i=n-1;i>=0;i--){
        REP(j,26)nxt[i][j]=nxt[i+1][j];
        nxt[i][input[i]-'a']=i;
    }
    {
        int lat[26]={};
        REP(i,n){
            tmp.PB(i-lat[input[i]-'a']);
            lat[input[i]-'a']=i;
        }
        hh.build(tmp);
    }
    while(m--){
        int x,y,len; R(x,y,len);
        x--;y--;
        LL v[2];
        v[0]=hh.get(x,x+len-1);
        v[1]=hh.get(y,y+len-1);
        int xx[2]={x,y};
        REP(k,2){
            REP(i,26){
                if(nxt[xx[k]][i]<=xx[k]+len-1){
                    int pos=nxt[xx[k]][i];
                    ADD(v[k],-tmp[pos]*(LL)mul[pos-xx[k]]);
                }
            }
        }
        W(v[0]==v[1]?"YES":"NO");
    }
    return 0;
}