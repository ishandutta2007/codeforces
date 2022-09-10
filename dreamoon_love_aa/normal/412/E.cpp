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
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
int dp[5][SIZE],nxt[SIZE];
char s[SIZE];
int get(int x,int l,int r){
    return dp[x][r]-dp[x][l-1];
}
int main(){
    RS(s+1);
    int n=LEN(s+1);
    nxt[n+1]=n+1;
    FOR(i,1,n){
        REP(j,5)dp[j][i]=dp[j][i-1];
        if(s[i]=='@')dp[0][i]++;
        else if(s[i]=='.')dp[1][i]++;
        else if(s[i]=='_')dp[2][i]++;
        else if(s[i]>='0'&&s[i]<='9')dp[3][i]++;
        else dp[4][i]++;
    }
    for(int i=n;i>0;i--){
        nxt[i]=nxt[i+1];
        if(s[i]=='.')nxt[i]=i;
    }
    LL an=0;
    FOR(i,1,n){
        if(s[i]=='@'){
            int ll=1,rr=i;
            while(ll<rr){
                int mm=(ll+rr)/2;
                if(get(2,mm,i-1)+get(3,mm,i-1)+get(4,mm,i-1)==i-mm){
                    rr=mm;
                }
                else ll=mm+1;
            }
            LL lv=get(4,ll,i);
            int dot=nxt[i];
            ll=dot,rr=n;
            if(ll==n+1||dot==i+1)continue;
            if(get(3,i+1,ll-1)+get(4,i+1,ll-1)!=ll-i-1)continue;
            while(ll<rr){
                int mm=(ll+rr+1)/2;
                if(get(4,dot+1,mm)==mm-dot)ll=mm;
                else rr=mm-1;
            }
            an+=lv*(ll-dot);
        }
    }
    W(an);
    return 0;
}