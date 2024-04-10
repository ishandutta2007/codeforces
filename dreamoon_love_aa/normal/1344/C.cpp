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
const int SIZE = 2e5+10;
VI e[SIZE],ae[SIZE];
char an[SIZE];
int an_v;
int bfs[SIZE];
int deg[SIZE];
int u[SIZE],tt;
int n;
bool test(){
    int bn=0;
    REP(x,n){
        for(int y:e[x]){
            deg[y]++;
        }
    }
    REP(x,n){
        if(!deg[x]){
            bfs[bn++]=x;
        }
    }
    REP(i,bn){
        int x=bfs[i];
        for(int y:e[x]){
            deg[y]--;
            if(!deg[y]){
                bfs[bn++]=y;
            }
        }
    }
    if(bn!=n)return 0;
    return 1;
}
bool QwQ[SIZE],OwQ[SIZE];
void go(int st){
    int bn=0;
    bfs[bn++]=st;
    QwQ[st]=1;
    REP(i,bn){
        int x=bfs[i];
        for(int y:e[x]){
            if(!QwQ[y]){
                bfs[bn++]=y;
                QwQ[y]=1;
            }
        }
    }
    bn=0;
    bfs[bn++]=st;
    OwQ[st]=1;
    REP(i,bn){
        int x=bfs[i];
        for(int y:ae[x]){
            if(!OwQ[y]){
                bfs[bn++]=y;
                OwQ[y]=1;
            }
        }
    }
}
int main(){
    int m;
    R(n,m);
    REP(i,n)an[i]='E';
    REP(i,m){
        int x,y;
        R(x,y);
        x--;y--;
        e[x].PB(y);
        ae[y].PB(x);
    }
    if(!test()){
        W(-1);
        return 0;
    }
    REP(i,n){
        if(!QwQ[i]&&!OwQ[i]){
            an_v++;
            an[i]='A';
        }
        go(i);
    }
    W(an_v);
    W(an);
    return 0;
}