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
int dp[77][77],from[77][77];
bool update(int &x,int v){
    if(x<v){
        x=v;
        return 1;
    }
    return 0;
}
void solve(){
    int n,k;
    R(n,k);
    vector<pair<PII,int>> pp;
    REP(i,n){
        int a,b;
        R(a,b);
        pp.PB(MP(MP(b,a),i+1));
    }
    sort(ALL(pp));
    MS1(dp);
    dp[0][0]=0;
    REP(i,SZ(pp)){
        FOR(j,0,min(k,i)){
            if(j<k){
                if(update(dp[j+1][i-j],dp[j][i-j]+pp[i].F.S+pp[i].F.F*j)){
                    from[j+1][i-j]=0;
                }
            }
            if(update(dp[j][i-j+1],dp[j][i-j]+pp[i].F.F*(k-1))){
                from[j][i-j+1]=1;
            }
        }
    }
    int now=k;
    VI res[2];
    for(int i=SZ(pp);i>0;i--){
        res[from[now][i-now]].PB(pp[i-1].S);
        if(!from[now][i-now])now--;
    }
    reverse(ALL(res[0]));
    VI an;
    REP(i,SZ(res[0])-1)an.PB(res[0][i]);
    REP(i,SZ(res[1])){
        an.PB(res[1][i]);
        an.PB(-res[1][i]);
    }
    an.PB(res[0].back());
    W(SZ(an));
    W(an);
}
int main(){
    CASET{
        solve();
    }
    return 0;
}