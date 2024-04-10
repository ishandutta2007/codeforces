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
const int SIZE = 5e3+10;
int n,m,_n[3];
int u[SIZE];
VI e[SIZE];
int cnt[SIZE][2];
VI nodes[SIZE][2];
int id;
char an[SIZE];
bool dfs(int x,int v){
    u[x]=v;
    cnt[id][v]++;
    nodes[id][v].PB(x);
    for(int y:e[x]){
        if(u[y]!=-1){
            if(u[y]==v)return 0;
        }
        else{
            if(!dfs(y,v^1))return 0;
        }
    }
    return 1;
}
int dp[SIZE][SIZE];
int main(){
    R(n,m);
    REP(i,3)R(_n[i]);
    REP(i,m){
        int x,y;
        R(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    MS1(u);
    FOR(i,1,n){
        if(u[i]==-1){
            if(!dfs(i,0)){
                W("NO");
                return 0;
            }
            id++;
        }
    }
    MS1(dp);
    dp[0][0]=0;
    REP(i,id){
        REP(j,SIZE){
            if(dp[i][j]==-1)continue;
            dp[i+1][j+cnt[i][0]]=j;
            dp[i+1][j+cnt[i][1]]=j;
        }
    }
    if(dp[id][_n[1]]==-1){
        W("NO");
        return 0;
    }
    int now=_n[1];
    for(int i=id;i>0;){
        int lt=dp[i][now];
        int num=now-lt;
        i--;
        int r=1;
        if(SZ(nodes[i][0])==num)r=0;
        for(int x:nodes[i][r]){
            an[x]='2';
        }
        now=lt;
    }
    FOR(i,1,n){
        if(!an[i]){
            if(_n[0]){
                _n[0]--;
                an[i]='1';
            }
            else an[i]='3';
        }
    }
    W("YES");
    puts(an+1);
    return 0;
}