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
const int SIZE = 1e6+10;
int an=0;
int f(VPII& e,int s){
    int ll=0;
    int ret=-1;
    multiset<int>AA;
    for(int i=SZ(e)-1;i>0;i--){
        while(ll<i&&e[ll].F+e[i].F<=s){
            AA.insert(e[ll].S);
            ll++;
        }
        while(ll>i){
            ll--;
            AA.erase(AA.find(e[ll].S));
        }
        if(SZ(AA))ret=max(ret,e[i].S+*AA.rbegin());
    }
    return ret;
}
int main(){
    int n,c,d;
    R(n,c,d);
    VPII e[2];
    REP(i,n){
        int b,p;
        char s[4];
        R(b,p);
        RS(s);
        if(s[0]=='C')e[0].PB(MP(p,b));
        else e[1].PB(MP(p,b));
    }
    REP(i,2)sort(ALL(e[i]));
    an=max(an,f(e[0],c));
    an=max(an,f(e[1],d));
    int v1=-1,v2=-1;
    REP(i,SZ(e[0])){
        if(e[0][i].F<=c)v1=max(v1,e[0][i].S);
    }
    REP(i,SZ(e[1])){
        if(e[1][i].F<=d)v2=max(v2,e[1][i].S);
    }
    if(v1!=-1&&v2!=-1)an=max(an,v1+v2);
    W(an);
    return 0;
}