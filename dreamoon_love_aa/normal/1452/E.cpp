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
int l[SIZE],r[SIZE];
int n,m,k;
int inter(int x1,int y1,int x2,int y2){
    if(y1<x2||y2<x1)return 0;
    return min(y2,y1)-max(x1,x2)+1;
}
int dp[SIZE][2];
void add(int h,int ll,int rr,int v){
    if(ll<1)ll=1;
    if(rr>n-k+1)rr=n-k+1;
    dp[ll][0]+=h-v;
    dp[rr+1][0]-=h-v;
    if(ll>1){
        int st=ll-(h-v);
        dp[max(1,st)][1]++;
        dp[ll][1]--;
        dp[max(1,st)][0]-=st;
        dp[ll][0]+=st;
    }
    {
        int ed=rr+(h-v);
        dp[rr+1][1]--;
        if(ed<=n-k+1)dp[ed][1]++;
        dp[rr+1][0]+=(h-v-1)+(rr+1);
        if(ed<=n-k+1)dp[ed][0]-=(h-v-1)+(rr+1);
    }
}
void solve() {
    int an=0;
    int rr=n-k+1;
    FOR(x,1,rr){
        int base=0;
        FOR(i,0,n)REP(j,2)dp[i][j]=0;
        REP(i,m){
            int v=inter(x,x+k-1,l[i],r[i]);
            base+=v;
            if(v==min(r[i]-l[i]+1,k))continue;
            if(k<=r[i]-l[i]+1){
                add(k,l[i],r[i]-k+1,v);
            }else{
                add(r[i]-l[i]+1,r[i]-k+1,l[i],v);
            }
        }
        FOR(y,1,rr){
            REP(j,2)dp[y][j]+=dp[y-1][j];
            an=max(an,base+dp[y][0]+dp[y][1]*y);
        }
    }
    W(an);
}
void input() {
    R(n,m,k);
    REP(i,m)R(l[i],r[i]);
}
int main(){
    input();
    solve();
    return 0;
}