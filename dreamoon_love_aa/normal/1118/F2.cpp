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
const int SIZE = 1<<19;
int a[SIZE];
VI e[SIZE];
VI col[SIZE];
int num_of_col;
int n,K;
int node_id,ll[SIZE];
// 0-based
#define MAX_LV 18
int jump[MAX_LV+1][SIZE],lv[SIZE];
void __init(int x,int lt){
    jump[0][x]=lt;
    ll[x]=++node_id;
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
void build_lca(int root,int N){
    __init(root,root);
    REPP(i,1,MAX_LV+1){
        FOR(x,1,N)
            jump[i][x]=jump[i-1][jump[i-1][x]];
    }
}
bool cmp(int x,int y){
    return ll[x]<ll[y];
}
void track(int x,int z,int id){
    while(x!=z){
        int y=jump[0][x];
        REP(i,2){
            if(a[y]&&a[y]!=id){
                W(0);
                exit(0);
            }
            a[y]=id;
        }
        x=y;
    }
}
void connect(int x,int y,int id){
    int z=lca(x,y);
    track(x,z,id);
    track(y,z,id);
}
LL dp[SIZE][2];
void cal_dfs(int x,int lt){
    if(a[x])dp[x][1]=1;
    else dp[x][0]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        cal_dfs(y,x);
        LL tmp[2]={};
        ADD(tmp[1],dp[x][1]*(dp[y][1]+dp[y][0]));
        ADD(tmp[1],dp[x][0]*dp[y][1]);
        ADD(tmp[0],dp[x][0]*dp[y][0]+dp[x][0]*dp[y][1]);
        REP(j,2)dp[x][j]=tmp[j];
    }
}
int main(){
    MOD=998244353;
    R(n,K);
    FOR(i,1,n){
        R(a[i]);
        col[a[i]].PB(i);
    }
    REPP(i,1,n){
        int x,y; R(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    build_lca(1,n);
    FOR(i,1,K){
        sort(ALL(col[i]),cmp);
        REPP(j,1,SZ(col[i])){
            int x=col[i][j-1];
            int y=col[i][j];
            connect(x,y,i);
        }
    }
    cal_dfs(1,1);
    W(dp[1][1]);
    return 0;
}