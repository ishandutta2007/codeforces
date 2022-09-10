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
const int SIZE = 1010;
char s[SIZE],t[SIZE];
int nxt[SIZE][26];
int dp[SIZE][SIZE];
void update(int &x,int v){
    if(x==-1||x>v)x=v;
}
bool good(int n,char t1[],char t2[],int x,int y){
    FOR(i,0,x)FOR(j,0,y)dp[i][j]=-1;
    dp[0][0]=1;
    FOR(i,0,x)FOR(j,0,y){
        if(dp[i][j]>=0){
            int v=dp[i][j];
            if(i+1<=x&&nxt[v][t1[i+1]-'a']<=n){
                update(dp[i+1][j],nxt[v][t1[i+1]-'a']+1);
            }
            if(j+1<=y&&nxt[v][t2[j+1]-'a']<=n){
                update(dp[i][j+1],nxt[v][t2[j+1]-'a']+1);
            }
        }
        else return 0;
    }
    return 1;
}
void solve(){
    RS(s+1);
    RS(t+1);
    int n=LEN(s+1);
    int m=LEN(t+1);
    REP(j,26)nxt[n+1][j]=n+1;
    for(int i=n;i>0;i--){
        REP(j,26)nxt[i][j]=nxt[i+1][j];
        nxt[i][s[i]-'a']=i;
    }
    if(m==1){
        bool suc=0;
        FOR(i,1,n){
            if(s[i]==t[1]){
                suc=1;
            }
        }
        W(suc?"YES":"NO");
        return;
    }
    FOR(i,1,m){
        if(good(n,t,t+i,i,m-i)){
            W("YES");
            return;
        }
    }
    W("NO");
}
int main(){
    CASET{solve();}
    return 0;
}