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
const int TYPE_AND = 0;
const int TYPE_OR = 1;
const int TYPE_XOR = 2;
const int TYPE_NOT = 3;
const int TYPE_IN = 4;
int XX[3][2][2];
void init(){
    REP(i,2)REP(j,2)XX[TYPE_AND][i][j]=i&j;
    REP(i,2)REP(j,2)XX[TYPE_OR][i][j]=i|j;
    REP(i,2)REP(j,2)XX[TYPE_XOR][i][j]=i^j;
}
int e[SIZE][2],AA[SIZE];
char an[SIZE];
VI vi[SIZE][2];
VI *ptr[SIZE][2];
void merge(VI *&ptr1,VI *&ptr2){
    if(ptr1->size() > ptr2->size()){
        swap(ptr1, ptr2);
    }
    for(int x:*ptr1)ptr2->PB(x);
}
int dfs(int x){
    REP(i,2)ptr[x][i]=&vi[x][i];
    if(AA[x] == TYPE_IN){
        vi[x][1^e[x][0]].PB(x);
        return e[x][0];
    }

    if(AA[x] == TYPE_NOT){
        int y = e[x][0];
        int ret = dfs(y);
        REP(i,2)ptr[x][i] = ptr[y][i^1];
        return ret^1;
    }

    int ret[2]={dfs(e[x][0]), dfs(e[x][1])};
    REP(i,2){
        int y=e[x][0];
        int nv=XX[AA[x]][i][ret[1]];
        merge(ptr[y][i],ptr[x][nv]);
    }
    REP(i,2){
        int y=e[x][1];
        int nv=XX[AA[x]][ret[0]][i];
        merge(ptr[y][i],ptr[x][nv]);
    }
    return XX[AA[x]][ret[0]][ret[1]];
}
int main(){
    init();
    int n; R(n);
    char s[24];
    FOR(i,1,n){
        RS(s);
        if(s[0]=='N'||s[0]=='I')R(e[i][0]);
        else R(e[i][0],e[i][1]);
        if(s[0]=='A'){
            AA[i]=TYPE_AND;
        }
        else if(s[0]=='O'){
            AA[i]=TYPE_OR;
        }
        else if(s[0]=='X'){
            AA[i]=TYPE_XOR;
        }
        else if(s[0]=='N'){
            AA[i]=TYPE_NOT;
        }
        else if(s[0]=='I'){
            AA[i]=TYPE_IN;
        }
        else {
            assert(1);
        }
    }
    dfs(1);
    VPII pp;
    for(int x:*ptr[1][0])pp.PB({x,0});
    for(int x:*ptr[1][1])pp.PB({x,1});
    sort(ALL(pp));
    REP(i,SZ(pp))an[i]=pp[i].S+'0';
    W(an);
    return 0;
}