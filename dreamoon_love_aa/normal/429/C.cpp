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
int a[24];
int dp[13][1<<12][24];
int m,sum[1<<12];
int main(){
    DRI(n);
    REP(i,n)RI(a[i]);
    sort(a,a+n);
    reverse(a,a+n);
    int one=0;
    while(one<n&&a[one]!=1)one++;
    m=one;
    one=n-one;
    if(m>=one||a[0]==a[1]){
        puts("NO");
        return 0;
    }
    if(m==0){
        if(one==1)puts("YES");
        else puts("NO");
        return 0;
    }
    for(int i=0;i<m;i++)sum[1<<i]=a[i];
    for(int i=1;i<(1<<m);i++){
        if(i&(i-1)){
            sum[i]=sum[i-(i&-i)]+sum[i&-i];
        }
    }
    dp[0][(1<<m)-2][one]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<(1<<m);j++){
            if((j>>i)&1)continue;
            for(int k=0;k<=one;k++){
                if(dp[i][j][k]){
                    if(k>=a[i]-1&&a[i]-1!=1)dp[i+1][j][k-(a[i]-1)]=1;
                    for(int k2=j;k2;k2=(k2-1)&j){
                        if((k2&(k2-1))==0&&a[i]-sum[k2]-1==0)continue;
                        if(sum[k2]<a[i]&&a[i]-sum[k2]-1<=k){
                            dp[i+1][j-k2][k-(a[i]-sum[k2]-1)]=1;
                        }
                    }
                }
            }
        }
    }
    if(dp[m][0][0])puts("YES");
    else puts("NO");
    return 0;
}