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
void ADD(LL& x,LL v){x+=v;if(x>=MOD)x-=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
LL dp[2][2][20];
int v[2][20];
void solve(int n,int have_three,int two_num){
    int now=0,nxt=1;
    FOR(i,0,have_three)dp[now][i][two_num-i]=1;
    REPP(AA,1,n){
        MS0(dp[nxt]);
        FOR(i,0,have_three)FOR(j,0,two_num){
            ADD(dp[nxt][i][j],dp[now][i][j]*(n/v[i][j]-AA)%MOD);
            if(i){
                ADD(dp[nxt][i-1][j],dp[now][i][j]*(n/v[i-1][j]-n/v[i][j])%MOD);
            }
            if(j){
                ADD(dp[nxt][i][j-1],dp[now][i][j]*(n/v[i][j-1]-n/v[i][j])%MOD);
            }
        }
        swap(now,nxt);
    }
    W(dp[now][0][0]);
}
int main(){
    int n; R(n);
    int two_num=0;
    int now=1;
    v[0][0]=1;
    v[1][0]=3;
    REP(i,2)REPP(j,1,20){
        v[i][j]=v[i][j-1]*2;
    }
    while(now*2<=n){
        now*=2;
        two_num++;
    }
    if(now/2*3<=n){
        solve(n,1,two_num);
    }
    else{
        solve(n,0,two_num);
    }
    return 0;
}