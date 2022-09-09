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
const int SIZE = 1<<18;
int e[20],w[20],w_sum[SIZE];
int cover[SIZE];
bitset<SIZE>valid_state,valid_group;
int n,m;
int get_bit(int x,int v){return (x>>v)&1;}
int dp[SIZE],from[SIZE];
bool update(int &x,int v){
    if(x>v){
        x=v;
        return 1;
    }
    return 0;
}
int an[20];
int track(int x){
    if(!x)return 20;
    int y=from[x];
    int v=track(y)-1;
    REP(i,n){
        if(get_bit(x,i)&&!get_bit(y,i))an[i]=v;
    }
    return v;
}
void solve() {
    int mask=(1<<n)-1;
    REP(i,1<<n){
        REP(j,n){
            if(get_bit(i,j)){
                w_sum[i]+=w[j];
                cover[i]|=e[j];
            }
        }
        if((cover[i]&i)==cover[i])valid_state[i]=1;
        if(!(cover[i]&i))valid_group[i]=1;
    }
    REP(i,1<<n){
        dp[i]=MOD;
    }
    dp[0]=0;
    REP(i,1<<n){
        int ss=mask^i;
        if(dp[i]==MOD)continue;
        for(int j=ss;;j=(j-1)&ss){
            if(valid_group[j]&&valid_state[i|j]&&update(dp[i|j],dp[i]+w_sum[mask^i])){
                from[i|j]=i;
            }
            if(!j)break;
        }
    }
    track(mask);
    W(VI(an,an+n));
}
void input() {
    R(n,m);
    REP(i,m){
        int x,y,v;
        R(x,y,v);
        x--;y--;
        e[y]|=1<<x;
        w[y]+=v;
        w[x]-=v;
    }
}
int main(){
    input();
    solve();
    return 0;
}