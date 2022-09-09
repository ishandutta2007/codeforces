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
map<VI,int>AA;
int n;
int qq(VI x){
    sort(ALL(x));
    if(AA.count(x)) return AA[x];
    W("?",x[0],x[1],x[2]);
    fflush(stdout);
    int v;
    R(v);
    AA[x]=v;
    return v;
}
void solve() {
    AA.clear();
    VPII dd;
    dd.PB(MP(qq({2,3,4}),1));
    dd.PB(MP(qq({1,3,4}),2));
    dd.PB(MP(qq({1,2,4}),3));
    dd.PB(MP(qq({1,2,3}),4));
    sort(ALL(dd));
    map<int,int>cnt;
    REPP(i,2,4)FOR(j,1,4)if(dd[i].S!=j)cnt[j]++;
    VI st;
    for(auto &[x,v]:cnt){
        if(v==1)st.PB(x);
    }
    VPII d;
    FOR(i,1,n){
        if(i!=st[0]&&i!=st[1]){
            d.PB(MP(qq({st[0],st[1],i}),i));
        }
    }
    sort(ALL(d),greater<PII>());
    VPII d2;
    st.PB(d[0].S);
    FOR(i,1,n){
        if(i!=st[2]&&i!=st[1]){
            d2.PB(MP(qq({st[2],st[1],i}),i));
        }
    }
    sort(ALL(d2),greater<PII>());
    st.PB(d2[0].S);
    W("!",st[2],st[3]);
    fflush(stdout);
}
void input() {
    R(n);
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}