#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
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
#define F first
#define S second
using namespace std;
const int SIZE = 100;
const int MOD = 1e9+7;
long long n;
int k;
long long A[2][SIZE][SIZE],a[2][SIZE],C[44][44];
long long mypow(long long x,long long y){
    long long res=1;
    while(y){
        if(y&1)res=res*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return res;
}
void init(int k){
    REP(i,44){
        C[i][0]=1;
        REPP(j,1,i+1){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
    REP(i,k+1){
        a[0][i]=1;
        a[0][i+k+1]=2*mypow(2,i)%MOD;
    }
    a[0][k*2+2]=1;

    A[0][k*2+2][k*2+2]=1;
    A[0][k*2+2][k*2+1]=1;
    REP(i,k+1){
        A[0][i][k+1+i]=1;
    }
    REP(i,k+1){
        REP(j,i+1){
            A[0][i+k+1][j+k+1]=C[i][j];
            A[0][i+k+1][j]=C[i][j]*mypow(2,i-j)%MOD;
        }
    }
}
int main(){
    cin>>n>>k;
    if(n==1){
        puts("1");
        return 0;
    }
    init(k);
    n-=1;
    int now=0;
    int mm=2*k+3;
    while(n){
        if(n&1){
            MS0(a[now^1]);
            REP(i,mm)REP(j,mm){
                a[now^1][i]+=A[now][i][j]*a[now][j];
                a[now^1][i]%=MOD;
            }
        }
        else REP(i,mm)a[now^1][i]=a[now][i];
        MS0(A[now^1]);
        REP(i,mm)REP(j,mm)REP(k2,mm){
            A[now^1][i][k2]+=A[now][i][j]*A[now][j][k2];
            A[now^1][i][k2]%=MOD;
        }
        now^=1;
        n>>=1;
    }
    cout<<a[now][mm-1];
    return 0;
}