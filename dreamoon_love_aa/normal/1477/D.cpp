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
        while(!isdigit(ch)) ch = gc();
        while(isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
    }
} using io::read;
const int SIZE = 1<<20;
int n,m;
VI e[SIZE];
int deg[SIZE];
int an[2][SIZE];
int r[SIZE], rn;
int con[SIZE];
int sp[SIZE], sp_n;
bool update(int &x, int v){
    if(x < v) {
        x = v;
        return 1;
    }
    return 0;
}
void solve() {
    rn = 0;
    REP(i, n) {
        r[rn++] = i + 1;
    }
    while(rn) {
        int now_rn = rn;
        int ma_deg = -1;
        int x = - 1;
        REP(i,rn){
            if(update(ma_deg, deg[r[i]])) {
                x = r[i];
            }
        }
        con[x] = x;
        for(int y: e[x]) {
            con[y] = x;
        }
        sp_n = 0;
        int tmp_rn = 0;
        REP(i, rn) {
            if(con[r[i]] != x) {
                sp[sp_n++] = r[i];
                for(int y: e[r[i]]) {
                    deg[y]--;
                }
            } else {
                r[tmp_rn++] = r[i];
            }
        }
        rn = tmp_rn;
        int pos1 = now_rn;
        int pos2 = now_rn - sp_n;
        tmp_rn = 0;
        int now_deg = deg[x];
        REP(i, rn) {
            if(deg[r[i]] == now_deg) {
                an[0][r[i]] = pos1--;
                an[1][r[i]] = pos2--;
                now_deg--;
                for(int y:e[r[i]]) {
                    deg[y]--;
                }
            } else {
                r[tmp_rn++] = r[i];
            }
        }
        rn = tmp_rn;
        pos2 = now_rn;
        REP(i, sp_n) {
            an[0][sp[i]] = pos1--;
            an[1][sp[i]] = pos2--;
        }
    }
    REP(i,2){
        W(VI(an[i]+1,an[i]+n+1));
    }
}
void input() {
    read(n);
    read(m);
    FOR(i,1,n){
        VI tmp;
        e[i].swap(tmp);
        con[i] = 0;
    }
    REP(i,m){
        int x, y;
        read(x);
        read(y);
        e[x].PB(y);
        e[y].PB(x);
        deg[x]++;
        deg[y]++;
    }
}
int main(){
    int T;
    read(T);
    while(T--) {
        input();
        solve();
    }
    return 0;
}