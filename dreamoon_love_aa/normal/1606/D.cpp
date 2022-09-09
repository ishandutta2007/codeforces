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
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<20;
int n,m;
vector<vector<int>> a;
const int LEFT = 0;
const int RIGHT = 1;
const int DOWN = 0;
const int UP = 1;
void check_min(int &x, int v){
    x=min(x,v);
}
void check_max(int &x, int v){
    x=max(x,v);
}
void solve() {
    VPII AA;
    REP(i,n){
        AA.PB(a[i][0],i);
    }
    sort(ALL(AA),greater<PII>());
    vector<vector<int>> dp[2][2];
    REP(i,2)REP(j,2){
        dp[i][j].assign(n,vector<int>(m));
    }
    REP(i,n){
        REP(j,m){
            REP(k1,2)REP(k2,2)dp[k1][k2][i][j]=a[AA[i].S][j];
            if(i)check_min(dp[LEFT][DOWN][i][j],dp[LEFT][DOWN][i-1][j]);
            if(j)check_min(dp[LEFT][DOWN][i][j],dp[LEFT][DOWN][i][j-1]);
        }
    }
    REP(i,n){
        for(int j=m-1;j>=0;j--){
            if(i)check_max(dp[RIGHT][DOWN][i][j],dp[RIGHT][DOWN][i-1][j]);
            if(j+1<m)check_max(dp[RIGHT][DOWN][i][j],dp[RIGHT][DOWN][i][j+1]);
        }
    }
    for(int i=n-1;i>=0;i--){
        REP(j,m){
            if(i+1<n)check_max(dp[LEFT][UP][i][j],dp[LEFT][UP][i+1][j]);
            if(j)check_max(dp[LEFT][UP][i][j],dp[LEFT][UP][i][j-1]);
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i+1<n)check_min(dp[RIGHT][UP][i][j],dp[RIGHT][UP][i+1][j]);
            if(j+1<m)check_min(dp[RIGHT][UP][i][j],dp[RIGHT][UP][i][j+1]);
        }
    }
    REP(i,n-1){
        int ll=-1,rr=m-2;
        while(ll<rr){
            int mm=ll+(rr-ll+1)/2;
            if(dp[LEFT][DOWN][i][mm]>dp[LEFT][UP][i+1][mm])ll=mm;
            else rr=mm-1;
        }
        if(ll==-1)continue;
        if(dp[RIGHT][UP][i+1][ll+1]>dp[RIGHT][DOWN][i][ll+1]){
            W("YES");
            string an(n,'B');
            REP(g,i+1){
                an[AA[g].S]='R';
            }
            W(an,ll+1);
            return;
        }
    }
    W("NO");
}
void input() {
    R(n,m);
    a.assign(n,vector<int>(m));
    REP(i,n)REP(j,m)R(a[i][j]);
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}