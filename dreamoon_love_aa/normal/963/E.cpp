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
void ADD(int& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 111;
LL mypow(LL x,LL y){
    x%=MOD;
    LL res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
int r;
int a[4];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
#define P(x,y) p[(x)+55][(y)+55]
int p[SIZE][SIZE],pid;
int sqr(int x){return x*x;}
bool Out(int x,int y){
    return sqr(x)+sqr(y)>sqr(r);
}
int d[7847][7847];
int main(){
    R(r);
    int sum_a=0;
    REP(i,4){
        R(a[i]);
        sum_a+=a[i];
    }
    REP(i,4){
        a[i]=a[i]*mypow(sum_a,MOD-2)%MOD;
    }
    int O_O=-1;
    FOR(x,-r,r)FOR(y,-r,r){
        if(!Out(x,y)){
            if(!x&&!y)O_O=pid;
            P(x,y)=pid++;
        }
    }
    FOR(x,-r,r)FOR(y,-r,r){
        if(Out(x,y))continue;
        d[P(x,y)][pid]=1;
        d[P(x,y)][P(x,y)]=1;
        REP(i,4){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(!Out(nx,ny)){
                ADD(d[P(x,y)][P(nx,ny)],-a[i]);
            }
        }
    }
    int rid=0;
    REP(i,pid){
        {
            int tt;
            for(tt=rid;!d[tt][i];tt++);
            if(tt!=rid){
                FOR(k,i,pid)swap(d[tt][k],d[rid][k]);
            }
        }
        int inv=mypow(d[rid][i],MOD-2);
        for(int j=rid+1;j<rid+110&&j<pid;j++){
            if(d[j][i]){
                int mul=(LL)d[j][i]*inv%MOD;
                REPP(k,i+1,min(i+110,pid)){
                    ADD(d[j][k],-(LL)d[rid][k]*mul);
                }
                ADD(d[j][pid],-(LL)d[rid][pid]*mul);
                d[j][i]=0;
            }
        }
        rid++;
    }
    for(int i=pid-1;i>O_O;i--){
        int mul=mypow(d[i][i],MOD-2)*d[i][pid]%MOD;
        for(int j=i-1;j>=O_O;j--){
            if(d[j][i]){
                ADD(d[j][pid],-(LL)d[j][i]*mul);
            }
        }
    }
    W(d[O_O][pid]*mypow(d[O_O][O_O],MOD-2)%MOD);
    return 0;
}