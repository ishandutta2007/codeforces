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
#define MS0(X) memset((X), 0, sizeof((X))
#define MS1(X) memset((X), -1, sizeof((X))
#define LEN(X) strlen(X)
#define F first
#define S second
#define MOD 1000000007
using namespace std;
int dp[1<<24],a[2],v[1<<24];
int main(){
    int i,j,k,n;
    RI(n);
    for(i=0;i<n;i++)RI(v[1<<i]);
    RI(k);
    for(i=0;i<k;i++)RI(a[i]);
    dp[0]=1;
    for(i=1;i<(1<<n);i++){
        v[i]=v[i-(i&-i)]+v[i&-i];
        if(v[i]!=a[0]&&v[i]!=a[1]){
            for(j=0;(1<<j)<=i;j++){
                if((i>>j)&1){
                    dp[i]+=dp[i-(1<<j)];
                    if(dp[i]>=MOD)dp[i]-=MOD;
                }
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
}