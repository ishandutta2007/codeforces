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

const int SIZE = 2020;
int n;
char s[2][SIZE];
int dp[SIZE*2][SIZE*2],tmp[SIZE*2][SIZE*2];
void my_add(int &x,int v){
    x+=v;
    if(x>=MOD)x-=MOD;
}
void add(int id,int v){
    FOR(i,-n,n){
        if(!dp[id-1][i+SIZE])continue;
        int nxt=i+SIZE+v;
        if(nxt<SIZE-n||nxt>SIZE+n)continue;
        my_add(dp[id][nxt],dp[id-1][i+SIZE]);
    }
}
void solve() {
    FOR(i,0,2*n)FOR(j,-n,n){
        dp[i][j+SIZE]=0;
    }
    FOR(i,1,n){
        if(i&1){
            REP(j,2){
                if(s[j][i]!='?')s[j][i]^=1;
            }
        }
    }
    dp[0][SIZE]=1;
    FOR(i,1,n){
        FOR(c,0,1){
            if(c+'0'==s[0][i]||s[0][i]=='?'){
                add(i*2-1,c);
            }
        }
        FOR(c,0,1){
            if(c+'0'==s[1][i]||s[1][i]=='?'){
                add(i*2,-c);
            }
        }
    }
    REP(i,2){
        reverse(s[i]+1,s[i]+n+1);
    }
    FOR(i,0,2*n)FOR(j,-n,n){
        tmp[i][j+SIZE]=dp[i][j+SIZE];
        dp[i][j+SIZE]=0;
    }
    dp[0][SIZE]=1;
    LL an=0;
    FOR(i,1,n){
        FOR(c,0,1){
            if(c+'0'==s[0][i]||s[0][i]=='?'){
                add(i*2-1,c);
            }
        }
        FOR(c,0,1){
            if(c+'0'==s[1][i]||s[1][i]=='?'){
                add(i*2,-c);
            }
        }
        if(i<n){
            FOR(j,-n,n){
                //DEBUG(i,j,dp[i*2][SIZE+j],tmp[n-i][SIZE-j]);
                ADD(an,(LL)dp[i*2][SIZE+j]*tmp[(n-i)*2][SIZE-j]%MOD*abs(j));
            }
        }
    }
    W(an);
}
void input() {
    R(n);
    RS(s[0]+1);
    RS(s[1]+1);
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}