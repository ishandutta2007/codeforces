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
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
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
VI e[SIZE];
int deg[SIZE];
VI lv[SIZE];
int MA_TT;
void f2(int x,int lt,int tt=0){
    MA_TT=max(MA_TT,tt);
    lv[tt].PB(x);
    for(int y:e[x]){
        if(y==lt)continue;
        f2(y,x,tt+1);
    }
}
bool check(int x){
    FOR(i,0,MA_TT)lv[i].clear();
    MA_TT=0;
    f2(x,x);
    FOR(i,0,MA_TT){
        REPP(j,1,SZ(lv[i])){
            if(SZ(e[lv[i][j]])!=SZ(e[lv[i][0]]))return 0;
        }
    }
    return 1;
}
bool u[SIZE];
int from[SIZE];
bool cmp(int x,int y){
    return SZ(e[x])<SZ(e[y]);
}
int find(int x){
    if(!from[x])return x;
    return find(from[x]);
}
int main(){
    int n; R(n);
    if(n==1){
        W(1);
        return 0;
    }
    REPP(i,1,n){
        int x,y; R(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    VI AA[2];
    FOR(i,1,n){
        deg[i]=SZ(e[i]);
        if(SZ(e[i])==1){
            u[i]=1;
            AA[0].PB(i);
        }
    }
    int now=0,nxt=1;
    while(1){
        AA[nxt].clear();
        for(int x:AA[now]){
            for(int y:e[x]){
                if(!u[y]){
                    u[y]=1;
                    from[y]=x;
                    AA[nxt].PB(y);
                }
            }
        }
        if(SZ(AA[nxt])==0){
            int v=find(AA[now][0]);
            if(check(v)){
                W(v);
                return 0;
            }
            v=find(AA[now].back());
            if(check(v)){
                W(v);
                return 0;
            }
            W(-1);
            return 0;
        }
        if(SZ(AA[nxt])==1){
            W(AA[nxt][0]);
            return 0;
        }
        int m=SZ(AA[nxt]);
        sort(ALL(AA[nxt]),cmp);
        if(SZ(e[AA[nxt][0]])!=SZ(e[AA[nxt][m-1]])){
            int v=find(AA[nxt][0]);
            if(check(v)){
                W(v);
                return 0;
            }
            v=find(AA[nxt][m-1]);
            if(check(v)){
                W(v);
                return 0;
            }
            W(-1);
            return 0;
        }
        swap(now,nxt);
    }
    return 0;
}