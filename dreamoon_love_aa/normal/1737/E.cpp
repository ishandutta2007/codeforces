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
long long mypow(long long x,long long y, int mod = MOD) {
    x %= mod;
    long long res = 1 % mod;
    while(y){
        if(y & 1) { res = res * x % mod; }
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}
int n;
//LL dp_r[SIZE],dp_r_sum[SIZE];
LL dp_r2[SIZE],dp_r2_sum[SIZE];
LL two[SIZE],inv_two[SIZE];
void pre(){
    two[0]=1;
    REPP(i,1,SIZE){
        two[i]=two[i-1]*2%MOD;
    }
    inv_two[SIZE-1]=mypow(two[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv_two[i]=inv_two[i+1]*2%MOD;
}
//dp_r[i] last_one start from i
//dp_r2[i] no any good start from i
//
void solve() {
    if(n==1){
        W(1);
        return;
    }
    dp_r2_sum[n+1]=1;
    dp_r2[n+1]=1;

    //dp_r[n+1]=0;
    //dp_r_sum[n+1]=0;
    for(int i=n;i>0;i--){
        int m=n-2*(i-1);
        /*
        if(m>=0){
            dp_r[i]=dp_r2_sum[n-m+1];
        }
        else{
            dp_r[i]=0;
        }
        dp_r_sum[i]=(dp_r[i]*two[i]+dp_r_sum[i+1])%MOD;
        */
        if(2*(i-1)+1>n+1){
            dp_r2[i]=two[n-i];
        }else{
            dp_r2[i]=dp_r2_sum[i+1]-dp_r2_sum[2*(i-1)+1];
            ADD(dp_r2[i],0);
        }
        dp_r2_sum[i]=(dp_r2[i]+dp_r2_sum[i+1])%MOD;
    }
    W(0);
    FOR(i,2,n){
        int m=i/2;
        W(two[m]*dp_r2[i+1]%MOD*inv_two[n-1]%MOD);
    }
}
void input() {
    R(n);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    pre();
    CASET {
        input();
        solve();
    }
    return 0;
}