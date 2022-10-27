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
LL p1,t1,p2,t2,h,s;
LL base[SIZE];
LL brute(int need) {
    LL r1=t1,r2=t2;
    LL an=0;
    while(need>0){
        LL mi=min(r1,r2);
        an+=mi;
        if(mi==r1){
            need-=p1-s;
            r1=t1;
        }else{
            r1-=mi;
        }
        if(mi==r2){
            need-=p2-s;
            r2=t2;
        }else{
            r2-=mi;
        }
    }
    return an;
}
LL AA[SIZE][2];
LL dp[SIZE];
void update(LL &x, LL v) {
    if(x>v||x==-1)x=v;
}
void solve() {
    FOR(i,0,h)base[i]=brute(i);
    LL an=base[h];
    int m=0;
    FOR(i,1,5000){
        if(i*t1<t2)continue;
        LL v=(i-1)*(p1-s)+(i*t1-t2)/t2*(p2-s)+(p1+p2-s);
        AA[m][0]=min(v,(LL)h);
        AA[m][1]=i*t1;
        m++;
        if(v>=h)break;
    }
    FOR(i,1,5000){
        if(i*t2<t1)continue;
        LL v=(i-1)*(p2-s)+(i*t2-t1)/t1*(p1-s)+(p1+p2-s);
        AA[m][0]=min(v,(LL)h);
        AA[m][1]=i*t2;
        m++;
        if(v>=h)break;
    }
    MS1(dp);
    dp[0]=0;
    FOR(i,0,h-1){
        if(dp[i]==-1)continue;
        REP(j,m){
            update(dp[min((LL)h,i+AA[j][0])],dp[i]+AA[j][1]);
        }
    }
    FOR(i,0,h){
        if(dp[i]==-1)continue;
        update(an,dp[i]+base[h-i]);
    }
    W(an);
}
void input() {
    R(p1,t1);
    R(p2,t2);
    R(h,s);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}