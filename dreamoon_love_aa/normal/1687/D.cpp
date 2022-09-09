#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const int SIZE = 1420*1420;
int n;
int a[SIZE];
int dp[SIZE];
LL st[SIZE];
void solve() {
    {
        int it=1;
        int pre=0;
        bool fail=0;
        FOR(i,1,1417){
            int me=i*i;
            while(it<=n&&a[it]<me){
                if(a[it]-pre>=me-a[it]){
                    fail=1;
                    break;
                }
                it++;
            }
            pre=me;
            if(fail||it>n)break;
        }
        if(!fail){
            W(0);
            return;
        }
    }
    {
        LL now=4;
        REPP(i,1,SIZE){
            st[i]=now;
            now+=2*i+3;
        }
    }
    a[n+1]=SIZE;
    {
        int v=1;
        FOR(i,1,n){
            REPP(j,a[i],a[i+1])dp[j]=v;
            v++;
        }
    }
    a[0]=a[1]-2000001;
    LL mi=9e12;
    int ma=a[n];
    FOR(i,1,n){
        int bb=a[i]-a[i-1]-1;
        FOR(j,1,bb){
            bool err=0;
            if(a[i]>=st[j])continue;
            int ll=a[i]-1-j;
            int rr=a[i]-1;
            int k=j;
            while(rr>=1){
                if(ll>=0){
                    if(dp[ll]!=dp[rr]){
                        err=1;
                        break;
                    }
                }else{
                    if(dp[rr]){
                        err=1;
                        break;
                    }
                }
                rr-=2*k+1;
                ll-=2*k;
                k--;
                if(!k)break;
            }
            if(err)continue;
            ll=a[i]+j+1;
            rr=a[i]+j+j+2;
            k=j+1;
            while(ll<=ma){
                if(dp[ll]!=dp[min(rr,ma)]){
                    err=1;
                    break;
                }
                k++;
                ll+=k*2;
                rr+=k*2+1;
            }
            if(!err)mi=min(mi,st[j]-a[i]);
        }
    }
    W(mi);
}
namespace io {
    const int SIZE = 1e7 + 10;
    char inbuff[SIZE];
    char *l, *r;
    inline void init() {
        l = inbuff;
        r = inbuff + fread(inbuff, 1, SIZE, stdin);
    }
    inline char gc() {
        if (l == r) init();
        return (l != r) ? *(l++) : EOF;
    }
    void read(int &x) {
        x = 0; char ch = gc();
        while(!isdigit(ch) && ch !='-') ch = gc();
        bool neg = 0;
        if(ch == '-') { neg = 1; ch = gc(); }
        while(isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
        if(neg) { x = -x; }
    }
} using io::read;
void input() {
    read(n);
    FOR(i,1,n)read(a[i]);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}