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
LL dp[888][888],res[1000000];
int main(){
    int n,m,k;
    R(n,m,k);
    vector<pair<int,PII>>d;
    REP(i,m){
        int x,y,v;
        R(x,y,v);
        d.PB(MP(v,MP(x,y)));
    }
    VI ids;
    sort(ALL(d));
    REP(i,min(SZ(d),k)){
        ids.PB(d[i].S.F);
        ids.PB(d[i].S.S);
    }
    SORT_UNIQUE(ids);
    REP(i,SZ(ids))REP(j,SZ(ids))dp[i][j]=1e18;
    REP(i,min(SZ(d),k)){
        d[i].S.F=GET_POS(ids,d[i].S.F);
        d[i].S.S=GET_POS(ids,d[i].S.S);
    }
    REP(i,min(SZ(d),k)){
        dp[d[i].S.F][d[i].S.S]=d[i].F;
        dp[d[i].S.S][d[i].S.F]=d[i].F;
    }
    REP(k,SZ(ids))REP(i,SZ(ids))REP(j,SZ(ids)){
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    }
    m=0;
    REP(i,SZ(ids))REP(j,i)res[m++]=dp[i][j];
    nth_element(res,res+k-1,res+m);
    W(res[k-1]);
    return 0;
}