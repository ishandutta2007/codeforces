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
int MOD = 998244353;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
const int COMBINATION_SIZE = 1<<21;
long long mypow(long long x, long long y, long long mod = MOD){
    long long res=1;
    while(y){
        if(y&1) {
            res = res * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}
struct Combination {
    long long fac[COMBINATION_SIZE], inv[COMBINATION_SIZE];
    bool built = 0;
    void build(){
        assert(MOD >= COMBINATION_SIZE);
        fac[0] = 1;
        for(int i = 1; i < COMBINATION_SIZE; i++) {
            fac[i] = fac[i - 1] * i % MOD;
        }
        inv[COMBINATION_SIZE - 1] = mypow(fac[COMBINATION_SIZE - 1], MOD - 2);
        for(int i = COMBINATION_SIZE - 2; i >= 0; i--) {
            inv[i] = inv[i + 1] * (i + 1) % MOD;
        }
    }
    long long C(int x, int y){
        if(y < 0 || y > x) {
            return 0;
        }
        if(!built) {
            built = 1;
            build();
        }
        return fac[x] * inv[y] % MOD * inv[x-y] % MOD;
    }
} comb;
int n;
int a[SIZE];
void solve() {
    LL ss=0;
    FOR(i,1,n)ss+=a[i];
    if(!ss){
        LL an=1;
        REP(i,n-1){
            ADD(an,an);
        }
        W(an);
        return;
    }
    map<LL,int>ll,rr;
    LL now=0;
    FOR(i,1,n){
        now+=a[i];
        if(now*2>ss)break;
        ll[now]++;
    }
    now=0;
    for(int i=n;i>0;i--){
        now+=a[i];
        if(now*2>ss)break;
        rr[now]++;
    }
    auto it_l=ll.begin();
    auto it_r=rr.begin();
    LL an=1;
    while(it_l!=ll.end()&&it_r!=rr.end()){
        if(it_l->F!=it_r->F){
            if(it_l->F<it_r->F){
                it_l++;
            }else{
                it_r++;
            }
        }else{
            int x=it_l->S;
            int y=it_r->S;
            if(it_l->F*2!=ss){
                LL tmp=1;
                FOR(i,1,min(x,y)){
                    ADD(tmp,comb.C(x,i)*comb.C(y,i));
                }
                an=an*tmp%MOD;
            }else{
                LL tmp=1;
                FOR(i,1,x){
                    ADD(tmp,comb.C(x,i));
                }
                an=an*tmp%MOD;
            }
            it_l++;
            it_r++;
        }
    }
    W(an);
}
void input() {
    R(n);
    FOR(i,1,n)R(a[i]);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    CASET {
        input();
        solve();
    }
    return 0;
}