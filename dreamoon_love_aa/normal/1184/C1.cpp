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
const double EPS=1e-12;
const double PI=acos(-1);
PII p[50];
set<PII>AA;
int n;
int dp[52][52];
int get(int x1,int y1,int x2,int y2){
    x1--;y1--;
    return dp[x2][y2]+dp[x1][y1]-dp[x1][y2]-dp[x2][y1];
}
int main(){
    R(n);
    REP(i,4*n+1){
        R(p[i].F,p[i].S);
        dp[p[i].F+1][p[i].S+1]++;
    }
    FOR(i,1,51)FOR(j,1,51)dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
    FOR(i,1,51)FOR(j,1,51){
        for(int k=2;max(i+k,j+k)<=51;k++){
            if(get(i,j,i+k,j+k)-get(i+1,j+1,i+k-1,j+k-1)==4*n){
                REP(r,4*n+1){
                    if(p[r].F+1==i&&p[r].S+1>=j&&p[r].S+1<=j+k)continue;
                    if(p[r].F+1==i+k&&p[r].S+1>=j&&p[r].S+1<=j+k)continue;
                    if(p[r].S+1==j&&p[r].F+1>=i&&p[r].F+1<=i+k)continue;
                    if(p[r].S+1==j+k&&p[r].F+1>=i&&p[r].F+1<=i+k)continue;
                    W(p[r]);
                    return 0;
                }
            }
        }
    }
    return 0;
}