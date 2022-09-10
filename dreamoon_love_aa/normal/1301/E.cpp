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
const int SIZE = 514;
int dp0[4][SIZE][SIZE];
short dp[SIZE][SIZE][SIZE];
char s[SIZE][SIZE];
int n,m,q;
int get(char c){
    if(c=='R')return 0;
    if(c=='G')return 1;
    if(c=='Y')return 2;
    return 3;
}
int get(int c,int x1,int y1,int x2,int y2){
    return dp0[c][x2][y2]+dp0[c][x1][y1]-dp0[c][x1][y2]-dp0[c][x2][y1];
}
void solve(){
    R(n,m,q);
    FOR(i,1,n)RS(s[i]+1);
    FOR(i,1,n)FOR(j,1,m){
        s[i][j]=get(s[i][j]);
    }
    REP(c,4){
        FOR(i,1,n)FOR(j,1,m){
            dp0[c][i][j]=dp0[c][i-1][j]+dp0[c][i][j-1]-dp0[c][i-1][j-1]+(s[i][j]==c);
        }
    }
    FOR(i,1,n)FOR(j,1,m){
        int mi=min(i,j);
        FOR(k,1,mi){
            if(!(k&1)){
                int half_k=k/2;
                int need=half_k*half_k;
                if(get(3,i-half_k,j-half_k,i,j)==need 
                 &&get(2,i-half_k,j-k,i,j-half_k)==need 
                 &&get(1,i-k,j-half_k,i-half_k,j)==need 
                 &&get(0,i-k,j-k,i-half_k,j-half_k)==need)dp[i][j][k]=k;
            }
            dp[i][j][k]=max({dp[i][j][k],dp[i][j][k-1],dp[i-1][j][k-1],dp[i][j-1][k-1],dp[i-1][j-1][k-1]});
        }
    }
    while(q--){
        int x1,y1,x2,y2;
        R(x1,y1,x2,y2);
        int side=min(x2-x1,y2-y1)+1;
        short an=0;
        if(x2-x1<y2-y1){
            int len=(y2-y1)-(x2-x1)+1;
            REP(i,len){
                an=max(an,dp[x2][y2-i][side]);
            }
        }
        else{
            int len=(x2-x1)-(y2-y1)+1;
            REP(i,len){
                an=max(an,dp[x2-i][y2][side]);
            }
        }
        W((int)an*(int)an);
    }
}
int main(){
    solve();
    return 0;
}