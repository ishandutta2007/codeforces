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
bool valid(string &s){
    int now=0;
    REP(i,SZ(s)){
        if(s[i]=='(')now++;
        else now--;
        if(now<0)return 0;
    }
    return 1;
}
int n;
string s;
void solve() {
    if(valid(s)){
        W(0);
        return;
    }
    int last_pos=0;
    bool neg=0;
    int now=0;
    REP(i,2*n){
        if(s[i]=='(')now++;
        else now--;
        if(now<0)neg=1;
        if(!neg)last_pos=i;
    }
    now=0;
    neg=0;
    int first_pos=2*n;
    for(int i=2*n-1;i>=0;i--){
        if(s[i]==')')now++;
        else now--;
        if(now<0)neg=1;
        if(!neg)first_pos=i;
    }
    now=0;
    int st=-1;
    int left_ma=-1;
    FOR(i,0,last_pos){
        if(s[i]=='(')now++;
        else now--;
        if(now>left_ma){
            left_ma=now;
            st=i;
        }
    }
    now=0;
    int right_ma=-1;
    int ed=2*n;
    for(int i=2*n-1;i>=first_pos;i--){
        if(s[i]==')')now++;
        else now--;
        if(now>right_ma){
            right_ma=now;
            ed=i;
        }
    }
    string t=s;
    reverse(t.begin()+st+1,t.begin()+ed);
    if(valid(t)){
        W(1);
        W(st+2,ed);
        return;
    }
    W(2);
    now=0;
    int ma=-1;
    int mid=-1;
    REP(i,2*n){
        if(s[i]=='(')now++;
        else now--;
        if(now>ma){
            ma=now;
            mid=i;
        }
    }
    W(1,mid+1);
    W(mid+2,2*n);
}
void input() {
    R(n);
    R(s);
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