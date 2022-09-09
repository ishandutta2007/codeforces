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
#define PB emplace_back
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
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
int get_bit(LL x,int v){return (x>>v)&1;}
VL ans;
set<LL>AA;
LL add(LL x, LL y, int op){
    LL res=0;
    if(!op){
        res=x+y;
    } else {
        res=x^y;
    }
    if(AA.count(res))return res;
    ans.PB(x);
    ans.PB(op);
    ans.PB(y);
    AA.insert(res);
    return res;
}
void rm(LL x,int bn){
    LL y=x;
    REP(i,bn){
        add(y,y,0);
        y<<=1;
    }
    LL v1=add(x,y,0);
    LL v2=add(x,y,1);
    LL v3=add(v1,v2,1);
    if(!(v3&(v3-1))){
        while(v3<=v1){
            if(v3&v1){
                v1=add(v1,v3,1);
            }
            v3=add(v3,v3,0);
        }
    } else {
        LL z=add(y,v3,1);
        v1=add(x,z,0);
        v2=add(x,z,1);
        v3=add(v1,v2,1);
        while(v3<=v1){
            if(v3&v1){
                v1=add(v1,v3,1);
            }
            if(v3<=v1)v3=add(v3,v3,0);
        }
    }
}
LL x;
void solve() {
    AA.insert(x);
    for(int i=20;i>0;i--){
        if(get_bit(x,i)){
            rm(x,i);
            x^=1<<i;
        }
    }
    W(SZ(ans)/3);
    for(int i=0;i<SZ(ans);i+=3){
        W(ans[i],(ans[i+1]==0)?'+':'^',ans[i+2]);
    }
}
void input() {
    R(x);
}
int main(){
    input();
    solve();
    return 0;
}