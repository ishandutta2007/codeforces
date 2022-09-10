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
const int SIZE = 1e6+10;
void solve(){
    int a[2][3];
    int v[8];
    int an[8];
    REP(k,2)REP(i,3)R(a[k][2-i]);
    FOR(i,1,7){
        R(v[8-i]);
    }
    int ll[3],rr[3];
    int sum[3]={};
    FOR(i,1,7){
        REP(j,3){
            if((i>>j)&1)sum[j]+=v[i];
        }
    }
    REP(i,3){
        if(sum[i]>a[0][i]+a[1][i]){
            W(-1);
            return;
        }
    }
    REP(i,3)rr[i]=a[0][i];
    ll[0]=max(0,v[3]+v[5]+v[7]-a[1][0]);
    ll[1]=max(0,v[3]+v[6]+v[7]-a[1][1]);
    ll[2]=max(0,v[5]+v[6]+v[7]-a[1][2]);
    FOR(i,max({ll[0],ll[1],ll[2]}),v[3]+v[5]+v[6]+v[7]){
        int s[3],b[3];
        bool err=0;
        REP(j,3){
            s[j]=max(0,i-rr[j]);
            b[j]=min(v[7^(1<<j)],i-ll[j]);
            if(s[j]>b[j])err=1;
        }
        if(err)continue;
        if(i-b[0]-b[1]-b[2]>v[7])continue;
        REP(j,3){
            int tmp=max(0,min(b[0]+b[1]+b[2]-i,b[j]-s[j]));
            b[j]-=tmp;
        }
        if(i-b[0]-b[1]-b[2]<0)continue;
        an[6]=b[0];
        an[5]=b[1];
        an[3]=b[2];
        an[7]=i-b[0]-b[1]-b[2];
        an[1]=min(v[1],rr[0]-an[3]-an[5]-an[7]);
        an[2]=min(v[2],rr[1]-an[3]-an[6]-an[7]);
        an[4]=min(v[4],rr[2]-an[5]-an[6]-an[7]);
        for(int j=7;j>0;j--)printf("%d%c",an[j]," \n"[j==1]);
        return;
    }
    W(-1);
}
int main(){
    CASET{
        solve();
    }
    return 0;
}