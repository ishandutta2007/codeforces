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
const int SIZE = 1010;
string input;
int dp[SIZE][51][51];
int nxt_s[51][26];
int nxt_t[51][26];
void build(const string &s,int nxt[][26]){
    int n=SZ(s);
    FOR(i,0,n){
        REP(j,26){
            string now=(i?s.substr(0,i):"")+string(1,'a'+j);
            for(int k=min(i+1,n);k>0;k--){
                if(now.substr(SZ(now)-k)==s.substr(0,k)){
                    nxt[i][j]=k;
                    break;
                }
            }
        }
    }
}
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
bool match(char c1,char c2){
    if(c1=='*')return 1;
    return c1==c2;
}
int main(){
    string s,t;
    R(input);
    R(s);
    R(t);
    build(s,nxt_s);
    build(t,nxt_t);
    FOR(i,0,SZ(input))FOR(j,0,SZ(s))FOR(k,0,SZ(t))dp[i][j][k]=-10000000;
    dp[0][0][0]=0;
    REP(i,SZ(input)){
        FOR(j,0,SZ(s))FOR(k,0,SZ(t)){
            if(dp[i][j][k]<-100000)continue;
            REP(r,26){
                if(match(input[i],r+'a'))
                maa(dp[i+1][nxt_s[j][r]][nxt_t[k][r]],dp[i][j][k]+(nxt_s[j][r]==SZ(s))-(nxt_t[k][r]==SZ(t)));
            }
        }
    }
    int an=-10000000;
    FOR(i,0,SZ(s))FOR(j,0,SZ(t))maa(an,dp[SZ(input)][i][j]);
    W(an);
    return 0;
}