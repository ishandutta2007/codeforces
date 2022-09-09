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
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<20;
int a[SIZE];
int n,m;
int u[SIZE],tt;
bool bi;
VI e[SIZE];
int v[SIZE];
VI p[2];
void dfs(int x){
    u[x]=tt;
    p[v[x]].PB(x);
    for(int y:e[x]){
        if(u[y]==tt){
            if(v[y]==v[x]){
                bi=0;
            }
        }else{
            v[y]=v[x]^1;
            dfs(y);
        }
    }
}
void solve() {
    tt++;
    FOR(i,1,n){
        if(u[i]!=tt){
            v[i]=0;
            bi=1;
            REP(j,2)p[j].clear();
            dfs(i);
            if(!bi){
                int s=0;
                REP(j,2){
                    for(int x:p[j]){
                        s^=a[x]&1;
                    }
                }
                if(s){
                    W("NO");
                    return;
                }
            }else{
                LL s[2]={};
                REP(j,2){
                    for(int x:p[j]){
                        s[j]+=a[x];
                    }
                }
                if(s[0]!=s[1]){
                    W("NO");
                    return;
                }
            }
        }
    }
    W("YES");
}
void input() {
    R(n,m);
    FOR(i,1,n){
        R(a[i]);
    }
    FOR(i,1,n)e[i].clear();
    FOR(i,1,n){
        int x;
        R(x);
        a[i]=x-a[i];
    }
    REP(i,m){
        int x ,y;
        R(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}