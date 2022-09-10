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
#define UnionFindSIZE 1234567
struct Union_Find{
    int d[UnionFindSIZE],num[UnionFindSIZE],w[UnionFindSIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    bool is_root(int x){return d[x]==x;}
    int uu(int x,int y,int v){
        int ma=0;
        while(x!=y&&(x!=d[x]||y!=d[y])){
            if(x==d[x]||(num[y]<=num[x]&&y!=d[y])){
                ma=max(ma,w[y]);
                y=d[y];
            }
            else{
                ma=max(ma,w[x]);
                x=d[x];
            }
        }
        if(x==y)return ma;
        if(num[x]>num[y])swap(x,y);
        d[x]=y;
        num[y]+=num[x];
        w[x]=v;
        return -1;
    }
}U;
struct EDGE{
    int x,y,v,id;
    EDGE(int x=0,int y=0,int v=0,int id=0):x(x),y(y),v(v),id(id){}
    bool operator<(const EDGE& b)const{
        return v<b.v;
    }
}e[SIZE];
LL an[SIZE];
int main(){
    int n,m;
    R(n,m);
    U.init(n);
    REP(i,m){
        int x,y,v;
        R(x,y,v);
        x--;y--;
        e[i]=EDGE(x,y,v,i);
    }
    sort(e,e+m);
    LL base=0;
    REP(i,m){
        int id=e[i].id;
        an[id]=U.uu(e[i].x,e[i].y,e[i].v);
        if(an[id]==-1){
            base+=e[i].v;
            an[id]=0;
        }
        else an[id]=e[i].v-an[id];
    }
    REP(i,m)W(base+an[i]);
    return 0;
}