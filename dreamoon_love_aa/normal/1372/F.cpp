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
int an[SIZE];
map<PII,PII>ret;
PII qq(int l,int r){
    if(ret.count(MP(l,r)))return ret[MP(l,r)];
    W("?",l,r);
    fflush(stdout);
    int x,f;
    R(x,f);
    return ret[MP(l,r)]=MP(x,f);
}
void go(int l,int r){
    if(l>r)return;
    int n=(r-l+1);
    int x,f;
    tie(x,f)=qq(l,r);
    int least=(n+f-1)/f;
    VPII gg(least);
    REP(i,least){
        gg[i]=qq(l+i*f,min(l+(i+1)*f-1,r));
    }
    int ma=-1;
    int center=-1;
    REP(i,least){
        if(gg[i].F==x){
            if(ma<gg[i].S){
                ma=gg[i].S;
                center=i;
            }
        }
    }
    PII done;
    if(gg[center].S==f){
        fill(an+l+center*f,an+min(l+(center+1)*f,r+1),x);
        done=MP(center,center);
    } else {
        if(qq(l+center*f,l+center*f+ma-1)==MP(x,ma)){
            fill(an+l+center*f,an+l+center*f+ma,x);
            fill(an+l+center*f-(f-ma),an+l+center*f,x);
            go(l+(center-1)*f,l+center*f-(f-ma)-1);
            go(l+center*f+ma,min(r,l+(center+1)*f-1));
            done=MP(center-1,center);
        } else{
            fill(an+l+(center+1)*f-ma,an+l+(center+1)*f,x);
            fill(an+l+(center+1)*f,an+l+(center+1)*f+(f-ma),x);
            go(l+center*f,l+(center+1)*f-ma-1);
            go(l+(center+1)*f+(f-ma),min(r,l+(center+2)*f-1));
            done=MP(center,center+1);
        }
    }
    REP(i,least){
        if(i<done.F||i>done.S){
            go(l+i*f,min(l+(i+1)*f-1,r));
        }
    }
}
void solve() {
    int n;
    R(n);
    go(1,n);
    W("!",VI(an+1,an+n+1));
    return;
}
int main(){
#define MULTITEST 0
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}