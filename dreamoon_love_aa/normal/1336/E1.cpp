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
int get_bit(LL x,int v){return (x>>v)&1;}
int n,m;
LL mask;
const int MAX_M=36;
const int HALF=(1+MAX_M)/2;
LL AA[MAX_M];
bool add(LL x){
    for(int i=m-1;i>=0;i--){
        if(get_bit(x,i)){
            if(!AA[i]){
                REP(j,i){
                    if(get_bit(x,j))x^=AA[j];
                }
                REPP(j,i+1,m){
                    if(get_bit(AA[j],i))AA[j]^=x;
                }
                mask|=1LL<<i;
                AA[i]=x;
                return 1;
            }
            x^=AA[i];
        }
    }
    return 0;
}
int an[MAX_M];
VL d;
void dfs(int x, LL now){
    if(x==SZ(d)){
        an[__builtin_popcountll(now)]++;
        return;
    }
    dfs(x+1,now);
    dfs(x+1,now^d[x]);
}
int dp[MAX_M+2][1<<(MAX_M-HALF+1)];
void solve1(int two_num){
    REP(i,m){
        if(AA[i])d.PB(AA[i]);
    }
    dfs(0,0);
    LL mul=1;
    REP(i,two_num){
        mul*=2;
        if(mul>=MOD)mul-=MOD;
    }
    FOR(i,0,m)an[i]=an[i]*mul%MOD;
    W(VI(an,an+m+1));
}
void my_add(int &x,int v){
    x+=v;
    if(x>=MOD)x-=MOD;
}
void solve2(int two_num){
    REP(i,m){
        if(AA[i]){
            int it=0;
            int me=0;
            REP(j,m){
                if(!get_bit(mask,j)){
                    me|=get_bit(AA[i],j)<<it;
                    it++;
                }
            }
            d.PB(me);
        }
    }
    dp[0][0]=1;
    int bb=m-__builtin_popcountll(mask);
    REP(i,SZ(d)){
        for(int k=i;k>=0;k--){
            REP(j,1<<bb){
                my_add(dp[k+1][j^d[i]],dp[k][j]);
            }
        }
    }
    FOR(i,0,SZ(d)){
        REP(j,1<<bb){
            my_add(an[__builtin_popcountll(j)+i],dp[i][j]);
        }
    }
    LL mul=1;
    REP(i,two_num){
        mul*=2;
        if(mul>=MOD)mul-=MOD;
    }
    FOR(i,0,m)an[i]=an[i]*mul%MOD;
    W(VI(an,an+m+1));
}
int main(){
    MOD=998244353;
    R(n,m);
    int num=0;
    REP(i,n){
        LL x;
        R(x);
        num+=add(x);
    }
    if(num<=HALF){
        solve1(n-num);
    }
    else{
        solve2(n-num);
    }
    return 0;
}