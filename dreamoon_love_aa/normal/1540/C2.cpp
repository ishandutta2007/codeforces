#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const int SIZE = 10001;
int c[SIZE],b[SIZE];
int n;
int dp[SIZE];
LL bk_num[SIZE];
bitset<SIZE> u;
int answer[SIZE];
void my_add(int &x, int v){
    x += v;
    if(x >=MOD)x-=MOD;
}
void my_sub(int &x, int v){
    x -= v;
    if(x<0)x+=MOD;
}
namespace io {
    const int SIZE = 1e7 + 10;
    char inbuff[SIZE];
    char *l, *r;
    inline void init() {
        l = inbuff;
        r = inbuff + fread(inbuff, 1, SIZE, stdin);
    }
    inline char gc() {
        if (l == r) init();
        return (l != r) ? *(l++) : EOF;
    }
    void read(int &x) {
        x = 0; char ch = gc();
        while(!isdigit(ch) && ch !='-') ch = gc();
        bool neg = 0;
        if(ch == '-') { neg = 1; ch = gc(); }
        while(isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
        if(neg) { x = -x; }
    }
} using io::read;
void solve() {
    int q;
    read(q);
    bk_num[n]=1;
    for(int i=n-1;i>=0;i--){
        bk_num[i]=bk_num[i+1]*(c[i+1]+1)%MOD;
    }
    while(q--){
        int x;
        read(x);
        if(x<=-5000){
            W(bk_num[0]);
            continue;
        }
        if(x>100){
            W(0);
            continue;
        }
        if(u[x+5000]){
            W(answer[x+5000]);
            continue;
        }
        u[x+5000]=1;
        int an=0;
        int sb=0;
        int d=0;
        memset(dp,0,sizeof(int)*(n*100+1));
        int low=0;
        int now=0;
        dp[0]=1;
        FOR(i,1,n){
            while(low<=now&&!dp[low]){low++;}
            if(low>now){break;}
            for(int j=now;j>=low;j--){
                int me=dp[j];
                dp[j]=0;
                int small_k=min(i*x+d-j,c[i]+1);
                if(small_k>0){
                        an=(an+bk_num[i]*me%MOD*small_k)%MOD;
                        my_add(dp[j+small_k],me);
                        my_sub(dp[j+c[i]+1],me);

                }else{
                    my_add(dp[j],me);
                    my_sub(dp[j+c[i]+1],me);
                }
            }
            now+=c[i];
            FOR(j,low,now){
                my_add(dp[j+1],dp[j]);
            }
            sb+=b[i];
            d+=sb;
        }
        an=bk_num[0]-an;
        an%=MOD;
        if(an<0)an+=MOD;
        answer[x+5000]=an;
        W(an);
    }
}
void input() {
    read(n);
    FOR(i,1,n)read(c[i]);
    FOR(i,1,n-1)read(b[i]);
}
int main(){
    input();
    solve();
    return 0;
}