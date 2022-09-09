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
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<20;
const int AA = 40;
char s[SIZE];
int n,A,B;
int dp[41][81][40][40];
int from[41][81][40][40];
void print(int id,int x,int y, int z){
    if(!id)return;
    if(!dp[id][x][y][z]){
        print(id-1,x-1,from[id][x][y][z],z);
        _W('R');
    }else{
        print(id-1,x+1,y,from[id][x][y][z]);
        _W('B');
    }
}
void solve() {
    MS1(dp);
    dp[0][AA][0][0]=0;
    REP(i,n){
        int d=s[i]-'0';
        FOR(j,0,2*AA){
            REP(k,A)REP(r,B){
                if(dp[i][j][k][r]==-1)continue;
                dp[i+1][j+1][(k*10+d)%A][r]=0;
                from[i+1][j+1][(k*10+d)%A][r]=k;
                dp[i+1][j-1][k][(r*10+d)%B]=1;
                from[i+1][j-1][k][(r*10+d)%B]=r;
            }
        }
    }
    int res=0;
    FOR(i,0,2*AA){
        if(dp[n][i][0][0]!=-1){
            if(abs(i-AA)<abs(res-AA))res=i;
        }
    }
    if(abs(res-AA)>=n)W(-1);
    else{
        print(n,res,0,0);
        W("");
    }
}
void input() {
    R(n,A,B);
    RS(s);
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}