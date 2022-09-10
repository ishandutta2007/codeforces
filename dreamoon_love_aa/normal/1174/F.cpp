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
int lv[SIZE],lat[SIZE];
VI e[SIZE];
int can[SIZE];
int AA;
void dfs0(int x,int lt,int v){
    lv[x]=v;
    for(int y:e[x]){
        if(y==lt)continue;
        lat[y]=x;
        dfs0(y,x,v+1);
    }
}
int target;
int cnt(int x,int lt,int dd){
    if(!dd){
        target=x;
        return 1;
    }
    int ret=0;
    for(int y:e[x]){
        if(y==lt)continue;
        ret+=cnt(y,x,dd-1);
    }
    return ret;
}
int dp[SIZE];
int dfs2(int x,int lt,int dd){
    if(!dd){
        dp[x]=can[x];
        return -1;
    }
    dp[x]=0;
    for(int y:e[x]){
        if(y==lt)continue;
        int now=dfs2(y,x,dd-1);
        if(now!=-1)return now;
        dp[x]+=dp[y];
        if(dp[x]>=(AA+1)/2)return x;
    }
    return -1;
}
void clear(int x,int lt,int dd){
    if(!dd){
        if(can[x]){
            can[x]=0;
            AA--;
        }
        return;
    }
    for(int y:e[x]){
        if(y==lt)continue;
        clear(y,x,dd-1);
    }
}
void clear2(int x,int lt,int stop,int dd){
    if(x==stop)return;
    if(!dd){
        if(can[x]){
            can[x]=0;
            AA--;
        }
        return;
    }
    for(int y:e[x]){
        if(y==lt)continue;
        clear2(y,x,stop,dd-1);
    }
}
int find_answer(){
    FOR(i,1,SIZE){
        if(can[i])return i;
    }
    return -1;
}
int qq(int x,int dd){
    if(AA==1){
        return find_answer();
    }
    if(!dd)return x;
    int qx=dfs2(x,lat[x],dd);
    if(qx!=x){
        W("d",qx);
        fflush(stdout);
        int v; R(v);
        if(lv[qx]+v!=lv[x]+dd){
            clear(qx,lat[qx],lv[x]+dd-lv[qx]);
            qx=x;
        }
        else{
            clear2(x,lat[x],qx,dd);
        }
    }
    if(AA==1){
        return find_answer();
    }
    W("s",qx);
    fflush(stdout);
    int v;
    R(v);
    clear2(x,lat[x],v,dd);
    return qq(v,dd-(lv[v]-lv[x]));
}
int main(){
    int n; R(n);
    REPP(i,1,n){
        int x,y; R(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs0(1,1,0);
    int now=1,dd;
    W("d",now);
    fflush(stdout);
    R(dd);
    FOR(i,1,n){
        if(lv[i]==dd){
            can[i]=1;
            AA++;
        }
    }
    W("!",qq(1,dd));
    return 0;
}