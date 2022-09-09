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

const int SIZE = 1<<12;
int n,m;
int a[SIZE],_b[SIZE];
int b[SIZE];
VI e[SIZE];
#define UnionFindSIZE 1234567
struct Union_Find {
    int d[UnionFindSIZE], num[UnionFindSIZE];
    void init(int n){
        for(int i = 0; i < n; i++) {
            d[i] = i;
            num[i] = 1;
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
        d[x] = y;
        return 1;
    }
}U;
int rn;
int ma_v;
bitset<2001>u;
int from[SIZE];
LL add_v;
LL st;
void clear(int y){
    int AA=y;
    while(AA!=1){
        add_v+=b[AA];
        if(b[AA])rn--;
        b[AA]=0;
        AA=from[AA];
    }
}
bool dfs(int x, int lt, LL now){
    u[x]=1;
    for(int y: e[x]) {
        if(y==lt){continue;}
        if(u[y]&&b[y]==0){
            if(now>st){
                clear(y);
                clear(x);
                return 1;
            }
            continue;
        }
        if(now>a[y]){
            if(u[y]){
                clear(y);
                clear(x);
                return 1;
            }else{
                from[y]=x;
                if(dfs(y,x,now+b[y]))return 1;
            }
        }
    }
    return 0;
}
bool valid(LL st_v){
    FOR(i,1,n){
        b[i]=_b[i];
    }
    U.init(n+1);
    rn=n;
    add_v=0;
    while(rn==1||st_v<=ma_v){
        st=st_v;
        u.reset();
        if(!dfs(1,1,st_v))break;
        st_v+=add_v;
        add_v=0;
    }
    return rn==1||st_v>ma_v;
}
void solve() {
    ma_v=*max_element(a+1,a+n+1)+1;
    int ll=MOD,rr=ma_v;
    for(int x:e[1])ll=min(ll,a[x]);
    while(ll<rr){
        int mm=(ll+rr)/2;
        if(valid(mm))rr=mm;
        else ll=mm+1;
    }
    W(ll);
}
void input() {
    R(n,m);
    FOR(i,2,n){
        R(a[i]);
    }
    FOR(i,2,n){
        R(_b[i]);
    }
    FOR(i,1,n){
        VI tmp;
        e[i].swap(tmp);
    }
    REP(i,m){
        int x,y;
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