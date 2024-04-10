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
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
LL A[2][2][2],a[2][2][2];
void ADD(LL& x,LL v){
    x=(x+v)%MOD;
}
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
    A[0][0][0]=MOD-1;
    A[0][0][1]=1;
    A[0][1][1]=2;
    DRI(n);
    int now=0;
    REP(i,n){
        LL y;
        a[now][0][0]=a[now][1][1]=1;
        a[now][0][1]=a[now][1][0]=0;
        scanf("%I64d",&y);
        while(y){
            if(y&1){
                MS0(a[now^1]);
                REP(i,2)REP(j,2)REP(k,2){
                    ADD(a[now^1][i][k],a[now][i][j]*A[now][j][k]);
                }
            }
            else REP(i,2)REP(j,2)a[now^1][i][j]=a[now][i][j];
            MS0(A[now^1]);
            REP(i,2)REP(j,2)REP(k,2)
                ADD(A[now^1][i][k],A[now][i][j]*A[now][j][k]);
            y>>=1;
            now^=1;
        }
        REP(i,2)REP(j,2)A[now][i][j]=a[now][i][j];
    }
    printf("%I64d/%I64d\n",(A[now][0][0]+A[now][0][1])*mypow(2,MOD-2)%MOD,(A[now][1][0]+A[now][1][1])*mypow(2,MOD-2)%MOD);
    return 0;
}