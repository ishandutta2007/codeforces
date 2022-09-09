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
const int SIZE = 1<<19;
int get_bit(int x,int v){return (x>>v)&1;}
int d[31][SIZE];
int n;
LL C2(int x){return x*(x-1)/2;}
LL an1;
int an2;
LL inv_cnt[31][2];
void f(int lv, int l, int r){
    if(l>r)return;
    int cnt=0;
    LL my_inv=0;
    FOR(i,l,r){
        int bit=get_bit(d[lv+1][i],lv);
        cnt+=bit;
        if(!bit){
            my_inv+=cnt;
        }
    }
    inv_cnt[lv][0]+=my_inv;
    inv_cnt[lv][1]+=cnt*(r-l+1LL-cnt)-my_inv;
    if(!lv)return;
    int it[2]={l,l+cnt};
    FOR(i,l,r){
        int x=d[lv+1][i];
        if(get_bit(x,lv)){
            d[lv][it[0]++]=x;
        } else {
            d[lv][it[1]++]=x;
        }
    }
    f(lv-1,l,it[0]-1);
    f(lv-1,it[0],r);
}
void solve() {
    MS0(inv_cnt);
    an1=0;
    an2=0;
    f(29,1,n);
    REP(i,30){
        if(inv_cnt[i][0]<=inv_cnt[i][1]){
            an1+=inv_cnt[i][0];
        }else{
            an1+=inv_cnt[i][1];
            an2|=1<<i;
        }
    }
    W(an1,an2);
}
void input() {
    R(n);
    FOR(i,1,n)R(d[30][i]);
}
int main(){
#define MULTITEST 0
#if MULTITEST    
    CASET
#endif
    {
        input();
        solve();
    }
    return 0;
}