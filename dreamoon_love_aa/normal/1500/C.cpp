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
const int SIZE = 1<<11;
int n,m;
VI a[SIZE], b[SIZE];
int d[2][SIZE];
bool cmp_a(int x, int y) {
    return a[x] < a[y];
}
bool cmp_b(int x, int y) {
    return b[x] < b[y];
}
int cnt[SIZE];
bitset<SIZE> used,col_used;
void make(int id){
    used[id]=1;
    REP(j,m+1){
        if(b[id][j] < b[id-1][j]){
            cnt[j]--;
        }
    }
}
void solve() {
    REP(i,n)d[0][i]=d[1][i]=i;
    stable_sort(d[0],d[0]+n,cmp_a);
    stable_sort(d[1],d[1]+n,cmp_b);
    REP(i,n){
        if(a[d[0][i]]!=b[d[1][i]]){
            W(-1);
            return;
        }
    }
    REP(i,n){
        a[i].PB(i);
    }
    REP(i,n){
        b[d[1][i]].PB(d[0][i]);
    }
    REPP(i,1,n){
        REP(j,m+1){
            if(b[i][j] < b[i-1][j]){
                cnt[j]++;
            }
        }
    }
    VI an;
    bool changed=1;
    while(cnt[m]>0&&changed) {
        changed=0;
        REP(i,m){
            if(!cnt[i] && !col_used[i]) {
                col_used[i]=1;
                changed=1;
                an.PB(i+1);
                REPP(j,1,n){
                    if(!used[j]&&b[j][i]>b[j-1][i]){
                        make(j);
                    }
                }
                break;
            }
        }
    }
    if(cnt[m]){
        W(-1);
        return;
    }
    W(SZ(an));
    reverse(ALL(an));
    W(an);
}
void input() {
    R(n,m);
    REP(i,n){
        a[i].resize(m);
        REP(j,m)R(a[i][j]);
    }
    REP(i,n){
        b[i].resize(m);
        REP(j,m)R(b[i][j]);
    }
}
int main(){
    input();
    solve();
    return 0;
}