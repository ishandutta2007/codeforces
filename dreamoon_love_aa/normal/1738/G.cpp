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
const int SIZE = 1<<10;
string s[SIZE];
string an[SIZE];
char tmp[SIZE];
int dp[SIZE][SIZE];
int n,k;
int calc(){
    REP(i,n)REP(j,n){
        dp[i][j]=(s[i][j]=='0');
        if(i)dp[i][j]=max(dp[i][j],dp[i-1][j]);
        if(j)dp[i][j]=max(dp[i][j],dp[i][j-1]);
        if(i&&j)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+(s[i][j]=='0'));
    }
    return dp[n-1][n-1];
}
int id_main(int x, int y){
    return n-1-x+y;
}
int id_ver(int x, int y){
    return x+y;
}
int id_ver(PII v){
    return v.F+v.S;
}
void step(PII &x){
    x.F++;
    x.S++;
}
void solve() {
    int zero_cnt=0;
    REP(i,n)REP(j,n){
        zero_cnt+=(s[i][j]=='0');
    }
    if(n*n-zero_cnt<(n-k+1)*(n-k+1)){
        W("NO");
        return;
    }
    if(calc()>=k){
        W("NO");
        return;
    }
    W("YES");
    k--;
    vector<VPII> target(2*n);
    REP(i,n)REP(j,n){
        if(s[i][j]=='0'){
            target[id_main(i,j)].PB({i,j});
        }
    }
    REP(i,2*n)reverse(ALL(target[i]));
    VPII current(2*n-1);
    REP(i,n){
        current[id_main(i,0)]={i,0};
        current[id_main(0,i)]={0,i};
    }
    int st=id_main(n-k,0);
    int ed=id_main(0,n-k);
    REP(i,n)an[i]=string(n,'0');
    REP(i,n)REP(j,n){
        if(id_main(i,j)<st||id_main(i,j)>ed)an[i][j]='1';
    }
    REP(i,k){
        VI fixed(2*n-1);
        if(i){
            FOR(j,st,ed)step(current[j]);
        }
        fixed[st]=fixed[ed]=1;
        priority_queue<PII,VPII,greater<>>pq;
        FOR(j,st+1,ed-1){
            pq.push({id_ver(current[j]),j});
        }
        while(!pq.empty()){
            PII me=pq.top();
            pq.pop();
            if(!target[me.S].empty()&&current[me.S]==target[me.S].back()){
                target[me.S].pop_back();
                fixed[me.S]=1;
                continue;
            }
            if((fixed[me.S-1]&&id_ver(current[me.S])>id_ver(current[me.S-1]))||
               (fixed[me.S+1]&&id_ver(current[me.S])>id_ver(current[me.S+1]))){
                fixed[me.S]=1;
                continue;
            }
            step(current[me.S]);
            pq.push({id_ver(current[me.S]),me.S});
        }
        FOR(i,st,ed){
            an[current[i].F][current[i].S]='1';
        }
    }
    REP(i,n)W(an[i]);
}
void input() {
    R(n,k);
    REP(i,n)R(s[i]);
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