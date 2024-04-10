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
const int SIZE = 3610;
int row[SIZE],col[SIZE];
LL dp_row[SIZE],dp_col[SIZE];
LL tmp[SIZE],C[SIZE][SIZE],fac[SIZE];
int calc(int AA[], LL dp_AA[],int n){
    int ma=0;
    dp_AA[0]=1;
    for(int i=1,j;i<=n;i=j){
        if(AA[i]){
            j=i+1;
            continue;
        }
        for(j=i+1;j<=n&&!AA[j];j++);
        int num=j-i;
        for(int k=num/2;k>0;k--){
            tmp[k]=C[k+(num-k*2)][k];
        }
        for(int k1=ma;k1>=0;k1--){
            for(int k2=num/2;k2>0;k2--){
                ADD(dp_AA[k1+k2],dp_AA[k1]*tmp[k2]);
            }
        }
        ma+=num/2;
    }
    return ma;
}
int main(){
    MOD=998244353;
    C[0][0]=1;
    REPP(i,1,SIZE){
        C[i][0]=1;
        FOR(j,1,i){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=MOD)C[i][j]-=MOD;
        }
    }
    fac[0]=1;
    REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
    int h,w,n;
    R(h,w,n);
    FOR(i,1,n){
        REP(j,2){
            int x,y;
            R(x,y);
            row[x]=1;
            col[y]=1;
        }
    }
    int col_zero=count(col+1,col+w+1,0);
    int row_zero=count(row+1,row+h+1,0);
    int row_ma=calc(row,dp_row,h);
    int col_ma=calc(col,dp_col,w);
    LL an=0;
    for(int i=0;i<=row_ma&&i<=col_zero;i++){
        if(!dp_row[i])continue;
        for(int j=0;j<=col_ma&&i*2+j<=row_zero&&i+j*2<=col_zero;j++){
            ADD(an,dp_row[i]*dp_col[j]%MOD*C[row_zero-2*i][j]%MOD*C[col_zero-2*j][i]%MOD*fac[i]%MOD*fac[j]);
        }
    }
    W(an);
    return 0;
}