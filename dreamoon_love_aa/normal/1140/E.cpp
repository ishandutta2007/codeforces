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
int k;
LL dp[SIZE][3];
LL go(int n,bool same){
    dp[0][0]=1;
    dp[0][1]=0;
    dp[0][2]=0;
    REP(i,n){
        dp[i+1][2]=(dp[i][2]*(k-3)+dp[i][1]*(k-2)+dp[i][0]*(k-2))%MOD;
        dp[i+1][0]=(dp[i][1]+dp[i][2])%MOD;
        dp[i+1][1]=(dp[i][0]+dp[i][2])%MOD;
    }
    if(same){
        return (dp[n][1]+dp[n][2])%MOD;
    }
    //W(n,"ker",(dp[n][0]+dp[n][2])%MOD);
    return (dp[n][0]+dp[n][2])%MOD;
}
LL solve(VI& AA){
    int ll=0;
    while(ll<SZ(AA)&&AA[ll]==-1)ll++;
    if(ll==SZ(AA)){
        LL an=k;
        REPP(i,1,SZ(AA))an=an*(k-1)%MOD;
        return an;
    }
    REPP(i,1,SZ(AA)){
        if(AA[i]==AA[i-1]&&AA[i]!=-1)return 0;
    }
    int rr=SZ(AA)-1;
    while(AA[rr]==-1)rr--;
    LL an=1;
    REP(i,ll)an=an*(k-1)%MOD;
    REP(i,SZ(AA)-1-rr)an=an*(k-1)%MOD;
    for(int i=ll,j;i<rr;i=j){
        for(j=i+1;j<rr&&AA[j]==-1;j++);
        an=an*go(j-i-1,AA[i]==AA[j])%MOD;
    }
    return an;
}
int main(){
    MOD=998244353;
    int n; R(n,k);
    VI a[2];
    FOR(i,1,n){
        int x; R(x);
        a[i&1].PB(x);
    }
    W(solve(a[0])*solve(a[1])%MOD);
    return 0;
}