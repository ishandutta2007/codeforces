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
const int MATRIX_SIZE = 500;
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
struct Matrix_Power{
    LL AA[60][MATRIX_SIZE][MATRIX_SIZE],aa[62][MATRIX_SIZE];
    int N;
    void set(LL _A[][MATRIX_SIZE],int _N,LL bb = (LL)1e18){
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
    LL get(LL _a[],LL v){
        MS0(aa);
        REP(i,N)aa[0][i]=_a[i];
        REP(i,61){
            if((1LL<<i)>v)return aa[i][N-1];
            if((v>>i)&1){
                REP(j,N)REP(k,N){
                    aa[i+1][j]+=AA[i][j][k]*aa[i][k];
                    aa[i+1][j]%=MOD;
                }
            }
            else REP(j,N)aa[i+1][j]=aa[i][j];
        }
        return -1;
    }
}mat;
LL A[1000][MATRIX_SIZE];
LL a[SIZE];
int main(){
    MOD = 1000003;
    int c,w,h;
    R(c,w,h);
    REP(i,w+1){
        if(i<w)A[i][i+1]=1;
        else{
            REP(j,w+1)A[i][i-j]=mypow(h,j);
        }
    }
    a[w-1]=a[w]=1;
    mat.set(A,w+1,c*2);
    W(mat.get(a,c));
    return 0;
}