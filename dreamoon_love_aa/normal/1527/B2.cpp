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
#define PB emplace_back
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
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
int n;
string s;
int dp[1001][2][501][2];
bool u[1001][2][501][2];
int f(int sp, int cc, int two,int lat_rev){
    if(u[sp][cc][two][lat_rev]){
        return dp[sp][cc][two][lat_rev];
    }
    u[sp][cc][two][lat_rev]=1;
    int an=1e9;
    if(!lat_rev&&sp){
        an=min(an,-f(sp,cc,two,1));
    }
    if(sp)an=min(an,1-f(sp-1,cc,two,0));
    if(cc)an=min(an,1-f(sp,cc-1,two,0));
    if(two){
        an=min(an,1-f(sp+1,cc,two-1,0));
    }
    return dp[sp][cc][two][lat_rev]=an;
}
void solve() {
    int l=0,r=n-1;
    int cc=0;
    int sp=0;
    int two=0;
    while(l<=r){
        if(l==r){
            if(s[l]=='0'){
                cc=1;
            }
            break;
        }
        if(s[l]!=s[r]){
            sp++;
        }else if(s[l]=='0'){
            two++;
        }
        l++;
        r--;
    }
    int an=f(sp,cc,two,0);
    if(an>0)W("BOB");
    else if(an==0)W("DRAW");
    else W("ALICE");
}
void input() {
    R(n);
    R(s);
}
int main(){
    dp[0][0][0][0]=dp[0][0][0][1]=0;
    u[0][0][0][0]=u[0][0][0][1]=1;
    CASET {
        input();
        solve();
    }
    return 0;
}