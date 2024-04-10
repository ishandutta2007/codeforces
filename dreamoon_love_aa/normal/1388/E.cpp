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
struct Seg{
    int xl,xr,y;
    bool operator<(const Seg &b)const{
        if(y!=b.y)return y>b.y;
        return xl<b.xl;
    }
}seg[SIZE];
int state[SIZE][SIZE];
int ord[SIZE];
double an;
void qq(int l_id,int r_id, LD v){
    LD ll=seg[l_id].xl+seg[l_id].y*v;
    LD rr=seg[r_id].xr+seg[r_id].y*v;
    an=min(an,(double)(rr-ll));
}
bool cmp(const pair<LD,pair<int,PII>>&x,const pair<LD,pair<int,PII>>&y){
    if(fabs(x.F-y.F)>1e-15)return x.F<y.F;
    if(x.S.F!=y.S.F)return x.S.F<y.S.F;
    return 0;
}
void solve() {
    an=1e18;
    int n;
    R(n);
    REP(i,n)R(seg[i].xl,seg[i].xr,seg[i].y);
    sort(seg,seg+n);
    vector<pair<LD,pair<int,PII>>>AA;
    REP(j,n){
        ord[j]=j;
        REP(i,j){
            if(seg[i].y==seg[j].y)continue;
            AA.PB(MP((LD)(seg[j].xl-seg[i].xr)/(seg[i].y-seg[j].y),MP(1,MP(i,j))));
            AA.PB(MP((LD)(seg[j].xr-seg[i].xl)/(seg[i].y-seg[j].y),MP(-1,MP(i,j))));
        }
    }
    sort(ALL(AA),cmp);
    if(SZ(AA)==0){
        printf("%d\n",seg[n-1].xr-seg[0].xl);
        return;
    }
    int now=0;
    int l_id=0,r_id=n-1;
    REP(i,SZ(AA)){
        if(!now){
            qq(l_id,r_id,AA[i].F);
        }
        state[AA[i].S.S.F][AA[i].S.S.S]^=1;
        if(!state[AA[i].S.S.F][AA[i].S.S.S]){
            now--;
            ord[AA[i].S.S.F]++;
            ord[AA[i].S.S.S]--;
            if(ord[AA[i].S.S.F]==n-1)r_id=AA[i].S.S.F;
            if(ord[AA[i].S.S.S]==0)l_id=AA[i].S.S.S;
        } else {
            now++;
        }
        if(!now){
            qq(l_id,r_id,AA[i].F);
        }
    }
    printf("%.12f\n",an);
}
int main(){
#define MULTITEST 0
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}