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
int dp[1<<15][15][15];
PII from[1<<15][15][15];
char lb[1<<15][15];
int s[1<<15];
int a[15];
int get_bit(int x,int v){return (x>>v)&1;}
void pre(){
    memset(lb,15,sizeof(lb));
    REP(i,1<<15){
        for(int j=14;j>=0;j--){
            if(get_bit(i,j))lb[i][j]=j;
            else if(j!=14)lb[i][j]=lb[i][j+1];
        }
    }
}
bool update(int &x,int v){
    if(!x||x>v){
        x=v;
        return 1;
    }
    return 0;
}
void solve(){
    int n;
    R(n);
    REP(i,n){
        R(a[i]);
        s[1<<i]=a[i];
    }
    REP(i,1<<n)REP(j,n)REP(k,n)dp[i][j][k]=0;
    REPP(i,1,1<<n){
        if((i&(i-1)))s[i]=s[i^(i&-i)]+s[i&-i];
    }
    int MASK=(1<<n)-1;
    REPP(i,1,1<<n){
        int bn=__builtin_popcount(i);
        if(update(dp[i][(int)lb[i][0]][bn-1],s[i])){
            from[i][(int)lb[i][0]][bn-1]=MP(0,0);
        }
        int mask=(MASK^i);
        REP(j,n-1){
            if(!get_bit(i,j))continue;
            REP(k,bn){
                if(!dp[i][j][k])continue;
                for(int now=mask;now>>j;now=(now-1)&mask){
                    if(s[now]>dp[i][j][k]){
                        int nxt_j=lb[now][j+1];
                        if(update(dp[i|now][nxt_j][k+__builtin_popcount(now)-1],s[now])){
                            from[i|now][nxt_j][k+__builtin_popcount(now)-1]=MP(i,j);
                        }
                    }
                }
            }
        }
    }
    REP(i,n){
        REP(j,n){
            if(dp[MASK][j][i]){
                int now=MASK;
                VPII AA;
                W(i);
                while(now){
                    auto bk=from[now][j][i];
                    AA.PB(MP(now^bk.F,bk.F?lb[now^bk.F][bk.S+1]:lb[now][0]));
                    j=bk.S;
                    i-=__builtin_popcount(AA.back().F)-1;
                    now=bk.F;
                }
                VI d;
                REP(k,n)d.PB(k);
                for(auto x:AA){
                    REP(i2,n){
                        if(i2==x.S)continue;
                        if(!get_bit(x.F,i2))continue;
                        int st,ed;
                        REP(j2,SZ(d)){
                            if(d[j2]==i2)st=j2+1;
                            else if(d[j2]==x.S)ed=j2+1;
                        }
                        W(st,ed);
                        d.erase(d.begin()+st-1);
                    }
                }
                return;
            }
        }
    }
}
int main(){
    pre();
    CASET{
        solve();
    }
    return 0;
}