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
const int SIZE = 2e5+5;
#define UnionFindSIZE 1234567
struct Union_Find {
    int d[UnionFindSIZE], num[UnionFindSIZE];
    LL ec[UnionFindSIZE];
    void init(int n){
        for(int i = 0; i < n; i++) {
            d[i] = i;
            num[i] = 1;
            ec[i] = 0;
        }
    }
    int find(int x){
        int y = x, z = x;
        while(y != d[y]) { y = d[y]; }
        while(x != y) {
            x = d[x];
            d[z] = y;
            z = x;
        }
        return y;
    }
    bool is_root(int x) { return d[x] == x; }
    bool uu(int x,int y) {
        x = find(x);
        y = find(y);
        if(x == y) { return 0; }
        if(num[x] > num[y]) { swap(x,y); }
        num[y] += num[x];
        ec[y] += ec[x];
        d[x] = y;
        return 1;
    }
}U,U2;
VI e[SIZE];

VI ee[SIZE];
int dp[SIZE];
int ord[SIZE];
bool cmp(int x, int y){
    return ee[x][2] < ee[y][2];
}
int main(){
    int n, m;
    int xx=0;
    R(n,m);
    U.init(n);
    REP(i,m){
        int x,y,v;R(x,y,v);x--;y--;
        ee[i]={x,y,v};
        xx^=v;
        e[x].PB(y);
        e[y].PB(x);
    }
    REP(i,n){
        sort(ALL(e[i]));
        int lt = -1;
        for(int y:e[i]){
            if(lt+1!=y){
                U.uu(i,lt+1);
                dp[lt+1]++;
                dp[y-1]--;
                U.ec[U.find(y-1)]+=y-lt-1;
            }
            lt=y;
        }
        if(lt!=n-1){
            U.uu(i,lt+1);
            dp[lt+1]++;
            dp[n-1]--;
            U.ec[U.find(n-1)]+=n-lt-1;
        }
    }
    REP(i,n){
        dp[i+1]+=dp[i];
        if(dp[i]){
            U.uu(i,i+1);
        }
    }
    LL an=0;
    LL sp_mi=1e18;
    U2.init(n);
    REP(i,m){ord[i]=i;}
    sort(ord,ord+m,cmp);
    int need=n-1;
    REP(j,m){
        int i=ord[j];
        if(U.uu(ee[i][0],ee[i][1])){
            U2.uu(ee[i][0],ee[i][1]);
            need--;
            an+=ee[i][2];
        }
    }
    REP(i,m){
        if(U2.find(ee[i][0])!=U2.find(ee[i][1])){
            sp_mi=min(sp_mi,(LL)ee[i][2]);
        }
    }
    if(need+m==n*(n-1LL)/2){
        an+=min(sp_mi,(LL)xx);
    }
    W(an);
    return 0;
}