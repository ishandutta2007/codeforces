/*{{{*/
#include <bits/stdc++.h>
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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1010;
int dd[SIZE][SIZE];
VI e[SIZE];
int RT;
void dfs(int x,int lt,int v){
    dd[RT][x]=v;
    for(int y:e[x]){
        if(y==lt)continue;
        dfs(y,x,v+1);
    }
}
bool u[SIZE];
int qq(int x,int y){
    W("?",x,y);
    fflush(stdout);
    int ret;
    R(ret);
    return ret;
}
bool is_leaf(int x){
    int cnt=0;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(!u[y])cnt++;
    }
    return cnt<=1;
}
bool AA[SIZE];
void visit(int x,int lt){
    if(u[x])return;
    AA[x]=1;
    for(int y:e[x]){
        if(y!=lt)visit(y,x);
    }
}
int main(){
    int n;
    R(n);
    REPP(i,1,n){
        int x,y;
        R(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    FOR(i,1,n){
        RT=i;
        dfs(i,i,0);
    }
    while(1){
        VI rr;
        FOR(i,1,n){
            if(u[i])continue;
            if(is_leaf(i)){
                rr.PB(i);
                if(SZ(rr)==2)break;
            }
        }
        if(SZ(rr)==1){
            W("!",rr[0]);
            return 0;
        }
        int v=qq(rr[0],rr[1]);
        if(v==rr[0]||v==rr[1]){
            W("!",v);
            return 0;
        }
        FOR(i,1,n){
            if(i==v)continue;
            if(dd[rr[0]][i]+dd[i][rr[1]]==dd[rr[0]][rr[1]])u[i]=1;
        }
        FOR(i,1,n)AA[i]=0;
        visit(v,v);
        FOR(i,1,n){
            if(!AA[i])u[i]=1;
        }
    }
    return 0;
}