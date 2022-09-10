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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
int get_bit(LL x,int v){return (x>>v)&1;}
VL d[60];
void No(){
    W("No");
    exit(0);
}
VL res[2];
int main(){
    int n; R(n);
    REP(i,n){
        LL v; R(v);
        for(int j=59;j>=0;j--){
            if(get_bit(v,j)) {
                d[j].PB(v);
                break;
            }
        }
    }
    int st=60;
    for(int i=59;i>=0;i--){
        if(SZ(d[i])){
            st=i;
            break;
        }
    }
    if(SZ(d[st])>1){
        No();
    }
    int now=0, nxt=1;
    res[now]=d[st];
    res[now].PB((1LL<<61)-1);
    for(int i=st-1;i>=0;i--){
        LL v=0;
        res[nxt].clear();
        int it=0;
        for(LL x: d[i]){
            while(it<SZ(res[now]) && (v >= (v^x) || (v^x) >= (v^x^res[now][it]))){
                v^=res[now][it];
                res[nxt].PB(res[now][it++]);
            }
            if(it==SZ(res[now])) No();
            v^=x^res[now][it];
            res[nxt].PB(x);
            res[nxt].PB(res[now][it++]);
        }
        while(it<SZ(res[now])){
            res[nxt].PB(res[now][it++]);
        }
        swap(now,nxt);
    }
    res[now].pop_back();
    W("Yes");
    W(res[now]);
    return 0;
}