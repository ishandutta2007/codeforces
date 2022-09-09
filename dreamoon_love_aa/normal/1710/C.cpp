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
void ADD(int& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
string str;
bool valid[2][2][2];
int get_bit(long long x, int v) { return (x >> v) & 1; }
void my_add(int &x, int v){
    x+=v;
    if(x>=MOD)x-=MOD;
}
void solve() {
    int n=SZ(str);
    int dp[2][8]={};
    int now=0,nxt=1;
    dp[now][7]=1;
    int s=0;
    REP(pos,n){
        MS0(dp[nxt]);
        int bb=str[pos]-'0';
        my_add(s,s);
        my_add(s,bb);
        REP(i,8){
            int x=1,y=1,z=1;
            if(get_bit(i,0)){
                x=bb;
            };
            if(get_bit(i,1)){
                y=bb;
            }
            if(get_bit(i,2)){
                z=bb;
            }
            FOR(j,0,x)FOR(k,0,y)FOR(r,0,z){
                if(!valid[j][k][r])continue;
                int ii=i;
                if(j!=bb)ii&=~1;
                if(k!=bb)ii&=~2;
                if(r!=bb)ii&=~4;
                my_add(dp[nxt][ii],dp[now][i]);
            }
        }
        swap(now,nxt);
    }
    my_add(s,1);
    int ans=(LL)s*s%MOD*s%MOD,tmp=0;
    REP(i,8)my_add(tmp,dp[now][i]);
    ADD(tmp,-((LL)s*s*2-s));
    ADD(ans,-tmp*3LL);
    ADD(ans,-(LL)s*s*3);
    ADD(ans,s*2LL);
    W(ans);
}
void input() {
    R(str);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    MOD=998244353;
    valid[0][0][0]=1;
    valid[1][1][1]=1;
    valid[0][1][0]=1;
    valid[0][1][1]=1;
    valid[1][0][0]=1;
    valid[1][0][1]=1;
    input();
    solve();
    return 0;
}