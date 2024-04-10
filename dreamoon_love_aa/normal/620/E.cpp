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
const int SIZE = 1<<20;
int c[SIZE],co[SIZE];
int _id,l[SIZE],r[SIZE];
VI e[SIZE];
LL AA[SIZE];
int pb[SIZE];
void dfs(int x,int lt){
    l[x]=r[x]=_id++;
    co[l[x]]=c[x];
    for(int y:e[x]){
        if(y==lt)continue;
        dfs(y,x);
        r[x]=r[y];
        AA[l[x]]|=AA[l[y]];
    }
}
void push(int id){
    if(pb[id]){
        pb[id<<1]=pb[id];
        pb[(id<<1)|1]=pb[id];
        AA[id<<1]=1LL<<pb[id];
        AA[(id<<1)|1]=1LL<<pb[id];
        pb[id]=0;
    }
}
void pull(int id){
    AA[id]=AA[id*2]|AA[id*2+1];
}
void edit(int L,int R,int id,int l,int r,int v){
    if(L>r||R<l)return;
    if(L>=l&&R<=r){
        AA[id]=1LL<<v;
        pb[id]=v;
        return;
    }
    push(id);
    int mm=(L+R)/2;
    edit(L,mm,id*2,l,r,v);
    edit(mm+1,R,id*2+1,l,r,v);
    pull(id);
}
LL qq(int L,int R,int id,int l,int r){
    if(L>r||R<l)return 0;
    if(L>=l&&R<=r){
        return AA[id];
    }
    push(id);
    int mm=(L+R)/2;
    return qq(L,mm,id*2,l,r)|qq(mm+1,R,id*2+1,l,r);
}
void build(int L,int R,int id){
    if(L==R){
        AA[id]=1LL<<co[L];
        return;
    }
    int mm=(L+R)/2;
    build(L,mm,id*2);
    build(mm+1,R,id*2+1);
    pull(id);
}
int main(){
    int n,m;
    R(n,m);
    FOR(i,1,n)R(c[i]);
    REPP(i,1,n){
        int x,y;
        R(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(1,1);
    build(0,n-1,1);
    REP(i,m){
        int ty;
        R(ty);
        if(ty==1){
            int x,v;
            R(x,v);
            edit(0,n-1,1,l[x],r[x],v);
        }else{
            int x;
            R(x);
            W(__builtin_popcountll(qq(0,n-1,1,l[x],r[x])));
        }
    }
    return 0;
}