/*{{{*/
#include <bits/stdc++.h>
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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
char s[66][66];
int dp[66][66];
int get(int x1,int y1,int x2,int y2){
    x1--;y1--;
    return dp[x2][y2]+dp[x1][y1]-dp[x1][y2]-dp[x2][y1];
}
void solve(){
    int r,c;
    R(r,c);
    REP(i,r)RS(s[i+1]+1);
    FOR(i,1,r)FOR(j,1,c){
        dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(s[i][j]=='A');
    }
    if(dp[r][c]==r*c)W(0);
    else if(dp[r][c]==0)W("MORTAL");
    else{
        if(get(1,1,1,c)==c||get(r,1,r,c)==c||get(1,1,r,1)==r||get(1,c,r,c)==r){
            W(1);
            return;
        }
        FOR(i,1,r){
            if(get(i,1,i,c)==c){
                W(2);
                return;
            }
        }
        FOR(j,1,c){
            if(get(1,j,r,j)==r){
                W(2);
                return;
            }
        }
        if(s[1][1]=='A'||s[r][c]=='A'||s[1][c]=='A'||s[r][1]=='A'){
            W(2);
            return;
        }
        FOR(i,1,r)FOR(j,1,c){
            if(i==1||j==1||i==r||j==c){
                if(s[i][j]=='A'){
                    W(3);
                    return;
                }
            }
        }
        W(4);
    }
}
int main(){
    CASET{
        solve();
    }
    return 0;
}