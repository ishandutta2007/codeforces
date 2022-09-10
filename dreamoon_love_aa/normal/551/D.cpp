#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
int MOD = 1e9+7;
const int SIZE = 1e6+10;
// template end here
const int MATRIX_SIZE = 2;
struct Matrix_Power{
    LL AA[62][MATRIX_SIZE][MATRIX_SIZE],aa[62][MATRIX_SIZE];
    int N;
    void set(LL _A[][MATRIX_SIZE],int _N,LL bb = (LL)1e18){
        N=_N;
        REP(i,N)
            REP(j,N)AA[0][i][j]=_A[i][j];
        REPP(round,1,62){
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
}MM;
LL A[1000][MATRIX_SIZE];
LL a[SIZE];
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
int main(){
    LL n,k,l,m;
    cin>>n>>k>>l>>m;
    int ma_bit=0;
    while((1LL<<ma_bit)<=k)ma_bit++;
    if(ma_bit>l){
        puts("0");
        return 0;
    }
    if(l==0){
        if(!k)cout<<1%m<<endl;
        else cout<<0<<endl;
        return 0;
    }
    MOD=m;
    A[0][1]=A[1][0]=A[1][1]=1;
    MM.set(A,2);
    a[0]=a[1]=1;
    LL me=MM.get(a,n);
    LL you=mypow(2,n)-me;
    you%=MOD;
    if(you<0)you+=MOD;
    LL res=1;
    REP(i,l){
        if((k>>i)&1)res=res*you%MOD;
        else res=res*me%MOD;
    }
    cout<<res%MOD<<endl;
    return 0;
}