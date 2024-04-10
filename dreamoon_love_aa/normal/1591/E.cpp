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
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<20;
int n,q;
int a[SIZE];
#include <bits/extc++.h>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>;
Tree<PII> AA;
int l[SIZE],k[SIZE];
int cnt[SIZE];
VI e[SIZE];
VI qq[SIZE];
int an[SIZE];
void dfs(int x){
    if(cnt[a[x]]){
        AA.erase({cnt[a[x]],a[x]});
    }
    cnt[a[x]]++;
    AA.insert({cnt[a[x]],a[x]});
    for(int qid: qq[x]){
        auto pos=AA.order_of_key(MP(l[qid],0));
        if(pos+k[qid]>SZ(AA)){
            an[qid]=-1;
        }else{
            an[qid]=AA.find_by_order(pos+k[qid]-1)->S;
        }
    }
    for(int y:e[x]){
        dfs(y);
    }
    AA.erase({cnt[a[x]],a[x]});
    cnt[a[x]]--;
    if(cnt[a[x]]){
        AA.insert({cnt[a[x]],a[x]});
    }
}
void solve() {
    dfs(1);
    W(VI(an,an+q));
}
void input() {
    R(n,q);
    FOR(i,1,n)R(a[i]);
    FOR(i,1,n){
        cnt[i]=0;
        VI tmp;
        e[i].swap(tmp);
        VI tmp2;
        qq[i].swap(tmp2);
    }
    FOR(i,2,n){
        int x;
        R(x);
        e[x].PB(i);
    }
    REP(i,q){
        int v;
        R(v,l[i],k[i]);
        qq[v].PB(i);
    }
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}