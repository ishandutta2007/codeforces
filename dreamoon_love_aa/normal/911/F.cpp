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
typedef int64_t LL;
typedef uint64_t ULL;
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
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
int bfs[3][SIZE];
int dis[3][SIZE],from[3][SIZE];
bool u[SIZE];
VI e[SIZE];
void solve(int a[],int dd[],int ff[]){
    MS0(u);
    int rr=1;
    u[a[0]]=1;
    dd[a[0]]=0;
    REP(i,rr){
        int x=a[i];
        REP(j,SZ(e[x])){
            int y=e[x][j];
            if(u[y])continue;
            u[y]=1;
            dd[y]=dd[x]+1;
            ff[y]=x;
            a[rr++]=y;
        }
    }
}
bool in[SIZE];
VI ans;
int main(){
    int n;
    R(n);
    REPP(i,1,n){
        int x,y;R(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    bfs[0][0]=1;
    REP(i,3){
        solve(bfs[i],dis[i],from[i]);
        if(i<2)bfs[i+1][0]=bfs[i][n-1];
    }
    VI p;
    {
        int now=bfs[2][0];
        while(now!=bfs[1][0]){
            in[now]=1;
            p.PB(now);
            now=from[1][now];
        }
        in[bfs[1][0]]=1;
        p.PB(bfs[1][0]);
    }
    VPII ker;
    FOR(i,1,n){
        if(!in[i]){
            ker.PB(MP(max(dis[1][i],dis[2][i]),i));
        }
    }
    sort(ALL(ker));
    reverse(ALL(ker));
    LL v=0;
    REP(i,SZ(ker)){
        v+=ker[i].F;
        int x=ker[i].S;
        ans.PB(x);
        if(dis[1][x]>dis[2][x]){
            ans.PB(bfs[1][0]);
        }
        else{
            ans.PB(bfs[2][0]);
        }
        ans.PB(x);
    }
    REP(i,SZ(p)-1){
        v+=SZ(p)-1-i;
        ans.PB(p[i]);
        ans.PB(p.back());
        ans.PB(p[i]);
    }
    W(v);
    W(ans);
    return 0;
}