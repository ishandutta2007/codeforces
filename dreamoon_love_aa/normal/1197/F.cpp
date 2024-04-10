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
const int SIZE = 1e3+10;
const int MATRIX_SIZE = 64;
struct Matrix_Power{
    LL AA[60][MATRIX_SIZE][MATRIX_SIZE],aa[62][MATRIX_SIZE];
    int N;
    void set(LL _A[][MATRIX_SIZE],int _N,LL bb = (LL)1e10){
        N=_N;
        REP(i,N)
            REP(j,N)AA[0][i][j]=_A[i][j];
        REPP(round,1,60){
            if((1LL<<round)>bb)break;
            REP(i,N)REP(j,N)AA[round][i][j]=0;
            REP(i,N)REP(j,N)REP(k,N){
                AA[round][i][k]+=AA[round-1][i][j]*AA[round-1][j][k];
                AA[round][i][k]%=MOD;
            }
        }
    }
    void get(LL _a[],LL v,LL ret[]){
        MS0(aa);
        REP(i,N)aa[0][i]=_a[i];
        REP(i,61){
            if((1LL<<i)>v){
                memcpy(ret,aa[i],sizeof(LL)*64);
                return;
            }
            if((v>>i)&1){
                REP(j,N)REP(k,N){
                    aa[i+1][j]+=AA[i][j][k]*aa[i][k];
                    aa[i+1][j]%=MOD;
                }
            }
            else REP(j,N)aa[i+1][j]=aa[i][j];
        }
    }
}mat;
LL A[MATRIX_SIZE][MATRIX_SIZE];
LL a[MATRIX_SIZE];
int relate[3][3];
int tran[3][MATRIX_SIZE][MATRIX_SIZE];
void build(){
    REP(i,3)REP(j,3)R(relate[i][j]);
    REP(col,3){
        REP(j,64){
            int tmp[3]={j&3,(j&12)>>2,(j&48)>>4};
            int ss[4]={};
            REP(k,3){
                if(relate[col][k])ss[tmp[k]]=1;
            }
            int me=0;
            while(ss[me])me++;
            tran[col][(j*4+me)&63][j]++;
            A[(j*4+me)&63][j]++;
        }
    }
    mat.set(A,64);
}
VPII ban[SIZE];
int input[SIZE];
void solve(VPII &pp,int n,LL ret[]){
    REP(i,4)ret[i]=0;
    sort(ALL(pp));
    int now=0;
    MS0(a);
    a[63]=1;
    REP(i,SZ(pp)){
        if(now+1!=pp[i].F){
            LL res[64];
            mat.get(a,pp[i].F-now-1,res);
            memcpy(a,res,sizeof(LL)*64);
        }
        LL tmp[64]={};
        REP(j,64)REP(k,64)ADD(tmp[j],tran[pp[i].S-1][j][k]*a[k]);
        memcpy(a,tmp,sizeof(LL)*64);
        now=pp[i].F;
    }
    if(now!=n){
        LL res[64];
        mat.get(a,n-now,res);
        memcpy(a,res,sizeof(LL)*64);
    }
    REP(i,64)ADD(ret[i&3],a[i]);
}
int main(){
    MOD=998244353;
    int n; R(n);
    FOR(i,1,n)R(input[i]);
    int m; R(m);
    REP(i,m){
        int x,y,v; R(x,y,v);
        ban[x].PB({y,v});
    }
    build();
    LL dp[2][4]={};
    int now=0,nxt=1;
    dp[now][0]=1;
    FOR(i,1,n){
        LL ret[4];
        solve(ban[i],input[i],ret);
        MS0(dp[nxt]);
        REP(j,4)REP(k,4){
            ADD(dp[nxt][j^k],dp[now][j]*ret[k]);
        }
        swap(now,nxt);
    }
    W(dp[now][0]);
    return 0;
}