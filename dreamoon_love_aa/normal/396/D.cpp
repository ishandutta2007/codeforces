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
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
long long dp[SIZE],fac[SIZE],dp2[SIZE];
int BIT[SIZE],a[SIZE];
void ins(int x){
    while(x<SIZE){
        BIT[x]++;
        x+=x&-x;
    }
}
int qq(int x){
    int res=0;
    while(x){
        res+=BIT[x];
        x-=x&-x;
    }
    return res;
}
int main(){
    DRI(n);
    dp[1]=0;
    fac[0]=1;
    REPP(i,1,n+1)fac[i]=fac[i-1]*i%MOD;
    REPP(i,2,n+1){
        dp[i]=dp[i-1]*i%MOD+fac[i-1]*(((long long)i*(i-1)/2)%MOD)%MOD;
        dp[i]%=MOD;
    }
    REP(i,n)RI(a[i]);
    ins(a[n-1]);
    dp2[n-1]=1;
    for(int i=n-2;i>=0;i--){
        int x=a[i];
        int now=qq(x);
        ins(x);
        dp2[i]=now*fac[n-i-1]+dp2[i+1];
        dp2[i]%=MOD;
    }
    MS0(BIT);
    long long an=0;
    REP(i,n){
        int x=a[i];
        ins(x);
        int now=x-qq(x);
        an+=dp[n-i-1]*now%MOD;
        an%=MOD;
        an+=((long long)now*(now-1)/2)%MOD*fac[n-i-1]%MOD;
        an%=MOD;
        an+=(dp2[i]-now*fac[n-i-1]%MOD)*now;
        an%=MOD;
        if(an<0)an+=MOD;
    }
    cout<<an<<endl;
    return 0;
}