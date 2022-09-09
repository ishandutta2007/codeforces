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
// 0-based
#define MAX_LV 19
const int SIZE = 1 << MAX_LV;
vector<int> e[SIZE];
int jump[2][SIZE], lv[SIZE], rn[SIZE];
void __init(int x,int lt) {
    jump[0][x] = lt;
    for(int y: e[x]) {
        if(y != lt) {
            rn[x]++;
            lv[y] = lv[x] + 1;
            __init(y, x);
        }
    }
}
int adv(int x,int v){
    for(int i = 0; v >> i; i++) {
        if((v >> i) & 1) { 
            x = jump[i][x];
        }
    }
    return x;
}
int lca(int x, int y) {
    if(lv[x] > lv[y]) { x = adv(x,lv[x] - lv[y]); }
    else { y = adv(y, lv[y] - lv[x]); }
    if(x == y) { return x; }
    for(int i = MAX_LV; i >= 0; i--) {
        if(jump[i][x] != jump[i][y]) {
            x = jump[i][x];
            y = jump[i][y];
        }
    }
    return jump[0][x];
}
int dis(int x, int y) {
    int z = lca(x, y);
    return lv[x] + lv[y] - lv[z] * 2;
}
void build(int root) {
    __init(root, root);
}
int n;
int a[SIZE],p[SIZE];
bool cmp(int x, int y){
    return a[x] < a[y];
}
int gg[SIZE],gid;
void dfs(int x, int lt){
    gg[x]=++gid;
    for(int y: e[x]) {
        if(y == lt){continue;}
        dfs(y,x);
    }
}
bitset<SIZE>u;
void check_dfs(int x, int lt,int &now){
    if(u[x])return;
    DEBUG(x,a[x],now);
    if(a[x]!=now){
        W("NO");
        exit(0);
        return;
    }
    now++;
    for(int y: e[x]) {
        if(y==lt){continue;}
        check_dfs(y,x,now);
    }
}
int res[SIZE],res_id;
void dfs_final(int x, int lt){
    res[x]=++res_id;
    for(int y: e[x]){
        if(y==lt){continue;}
        dfs_final(y,x);
    }
}
void solve() {
    LL an=0;
    REP(i,n){
        sort(ALL(e[i]),cmp);
    }
    dfs(0,0);
    build(0);
    priority_queue<PII,VPII,greater<PII>>pq;
    REP(i,n){
        if(!rn[i]){
            pq.push(MP(gg[i],i));
        }
    }
    int st=n;
    REP(i,n){
        assert(!pq.empty());
        auto now=pq.top();
        pq.pop();
        an+=lv[now.S];
        u[now.S]=1;
        if(a[now.S]==i){
            int pa=jump[0][now.S];
            rn[pa]--;
            if(!rn[pa]){
                pq.push(MP(gg[pa],pa));
            }
        } else {
            int x=now.S;
            int tmp=i;
            DEBUG("go",x);
            while(a[x]!=i){
                if(!x){
                    W("NO");
                    return;
                }
                swap(tmp,a[x]);
                an--;
                x=jump[0][x];
            }
            a[x]=tmp;
            st=i+1;
            break;
        }
    }
    DEBUG("here");
    check_dfs(0,0,st);
    W("YES");
    W(an);
    dfs_final(0,0);
    W(VI(res,res+n));
}
void input() {
    R(n);
    REP(i,n){
        R(a[i]);
        a[i]--;
        p[a[i]]=i;
    }
    FOR(i,1,n-1){
        int x,y;
        R(x,y);
        x--;y--;
        e[x].PB(y);
        e[y].PB(x);
    }
}
int main(){
    input();
    solve();
    return 0;
}