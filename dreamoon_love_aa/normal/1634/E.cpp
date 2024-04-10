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
vector<pair<int, int>> e[SIZE];
int it[SIZE], deg[SIZE];
bitset<SIZE> used;
int m;
string an[SIZE];
VI a[SIZE];
PII tag[SIZE];
PII ee[SIZE];
void dfs(int x) {
    for(int &i = it[x]; i < SZ(e[x]); i++) {
        int eid=e[x][i].second;
        if(!used[eid]) {
            used[eid] = 1;
            if(ee[eid].F==x){
                an[ee[eid].F][tag[eid].F]='L';
                an[ee[eid].S][tag[eid].S]='R';
            }else{
                an[ee[eid].F][tag[eid].F]='R';
                an[ee[eid].S][tag[eid].S]='L';
            }
            dfs(e[x][i].first);
        }
    }
}
/*
void solve() {
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        e[a].PB(MP(b, i));
        e[b].PB(MP(a, i));
        deg[a] ^= 1;
        deg[b] ^= 1;
    }
    if(count(deg, deg + n + 1, 1)) {
         puts("IMPOSSIBLE");
    } else {
        dfs(1);
        if(SZ(answer) <= m) { puts("IMPOSSIBLE"); }
        else {
            for(int i = 0; i < SZ(answer); i++) {
                printf("%d%c", answer[i], " \n"[i == SZ(answer) - 1]);
            }
        }
    }
}
*/
void solve() {
    map<int,PII>pos;
    int en=0;
    REP(i,m){
        an[i].resize(SZ(a[i]));
        REP(j,SZ(a[i])){
            auto it=pos.find(a[i][j]);
            if(it!=pos.end()){
                int x=it->S.F;
                tag[en].F=it->S.S;
                int y=i;
                tag[en].S=j;
                if(x==y){
                    an[i][tag[en].F]='L';
                    an[i][tag[en].S]='R';
                }else{
                    ee[en]=MP(x,y);
                    e[x].PB(MP(y,en));
                    e[y].PB(MP(x,en));
                }
                en++;
                pos.erase(it);
            }else{
                pos[a[i][j]]=MP(i,j);
            }
        }
    }
    if(SZ(pos)){
        W("NO");
        return;
    }
    W("YES");
    REP(i,m){
        dfs(i);
    }
    REP(i,m)W(an[i]);
}
void input() {
    R(m);
    REP(i,m){
        int len;
        R(len);
        a[i].resize(len);
        for(int &x: a[i])R(x);
    }
}
int main(){
    input();
    solve();
    return 0;
}