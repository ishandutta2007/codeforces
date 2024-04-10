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
LL fib[SIZE];
void pre(){
    fib[0]=fib[1]=1;
    REPP(i,2,90){
        fib[i]=fib[i-1]+fib[i-2];
        if(fib[i]>1e12){
            return;
        }
    }
}
int k,c[SIZE];
bool test(multiset<PLL>&AA,int id){
    for(int i=id;i>=0;i-=2){
        if(AA.rbegin()->F<fib[i]){
            return 0;
        }
        auto x=*AA.rbegin();
        AA.erase(prev(AA.end()));
        if(fib[i]>x.F)AA.insert(MP(fib[i]-x.F,x.S));
    }
    return 1;
}
int an[SIZE];
void solve() {
    multiset<PLL>AA;
    REP(i,k)AA.insert(MP(c[i],i));
    LL sum=0;
    REP(i,k){
        sum+=c[i];
    }
    int n=0;
    LL now=0;
    while(1){
        now+=fib[n];
        if(now>=sum)break;
        n++;
    }
    if(now!=sum){
        W("NO");
        return;
    }
    int lt=-1;
    for(int i=n;i>=0;i--){
        if((--AA.end())->F<fib[i]){
            W("NO");
            return;
        }
        auto it=prev(AA.end());
        if(it->S==lt){
            if(it==AA.begin()){
                W("NO");
                return;
            }
            it--;
        }
        if(it->S==lt||it->F<fib[i]){
            W("NO");
            return;
        }
        LL x=it->F-fib[i];
        int id=it->S;
        lt=id;
        AA.erase(it);
        if(x){
            AA.insert(MP(x,id));
        }
    }
    W("YES");
}
void input() {
    R(k);
    REP(i,k)R(c[i]);
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