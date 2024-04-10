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
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<20;
int n;
VPII e[SIZE];
VI AA[SIZE];
int xx[SIZE],yy[SIZE];
bool fail;
int deg[SIZE];
int dfs(int x, int lt){
    VI tmp[2];
    for(auto &[y, id]: e[x]){
        if(id==lt)continue;
        int ret=dfs(y,id);
        tmp[ret].PB(id);
    }
    int ret=0;
    if(lt!=-1){
        if(SZ(tmp[0])>(SZ(e[x])+1)/2){
            fail=1;
        }
        if(SZ(tmp[1])>SZ(e[x])/2){
            fail=1;
        }
        if(SZ(tmp[0])<(SZ(e[x])+1)/2){
            tmp[0].PB(lt);
        }else{
            tmp[1].PB(lt);
            ret=1;
        }
    }else{
        if(SZ(tmp[0])!=(SZ(e[x])+1)/2){
            fail=1;
        }
        if(SZ(tmp[1])!=SZ(e[x])/2){
            fail=1;
        }
    }
    if(fail)return ret;
    REP(i,SZ(tmp[0])){
        if(i<SZ(tmp[1])){
            deg[tmp[1][i]]++;
            AA[tmp[0][i]].PB(tmp[1][i]);
        }
        if(i+1<SZ(tmp[0])){
            deg[tmp[0][i+1]]++;
            AA[tmp[1][i]].PB(tmp[0][i+1]);
        }
    }
    return ret;
}
int bfs[SIZE];
void solve() {
    fail=0;
    FOR(i,1,n-1)deg[i]=0;
    dfs(1,-1);
    if(fail){
        W("NO");
        return;
    }
    W("YES");
    int bn=0;
    VPII an;
    FOR(i,1,n-1){
        if(!deg[i]){
            bfs[bn++]=i;
        }
    }
    REP(i,bn){
        an.PB({xx[bfs[i]],yy[bfs[i]]});
        for(int y: AA[bfs[i]]){
            deg[y]--;
            if(!deg[y]){
                bfs[bn++]=y;
            }
        }
    }
    reverse(ALL(an));
    for(auto &x: an)W(x);
}
void input() {
    R(n);
    REPP(i,1,n){
        int x,y;
        R(x,y);
        xx[i]=x;
        yy[i]=y;
        e[x].PB({y,i});
        e[y].PB({x,i});
    }
}
void my_clear(){
    FOR(i,1,n){
        VPII tmp;
        e[i].swap(tmp);
        VI tmp2;
        AA[i].swap(tmp2);
    }
}
int main(){
    CASET {
        input();
        solve();
        my_clear();
    }
    return 0;
}