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

const int SIZE = 5001;
map<int, int> AA;
LL C[SIZE][SIZE];
LL dp[SIZE][SIZE];
int n;
void solve() {
    int now=0;
    FOR(i,0,n)FOR(j,0,n/2)dp[i][j]=0;
    for(auto &[x,num]: AA){
        if(x==AA.begin()->F){
            if(num>1){
                W(0);
                return;
            }
            dp[num][num]=1;
            now=num;
            continue;
        }
        FOR(i,0,min(now,n/2)){
            int big=i;
            int small=now-i;
            if(big<=small)continue;
            if(big+num<=n/2&&num==1)ADD(dp[now+num][big+num],dp[now][big]);
            FOR(j,1,num){
                if(j<num-1)continue;
                if(big==n/2){
                    if(j==num){
                        ADD(dp[now+num][big],dp[now][i]*C[n/2-small][j]);
                        DEBUG("ADD3",dp[now+num][big],dp[now][i],C[n/2-small][j],n/2-small);
                        DEBUG("here",now+num,big,dp[now+num][big],dp[now][i]);
                    }
                }else{
                    if(j<big-small){
                        ADD(dp[now+num][big+num-j],dp[now][i]*C[big-small-1][j]);
                        DEBUG("ADD2",dp[now+num][big+num-j],dp[now][i]*C[big-small-1][j]);
                    }
                }
            }
        }
        now+=num;
        DEBUG(VL(dp[now],dp[now]+n/2+1));
    }
    W(dp[n][n/2]);
}
void input() {
    AA.clear();
    R(n);
    FOR(i,1,n){
        int x;
        R(x);
        AA[-x]++;
    }
}
int main(){
    MOD = 998244353;
    FOR(i,0,SIZE-1){
        C[i][0]=1;
        FOR(j,1,i){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
    CASET {
        input();
        solve();
    }
    return 0;
}