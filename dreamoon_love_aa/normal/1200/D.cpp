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
char s[SIZE][SIZE];
int dp[SIZE][SIZE];
int row_cnt[SIZE],col_cnt[SIZE];
int get(int x1,int y1, int x2,int y2){
    if(y2<y1||x2<x1)return 0;
    return dp[x2][y2]+dp[x1-1][y1-1]-dp[x2][y1-1]-dp[x1-1][y2];
}
int v[SIZE][SIZE];
int tmp[SIZE];
int main(){
    int n,k;
    R(n,k);
    FOR(i,1,n)RS(s[i]+1);
    FOR(i,1,n)FOR(j,1,n){
        row_cnt[i]+=(s[i][j]=='W');
        col_cnt[j]+=(s[i][j]=='W');
        dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(s[i][j]=='W');
    }
    FOR(i,1,n){
        row_cnt[i]=(row_cnt[i]==n);
        col_cnt[i]=(col_cnt[i]==n);
    }
    REPP(i,1,SIZE){
        row_cnt[i]+=row_cnt[i-1];
        col_cnt[i]+=col_cnt[i-1];
    }
    FOR(i,k,n){
        FOR(j,1,n){
            tmp[j]=tmp[j-1]+((get(1,j,i-k,j)+get(i+1,j,n,j))==n-k);
        }
        FOR(j,k,n){
            v[i][j]+=tmp[j]-tmp[j-k];
            v[i][j]+=row_cnt[i-k]-row_cnt[i]+row_cnt[n];
        }
    }
    FOR(j,k,n){
        FOR(i,1,n){
            tmp[i]=tmp[i-1]+((get(i,1,i,j-k)+get(i,j+1,i,n))==n-k);
        }
        FOR(i,k,n){
            v[i][j]+=tmp[i]-tmp[i-k];
            v[i][j]+=col_cnt[j-k]-col_cnt[j]+col_cnt[n];
        }
    }
    int an=0;
    FOR(i,k,n)FOR(j,k,n)an=max(an,v[i][j]);
    W(an);
    return 0;
}