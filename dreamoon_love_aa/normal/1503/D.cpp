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
const int SIZE = 1<<20;
int to[SIZE];
int pos[SIZE];
bool u[SIZE];
int res[2][SIZE]; // 0: small to large, 1: large to small
int n;
int a[SIZE];
int b[SIZE];
void solve() {
    int ll=1,rr=2*n;
    int it_l=1,it_r=n;
    int an=0;
    res[1][0]=res[0][n+1]=2*n+1;
    while(it_l<=it_r){
        while(u[ll])ll++;
        while(u[rr])rr--;
        int cnt[2]={};
        int r_mi=to[ll];
        int l_ma=ll;
        cnt[pos[ll]]++;
        res[0][it_l]=ll;
        res[1][it_l++]=to[ll];
        u[ll]=u[to[ll]]=1;
        while(ll<l_ma||rr>r_mi){
            while(rr>r_mi){
                if(u[rr]){
                    rr--;
                    continue;
                }
                res[0][it_r]=rr;
                res[1][it_r--]=to[rr];
                l_ma=max(l_ma,to[rr]);
                u[rr]=u[to[rr]]=1;
                cnt[pos[rr]]++;
                rr--;
            }
            while(ll<l_ma){
                if(u[ll]){
                    ll++;
                    continue;
                }
                res[0][it_l]=ll;
                res[1][it_l++]=to[ll];
                r_mi=min(r_mi,to[ll]);
                u[ll]=u[to[ll]]=1;
                cnt[pos[ll]]++;
                ll++;
            }
        }
        an+=min(cnt[0],cnt[1]);
    }
    FOR(i,1,n){
        if(res[0][i]<res[0][i-1]){
            W(-1);
            return;
        }
        if(res[1][i]>res[1][i-1]){
            W(-1);
            return;
        }
    }
    W(an);
}
void input() {
    R(n);
    FOR(i,1,n){
        R(a[i],b[i]);
        pos[a[i]]=1;
        to[a[i]]=b[i];
        to[b[i]]=a[i];
    }
}
int main(){
    input();
    solve();
    return 0;
}