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
VI e[SIZE];
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){
        int y = x, z = x;
        while(y != d[y]) y = d[y];
        while(x != y){
            x = d[x];
            d[z] = y;
            z = x;
        }
        return y;
    }
    bool is_root(int x){return d[x]==x;}
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        d[x]=y;
        return 1;
    }
}U;
int dis[1111][1111];
void dfs(int x,int lt,int dd[]){
    for(int y:e[x]){
        if(y==lt)continue;
        dd[y]=dd[x]+1;
        dfs(y,x,dd);
    }
}
int self_far[1111];
VI AA[1111];
VPII an;
int main(){
    int n,m;
    R(n,m);
    U.init(n+1);
    REP(i,m){
        int x,y;
        R(x,y);
        e[x].PB(y);
        e[y].PB(x);
        U.uu(x,y);
    }
    FOR(i,1,n){
        dfs(i,i,dis[i]);
    }
    auto maa = [](auto& x,auto y){if(x<y)x=y;};
    int max_dia=0;
    FOR(i,1,n){
        FOR(j,1,n){
            if(U.find(i)==U.find(j)){
                maa(self_far[i],dis[i][j]);
                maa(max_dia,dis[i][j]);
            }
        }
        AA[U.find(i)].PB(i);
    }
    if(m==n-1){
        W(max_dia);
        return 0;
    }
    int mi_v=1111;
    FOR(i,1,n){
        VI g;
        g.PB(self_far[i]);
        VPII tmp;
        FOR(j,1,n){
            if(SZ(AA[j])==0)continue;
            if(U.find(i)==j)continue;
            PII mi=MP(1111,1111);
            for(int y:AA[j]){
                mi=min(mi,MP(self_far[y]+1,y));
            }
            g.PB(mi.F);
            tmp.PB(MP(i,mi.S));
        }
        sort(ALL(g),greater<int>());
        if(max(max_dia,g[0]+g[1])<mi_v){
            mi_v=max(max_dia,g[0]+g[1]);
            an=tmp;
        }
    }
    W(mi_v);
    for(auto x:an)W(x);
    return 0;
}