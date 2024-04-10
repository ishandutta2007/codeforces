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
typedef int64_t LL;
typedef uint64_t ULL;
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
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
int n;
int dp[2][1<<12];
int v[6],digit_cnt[1<<12];
char s[4][SIZE];
VPII mask;
void pre(){
    int sqr[4][4];
    VPII tmp;
    REP(i,4)REP(j,4)sqr[i][j]=i*4+j;
    FOR(len,1,4)FOR(i,0,4-len){
        int me=0;
        REP(x,len)REPP(y,i,i+len)me|=1<<sqr[x][y];
        tmp.PB(MP(me,v[len]));
    }
    map<int,int>H;
    auto mii = [](auto& x,auto y){if(x>y)x=y;};
    REP(i,1024){
        int vv=0,me=0;
        REP(j,10){
            if((i>>j)&1){
                vv+=tmp[j].S;
                me|=tmp[j].F;
            }
        }
        if(!H.count(me))H[me]=vv;
        else mii(H[me],vv);
    }
    for(auto pp:H)mask.PB(pp);
}
void update(int &x,int vv){
    if(x==-1||x>vv)x=vv;
}
int main(){

    R(n);
    FOR(i,1,4)R(v[i]);
    REP(i,4)RS(s[i]);
    pre();
    MS1(dp);
    dp[0][(1<<12)-1]=0;
    int now=0,nxt=1;
    REP(i,n){
        MS1(dp[nxt]);
        int me=0;
        REP(j,4){
            if(s[j][i]=='.')me|=1<<j;
        }
        REP(j,1<<12){
            if(dp[now][j]==-1)continue;
            REP(k,SZ(mask)){
                if(i<3&&mask[k].F>=(16<<(4*i)))continue;
                if(((j|(mask[k].F>>4))>>8)==15){
                    update(dp[nxt][((j<<4)|me|mask[k].F)&((1<<12)-1)],dp[now][j]+mask[k].S);
                }
            }
        }
        swap(now,nxt);
    }
    W(dp[now][(1<<12)-1]);
    return 0;
}