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
const int SIZE = 1e6+10;
bool u[SIZE];
int AA[SIZE];
LL dp[128][128][128][2];
void update(LL& x,LL v){
    if(v==-1)return;
    if(x==-1||x>v)x=v;
}
void solve(){
    int n; R(n);
    FOR(i,1,n){
        R(AA[i]);
        u[AA[i]]=1;
    }
    int cnt[2]={};
    FOR(i,1,n){
        if(!u[i]){
            cnt[i&1]++;
        }
    }
    MS1(dp);
    dp[0][0][0][0]=dp[0][0][0][1]=0;
    int zero_cnt=0;
    FOR(i,1,n){
        FOR(j,0,zero_cnt){
            REP(k,2){
                if(dp[i-1][j][zero_cnt-j][k]==-1)continue;
                if(AA[i]==0){
                    update(dp[i][j+1][zero_cnt-j][1],dp[i-1][j][zero_cnt-j][k]+(1!=k));
                    update(dp[i][j][zero_cnt-j+1][0],dp[i-1][j][zero_cnt-j][k]+(0!=k));
                }
                else{
                    update(dp[i][j][zero_cnt-j][AA[i]&1],dp[i-1][j][zero_cnt-j][k]+(k!=(AA[i]&1)));
                }
            }
        }
        if(AA[i]==0)zero_cnt++;
    }
    LL an=-1;
    REP(i,2)update(an,dp[n][cnt[1]][cnt[0]][i]);
    W(an);
}
int main(){
    solve();
    return 0;
}