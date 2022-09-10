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
const int MOD = (int)1e9+7;
const int SIZE = 100000;
int p[SIZE],pn;
long long fac[SIZE],inv[SIZE];
long long mypow(long long x,long long y){
    long long res=1;
    while(y){
        if(y&1)res=res*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return res;
}
void pre(){
    fac[0]=1;
    REPP(i,1,SIZE)fac[i]=fac[i-1]*i%MOD;
    inv[SIZE-1]=mypow(fac[SIZE-1],MOD-2);
    for(int i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
long long C(int x,int y){
    return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
long long f(int x,int n){
    return C(x+n-1,x);
}
int main(){
    pre();
    DRI(n);
    REP(i,n){
        DRI(x);
        for(int j=2;j*j<=x;j++){
            while(x%j==0){
                p[pn++]=j;
                x/=j;
            }
        }
        if(x!=1)p[pn++]=x;
    }
    sort(p,p+pn);
    long long an=1;
    for(int i=0,j;i<pn;i=j){
        for(j=i+1;j<pn&&p[j]==p[i];j++);
        int nn=j-i;
        an=an*f(nn,n)%MOD;
    }
    cout<<an<<endl;
    return 0;
}