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
const int SIZE = 52;
char s[SIZE][SIZE];
int dp[SIZE][SIZE];
int get(int x1,int y1,int x2,int y2){
    x1--;y1--;
    return dp[x2][y2]+dp[x1][y1]-dp[x1][y2]-dp[x2][y1];
}
int dp2[SIZE][SIZE][SIZE][SIZE];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int main(){
    int n,m;
    R(n);
    m=n;
    FOR(i,1,n){
        RS(s[i]+1);
        FOR(j,1,m){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(s[i][j]=='#');
        }
    }
    FOR(len1,1,n)FOR(len2,1,m){
        FOR(x1,1,n-len1+1)FOR(y1,1,m-len2+1){
            int x2=x1+len1-1;
            int y2=y1+len2-1;
            dp2[x1][y1][x2][y2]=max(len1,len2);
            FOR(i,x1,x2){
                if(!get(i,y1,i,y2))mii(dp2[x1][y1][x2][y2],dp2[x1][y1][i-1][y2]+dp2[i+1][y1][x2][y2]);
            }
            FOR(j,y1,y2){
                if(!get(x1,j,x2,j))mii(dp2[x1][y1][x2][y2],dp2[x1][y1][x2][j-1]+dp2[x1][j+1][x2][y2]);
            }
        }
    }
    W((int)dp2[1][1][n][m]);
    return 0;
}