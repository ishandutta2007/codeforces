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
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<12;
struct Data{
    int lt,r;
    LL use;
    Data(int lt=0,int r=0,LL use=0):lt(lt),r(r),use(use){}
    bool operator<(const Data& b)const{
        return MP(lt,r)<MP(b.lt,b.r);
    }
    bool same(const Data& b)const{
        return MP(lt,r)==MP(b.lt,b.r);
    }
};
Data dp[2001][6192];
int dn[SIZE];
int n;
LL K;
LL l[SIZE],r[SIZE];
LL a[SIZE];
void fix(int id){
    sort(dp[id],dp[id]+dn[id]);
    int j,k=0;
    for(int i=0;i<dn[id];i=j){
        LL mi=1e18;
        for(j=i;j<dn[id]&&dp[id][j].same(dp[id][i]);j++){
            mi=min(mi,dp[id][j].use);
        }
        dp[id][k++]=Data(dp[id][i].lt,dp[id][i].r,mi);
    }
}
int f(int x,int y){
    if(x<y)return y-1;
    return y;
}
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
void solve() {
    dn[0]=1;
    l[n]=2e9;
    REP(i,n){
        dn[i+1]=2;
        dp[i+1][0]=Data(l[i+1]-1,(K-a[i]%K)%K,1e18);
        dp[i+1][1]=Data(l[i+1],(K-a[i]%K)%K,1e18);
        REP(j,dn[i]){
            //DEBUG(dp[i][j].lt,dp[i][j].r,dp[i][j].use);
            auto me=dp[i][j];
            if(me.use>1e17)continue;
            if((r[i]-l[i])*K+(me.lt==l[i]?me.r:K)<a[i])continue;
            if(me.r+(r[i]-l[i])*K>=a[i]){
                if(me.r>=a[i]){
                    dp[i+1][dn[i+1]++]=Data(f(l[i],l[i+1]),me.r-a[i],me.use+a[i]);
                }
                else{
                    dp[i+1][dn[i+1]++]=Data(f(l[i]+1+(a[i]-me.r-1)/K,l[i+1]),(K-(a[i]-me.r)%K)%K,me.use+a[i]);
                }
            } 
            if((r[i]-l[i])*K+(me.lt==l[i]?0:K)){
                int ty=f(l[i]+(me.lt==l[i])+(a[i]-1)/K,l[i+1]);
                if(ty==l[i+1]-1){
                    mii(dp[i+1][0].use,me.use+a[i]+me.r);
                }
                else{
                    mii(dp[i+1][1].use,me.use+a[i]+me.r);
                }
            }
        }
    }
    if(!dn[n]){
        W(-1);
    }
    else{
        LL an=1e18;
        REP(i,dn[n]){
            an=min(an,dp[n][i].use);
        }
        if(an<1e17){
            W(an);
        }else W(-1);
    }
}
void input() {
    R(n,K);
    REP(i,n){
        R(l[i],r[i],a[i]);
        if(i&&l[i]==l[i-1]&&r[i]==r[i-1]){
            a[i-1]+=a[i];
            i--;
            n--;
        }
    }
}
int main(){
    input();
    solve();
    return 0;
}