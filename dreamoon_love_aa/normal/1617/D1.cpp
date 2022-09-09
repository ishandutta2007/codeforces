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
#include<iomanip>
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
#define CASET int ___T; cin >> ___T; for(int cs=1;cs<=___T;cs++)
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
template<class T,class U> void _R(pair<T,U> &x) {cin >> x.F >> x.S;}
void R() {}
template<class T, class... U> void R(T &head, U &... tail) {_R(head); R(tail...);}
template<class T> void _W(const T &x) {cout << x;}
void _W(const double &x) {cout << fixed << setprecision(16) << x;}
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); cout << ' '; _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) cout << ' '; }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); cout << (sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {cout << "[DEBUG] "; W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
int n;
int qq(int x, int y, int z) {
    W("?", x, y , z);
    fflush(stdout);
    int v;
    R(v);
    return v;
}
void solve() {
    int h[2] = {};
    VI ty(n + 1);
    for(int i = 1; i < n; i += 3) {
        int v = qq(i, i + 1, i + 2);
        if(!h[v]) h[v] = i;
        ty[i] = v;
    }
    int zero_guy, one_guy;
    if(qq(h[0] + 1, h[0] + 2, h[1])) {
        zero_guy = h[0];
        one_guy = h[1];
    } else if(qq(h[0] + 2, h[1], h[1] + 1)) {
        zero_guy = h[0] + 1;
        one_guy = h[1] + 1;
    } else {
        zero_guy = h[0] + 2;
        one_guy = h[1] + 2;
    }
    VI res(n + 1);
    res[one_guy] = 1;
    VI an;
    REP(i, 3) {
        if(h[0] + i != zero_guy) {
            res[h[0] + i] = qq(h[0] + i, one_guy, zero_guy);
        }
        if(h[1] + i != one_guy) {
            res[h[1] + i] = qq(h[1] + i, one_guy, zero_guy);
        }
    }
    for(int i = 1; i < n; i += 3) {
        if((i - 1) / 3 == (one_guy - 1) / 3 || (i - 1) / 3 == (zero_guy - 1) / 3) continue;
        if(ty[i]) {
            int v = qq(i, i + 1, zero_guy);
            if(v) {
                res[i] = res[i + 1] = 1;
                res[i + 2] = qq(i + 2, zero_guy, one_guy);
            } else {
                res[i + 2] = 1;
                v = qq(i, one_guy, zero_guy);
                res[i] = v;
                res[i + 1] = v ^ 1;
            }
        } else {
            int v = qq(i, i + 1, one_guy);
            if(!v) {
                res[i] = res[i + 1] = 0;
                res[i + 2] = qq(i + 2, zero_guy, one_guy);
            } else {
                res[i + 2] = 0;
                v = qq(i, one_guy, zero_guy);
                res[i] = v;
                res[i + 1] = v ^ 1;
            }
        }
    }
    FOR(i, 1, n) {
        if(!res[i]) an.PB(i);
    }
    W("!", SZ(an), an);
}
void input() {
    R(n);
}
int main(){
    ios_base::sync_with_stdio(false);
    CASET {
        input();
        solve();
    }
    return 0;
}