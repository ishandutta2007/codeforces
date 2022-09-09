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
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<17;
template<class T>
T rmqfunc(T a, T b) {
    return MP(max(a.F,b.F),min(a.S,b.S));
}
template <class T,T RmqFunc(T,T)>
class RMQ{
    public:
        vector<int>log2;
        vector<vector<T>> values;

        template<class IterType> void build(IterType begin, IterType end){
            assert(begin!=end);
            int n=end-begin;
            log2=vector<int>(n+1);
            for(int i=2;i<=n;i++)log2[i]=log2[i>>1]+1;
            values=vector<vector<T> >(log2.back()+1,vector<T>(n));
            for(int i=0;i<n;i++){
                values[0][i]=*(begin+i);
            }
            for(int i=1;i<=log2.back();i++){
                int len=1<<i;
                int half_len=1<<(i-1);
                for(int j=0;j+len<=n;j++){
                    values[i][j]=RmqFunc(values[i-1][j], values[i-1][j+half_len]);
                }
            }
        }
        T query(int ll,int rr) {
            int len = rr-ll+1;
            int lv=log2[len];
            return RmqFunc(values[lv][ll], values[lv][rr-(1<<lv)+1]);
        }
};
/*
void test() {
    vector<int> AA {1, 5, 3, 9, 7};
    RMQ<int,rmqfunc> rmq;
    rmq.build(AA.begin(), AA.end());

    cout<<rmq.query(0,2)<<endl;
    cout<<rmq.query(3,4)<<endl;
    cout<<rmq.query(1,4)<<endl;
    cout<<rmq.query(3,3)<<endl;
}
*/
bool in(int v,PII x){
    return x.F<=v&&v<=x.S;
}
PII dp[SIZE][2];
int n,m;
int k[SIZE];
int qq(RMQ<PII,rmqfunc> &rmq, int st, int v){
    int ll=st,rr=n;
    while(ll<rr){
        int mm=(ll+rr+1)/2;
        auto ret=rmq.query(st,mm);
        if(in(v,ret)){
            ll=mm;
        }else{
            rr=mm-1;
        }
    }
    return ll;
}
void update(PII &x, PII y){
    if(y.F>x.F){
        x=y;
    }
}
int an[SIZE];
void solve() {
    R(n,m);
    VPII p[2];
    REP(i,2)p[i].resize(n+1);
    FOR(i,1,n){
        R(k[i]);
        int a,b;
        R(a,b);
        p[0][i]=MP(a,b);
        R(a,b);
        p[1][i]=MP(a,b);
    }
    RMQ<PII,rmqfunc> rmq[2];
    rmq[0].build(ALL(p[0]));
    rmq[1].build(ALL(p[1]));
    REP(i,2){
        dp[1][i]=MP(qq(rmq[i],0,0),0);
        if(!in(k[1],p[i^1][1])){
            dp[1][i].F=-1;
        }
    }
    DEBUG(1,dp[1][0],dp[1][1]);
    REPP(i,1,n){
        REP(j,2){
            dp[i+1][j].F=-1;
        }
        REP(j,2){
            if(dp[i][j].F<i){continue;}
            if(dp[i][j].F>i&&in(k[i+1],p[j^1][i+1])){
                dp[i+1][j]=dp[i][j];
            }
        }
        REP(j,2){
            if(dp[i][j].F<i){continue;}
            if(in(k[i+1],p[j][i+1])){
                update(dp[i+1][j^1],MP(qq(rmq[j^1],i,k[i]),i));
            }
        }
        DEBUG(i,dp[i+1][0],dp[i+1][1]);
    }
    REP(i,2){
        if(dp[n][i].F>=n){
            PII now=MP(n,i);
            while(now.F){
                DEBUG("print",now);
                REPP(j,dp[now.F][now.S].S+1,now.F+1){
                    an[j]=now.S^1;
                }
                now=MP(dp[now.F][now.S].S,now.S^1);
            }
            W("Yes");
            W(VI(an+1,an+n+1));
            return;
        }
    }
    W("No");
}
int main(){
    solve();
    return 0;
}