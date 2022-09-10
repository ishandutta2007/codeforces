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
const int SIZE = 2020;
LL l[SIZE],s[SIZE],c[SIZE*2],sum_c[SIZE*2];
const LL INF = 1e18;
auto maa = [](auto& x,auto y){if(x<y)x=y;};
LL dp[SIZE*2][SIZE];
int cnt[SIZE*2];
int main(){
    int n,m;
    R(n,m);
    FOR(i,1,n){
        R(l[i]);
        cnt[l[i]]++;
    }
    FOR(i,1,n+m){
        cnt[i+1]+=cnt[i]/2;
    }
    FOR(i,1,n)R(s[i]);
    FOR(i,1,n+m){
        R(c[i]);
    }
    FOR(i,1,n+m){
        FOR(j,1,cnt[i])dp[i][j]=-INF;
    }
    LL an=0;
    for(int i=n;i>0;i--){
        int v=l[i];
        for(int j=v;j>0;j--){
            for(int k=cnt[j];k>0;k--){
                if(dp[j][k]==-INF)continue;
                if(v==j)maa(dp[j][k+1],dp[j][k]+c[v]-s[i]);
                else {
                    LL ret=dp[j][k]+c[v]-s[i];
                    int lv=j;
                    int now=k;
                    while(lv<v&&now){
                        lv++;
                        now/=2;
                        ret+=now*c[lv];
                    }
                    maa(dp[v][1+now],ret);
                }
            }
        }
        maa(dp[v][1],c[v]-s[i]);
    }
    FOR(i,1,n+m){
        FOR(j,1,cnt[i]){
            if(dp[i][j]==-INF)continue;
            LL ret=dp[i][j];
            int lv=i;
            int now=j;
            while(now){
                lv++;
                now/=2;
                ret+=now*c[lv];
            }
            maa(an,ret);
        }
    }
    W(an);
    return 0;
}