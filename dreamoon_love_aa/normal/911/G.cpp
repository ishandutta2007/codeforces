/*{{{*/
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#pragma GCC optimize("tree-vectorize")
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
typedef int64_t LL;
typedef uint64_t ULL;
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
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
#define UL unsigned long long
UL a[100][3200];
UL pre[64],pro[64];
UL mask;
int main(){
    REP(i,64){
        mask|=1ULL<<i;
        pre[i]=1ULL<<i;
        if(i)pre[i]|=pre[i-1];
    }
    for(int i=63;i>=0;i--){
        pro[i]=1ULL<<i;
        if(i!=63)pro[i]|=pro[i+1];
    }
    int n;R(n);
    REP(i,n){
        int x;
        R(x);x--;
        a[x][i/64]|=1ULL<<i%64;
    }
    int q;R(q);
    while(q--){
        int l,r,x,y;
        R(l,r,x,y);
        if(x==y)continue;
        l--;r--;x--;y--;
        int lid=l>>6;
        int rid=r>>6;
        if(lid==rid){
            UL v=pre[r&63]&pro[l&63];
            a[y][lid]|=v&a[x][lid];
            a[x][lid]&=mask^v;
            continue;
        }
        REPP(i,lid+1,rid){
            a[y][i]|=a[x][i];
            a[x][i]=0;
        }
        a[y][lid]|=pro[l&63]&a[x][lid];
        if(l&63)a[x][lid]&=pre[(l&63)-1];
        else a[x][lid]=0;

        a[y][rid]|=pre[r&63]&a[x][rid];
        if((r&63)!=63)a[x][rid]&=pro[(r&63)+1];
        else a[x][rid]=0;
    }
    VI an;
    REP(i,n){
        REP(j,100)
            if((a[j][i/64]>>i%64)&1){
                an.PB(j+1);
                break;
            }
    }
    W(an);
    return 0;
}