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
const int SIZE = 80010;
LL ma[SIZE],_tmp[SIZE];
void push(int id){
    if(_tmp[id]==0)return;
    _tmp[id*2]+=_tmp[id];
    ma[id*2]+=_tmp[id];
    _tmp[id*2+1]+=_tmp[id];
    ma[id*2+1]+=_tmp[id];
    _tmp[id]=0;
}
void pull(int id){
    ma[id]=max(ma[id*2],ma[id*2+1]);
}
void seg_init(int L,int R,int id){
    ma[id]=_tmp[id]=0;
    if(L==R){
        return;
    }
    int mm=(L+R)/2;
    seg_init(L,mm,id*2);
    seg_init(mm+1,R,id*2+1);
    pull(id);
}
LL qq(int L,int R,int id,int ll,int rr){
    if(R<ll||L>rr)return LLONG_MIN;
    if(L>=ll&&R<=rr)return ma[id];
    int mm=(L+R)/2;
    push(id);
    return max(qq(L,mm,id*2,ll,rr),qq(mm+1,R,id*2+1,ll,rr));
}
void ins(int L,int R,int id,int ll,int rr,LL v){
    if(R<ll||L>rr)return;
    if(L>=ll&&R<=rr){
        ma[id]+=v;
        _tmp[id]+=v;
        return;
    }
    int mm=(L+R)/2;
    push(id);
    ins(L,mm,id*2,ll,rr,v);
    ins(mm+1,R,id*2+1,ll,rr,v);
    pull(id);
}
int dp[52][SIZE];
int a[52][SIZE];
int dp0[52][SIZE];
int get(int lv,int x,int y){
    x--;
    if(x<=0)return dp0[lv][y];
    return dp0[lv][y]-dp0[lv][x];
}
int main(){
    int n,m,k;
    R(n,m,k);
    FOR(i,1,n)FOR(j,1,m){
        R(a[i][j]);
        dp0[i][j]=dp0[i][j-1]+a[i][j];
    }
    int r_bound=m+1-k;
    FOR(i,1,n){
        if(i==1){
            FOR(j,1,r_bound)dp[i+1][j]=get(1,j,j+k-1)+get(2,j,j+k-1);
            continue;
        }
        else{
            seg_init(1,r_bound,1);
            FOR(j,1,r_bound){
                ins(1,r_bound,1,j,j,dp[i][j]+dp0[i][min(k,j-1)]);
            }
        }
        FOR(j,1,r_bound){
            dp[i+1][j]=qq(1,r_bound,1,1,r_bound)+get(i+1,j,j+k-1);
            if(j+1<=r_bound)ins(1,r_bound,1,j+1,r_bound,-a[i][j]);
            if(j-k>=1)ins(1,r_bound,1,1,j-k,-a[i][j]);
            if(j+k<r_bound)ins(1,r_bound,1,j+k+1,r_bound,a[i][j+k]);
            ins(1,r_bound,1,1,j,a[i][j+k]);
        }
    }
    int an=0;
    FOR(i,1,r_bound)an=max(an,dp[n+1][i]);
    W(an);
    return 0;
}