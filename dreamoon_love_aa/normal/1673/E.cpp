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

const int SIZE = (1<<20)+1;
int dp[24][SIZE],n,k;
int B[SIZE];
void pre(){
    REP(i,24){
        FOR(j,0,n-i){
            if((j&(n-i))==j)dp[i][j]=1;
        }
        for(int j=n-i-1;j>=0;j--)dp[i][j]^=dp[i][j+1];
    }
}
int an[SIZE];
void print(){
    int st=0;
    for(int i=SIZE-2;i>=0;i--){
        if(an[i])st=1;
        if(st)_W(an[i]);
    }
    if(!st)_W(0);
    W("");
}
void solve() {
    if(n==1){
        an[B[1]]=1;
        print();
        return;
    }
    FOR(i,1,n){
        LL me=B[i];
        if(i==1||i==n)an[me]^=dp[2][max(0,k-1)];
        else an[me]^=dp[3][max(0,k-2)];
        for(int j=i+1;j<=n;j++){
            if(B[j]>20)break;
            me<<=B[j];
            if(me>=SIZE)break;
            if(i==1&&j==n){
                if(k==0) an[me]^=1;
            }
            else if(i==1||j==n) an[me]^=dp[j-i+2][max(0,k-1)];
            else an[me]^=dp[j-i+3][max(0,k-2)];
        }
    }
    print();
}
void input() {
    R(n,k);
    pre();
    FOR(i,1,n)R(B[i]);
}
int main(){
    input();
    solve();
    return 0;
}