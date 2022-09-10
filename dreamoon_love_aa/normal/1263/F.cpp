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
const int SIZE = 1e6+10;
// 0-based
#define MAX_LV 19
VI e[SIZE];
int jump[MAX_LV+1][SIZE],lv[SIZE];
void __init(int x,int lt){
    jump[0][x]=lt;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y!=lt){
            lv[y]=lv[x]+1;
            __init(y,x);
        }
    }
}
int adv(int x,int v){
    for(int i=0;(1<<i)<=v;i++){
        if((v>>i)&1)x=jump[i][x];
    }
    return x;
}
int lca(int x,int y){
    if(lv[x]>lv[y])x=adv(x,lv[x]-lv[y]);
    else y=adv(y,lv[y]-lv[x]);
    if(x==y)return x;
    for(int i=MAX_LV;i>=0;i--)
        if(jump[i][x]!=jump[i][y]){x=jump[i][x];y=jump[i][y];}
    return jump[0][x];
}
int dis(int x,int y){
    int z=lca(x,y);
    return lv[x]+lv[y]-lv[z]*2;
}
void build(int root,int N){
    __init(root,root);
    REPP(i,1,MAX_LV+1){
        REP(x,N)
            jump[i][x]=jump[i-1][jump[i-1][x]];
    }
}
int r[SIZE][2];
int dp[1001][1001][2];
int main(){
    int n;R(n);
    int a; R(a);
    FOR(i,2,a){
        int x;R(x);
        e[x].PB(i);
        e[i].PB(x);
    }
    FOR(i,1,n)R(r[i][0]);
    int b; R(b);
    FOR(i,2,b){
        int x;R(x);
        x+=a;
        e[x].PB(i+a);
        e[i+a].PB(x);
    }
    FOR(i,1,n){
        R(r[i][1]);
        r[i][1]+=a;
    }
    e[0].PB(1);
    e[1].PB(0);
    e[0].PB(a+1);
    e[a+1].PB(0);
    build(0,a+b+1);
    FOR(i,0,n)FOR(j,0,n)REP(k,2)dp[i][j][k]=MOD;
    dp[1][0][0]=lv[r[1][0]]-1;
    dp[1][0][1]=lv[r[1][1]]-1;
    auto maa = [](auto& x,auto y){if(x>y)x=y;};
    REPP(i,1,n){
        REP(k,2){
            int z=lca(r[i][k],r[i+1][k]);
            int v=lv[r[i+1][k]]-lv[z];
            REP(j,i){
                maa(dp[i+1][j][k],dp[i][j][k]+v);
                if(!j){
                    maa(dp[i+1][i][k^1],dp[i][j][k]+lv[r[i+1][k^1]]-1);
                }
                else{
                    z=lca(r[i+1][k^1],r[j][k^1]);
                    maa(dp[i+1][i][k^1],dp[i][j][k]+lv[r[i+1][k^1]]-lv[z]);
                }
            }
        }
    }
    int an=MOD;
    REP(i,n)REP(j,2)maa(an,dp[n][i][j]);
    W(a+b-2-an);
    return 0;
}