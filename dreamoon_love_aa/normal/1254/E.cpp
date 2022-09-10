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
void fail(){
    W(0);
    exit(0);
}
LL fac[SIZE];
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
VPII ord[SIZE];
int st[SIZE],ed[SIZE];
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){return (x!=d[x])?(d[x]=find(d[x])):x;}
    bool is_root(int x){return d[x]==x;}
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        d[x]=y;
        return 1;
    }
}U;
bool check(VPII &gg){
    VI tmp;
    VI d;
    REP(i,SZ(gg)){
        tmp.PB(gg[i].S);
        d.PB(gg[i].S);
        d.PB(gg[i].F);
        if(i&&gg[i].F==gg[i-1].F)fail();
    }
    SORT_UNIQUE(tmp);
    if(SZ(tmp)!=SZ(gg))fail();
    SORT_UNIQUE(d);
    U.init(SZ(d));
    REP(i,SZ(gg)){
        int x=GET_POS(d,gg[i].F);
        int y=GET_POS(d,gg[i].S);
        if(!U.uu(x,y)){
            fail();
        }
    }
    return SZ(d)&&d[0]==-1&&d.back()==MOD&&U.find(0)==U.find(SZ(d)-1);
}
LL solve(int x){
    if(st[x]!=-1)ord[x].PB(MP(-1,st[x]));
    if(ed[x]!=-1)ord[x].PB(MP(ed[x],MOD));
    if(st[x]==ed[x]&&st[x]!=-1&&SZ(e[x])>1)fail();
    SORT_UNIQUE(ord[x]);
    if(check(ord[x])){
        if(SZ(e[x])+1!=SZ(ord[x]))fail();
    }
    return fac[max(SZ(e[x])-SZ(ord[x]),0)];
}
void assign(int &x,int v){
    if(x==v||x==-1){
        x=v;
    }
    else{
        fail();
    }
}
int dp[2][SIZE];
void dfs(int x,int lt){
    for(int y:e[x]){
        if(y==lt)continue;
        dfs(y,x);
        REP(j,2)dp[j][x]+=dp[j][y];
    }
    if(dp[0][x]&&dp[1][x]){
        fail();
    }
    if(dp[0][x]){
        ord[lt].PB(MP(x, jump[0][lt]));
    }
    if(dp[1][x]){
        ord[lt].PB(MP(jump[0][lt], x));
    }
}
int main(){
    fac[0]=1;
    REPP(i,1,SIZE){
        fac[i]=fac[i-1]*i%MOD;
    }
    MS1(st);
    MS1(ed);
    int n; R(n);
    REPP(i,1,n){
        int x,y;
        R(x,y);
        x--;y--;
        e[x].PB(y);
        e[y].PB(x);
    }
    build(0,n);
    REP(y,n){
        int x; R(x);
        if(x){
            x--;
            if(x==y)fail();
            int z=lca(x,y);
            if(z!=x)assign(st[x],jump[0][x]);
            else assign(st[x],adv(y,lv[y]-lv[x]-1));

            if(z!=y)assign(ed[y],jump[0][y]);
            else assign(ed[y],adv(x,lv[x]-lv[y]-1));
            
            if(z!=x && z!=y) {
                ord[z].PB(MP(adv(x,lv[x]-lv[z]-1),adv(y,lv[y]-lv[z]-1)));
            }
            if(lv[x]>lv[z]+1){
                int w=adv(x,lv[x]-lv[z]-1);
                dp[0][x]++;
                dp[0][w]--;
            }
            if(lv[y]>lv[z]+1){
                int w=adv(y,lv[y]-lv[z]-1);
                dp[1][y]++;
                dp[1][w]--;
            }
        }
    }
    dfs(0,0);
    LL an=1;
    REP(i,n){
        an=an*solve(i)%MOD;
    }
    W(an);
    return 0;
}