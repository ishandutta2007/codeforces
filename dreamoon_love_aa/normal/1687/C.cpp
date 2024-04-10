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
int n,m;
LL a[SIZE],b[SIZE];
int l[SIZE],r[SIZE];
VI AA[SIZE];
set<int>bad;
queue<int>qq;
bitset<SIZE>u;
void del(int y){
    for(int x:AA[y]){
        if(u[x])continue;
        if(!bad.count(l[x])&&!bad.count(r[x])){
            u[x]=1;
            qq.push(x);
        }
    }
}
void solve() {
    REP(i,m)u[i]=0;
    {
        queue<int>tmp;
        qq.swap(tmp);
    }
    bad.clear();
    FOR(i,1,n){
        a[i]=a[i-1]+(a[i]-b[i]);
        if(a[i])bad.insert(i);
    }
    if(a[n]){
        W("NO");
        return;
    }
    REP(i,m){
        if(!bad.count(l[i])&&!bad.count(r[i])){
            u[i]=1;
            qq.push(i);
        }else{
            AA[l[i]].PB(i);
            AA[r[i]].PB(i);
        }
    }
    while(!qq.empty()){
        int x=qq.front();
        qq.pop();
        auto it=bad.lower_bound(l[x]);
        while(it!=bad.end()&&*it<=r[x]){
            int v=*it;
            it=bad.erase(it);
            del(v);
        }
    }
    W(SZ(bad)?"NO":"YES");
}
void input() {
    R(n,m);
    FOR(i,1,n){
        R(a[i]);
    }
    FOR(i,1,n){
        R(b[i]);
    }
    FOR(i,0,n)AA[i].clear();
    REP(i,m){
        R(l[i],r[i]);
        l[i]--;
    }
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