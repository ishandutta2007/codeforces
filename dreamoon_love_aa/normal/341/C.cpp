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
#define SIZE 2001
#define MOD 1000000007
int a[SIZE],used[SIZE];
long long dp[SIZE][SIZE];
int main(){
    DRI(n);
    int cnt=0,cnt2=0;
    bool err=0;
    REPP(i,1,n+1){
        RI(a[i]);
        if(a[i]==i)err=1;
        if(a[i]!=-1)used[a[i]]=1;
        else cnt++;
    }
    if(err){
        puts("0");
        return 0;
    }
    if(cnt==0){
        puts("1");
        return 0;
    }
    REPP(i,1,n+1){
        if(a[i]==-1&&!used[i])cnt2++;
    }
    dp[0][0]=1;
    REPP(i,1,SIZE){
        dp[i][0]=dp[i-1][0]*i%MOD;
        REPP(j,1,i+1){
            if(j>1)dp[i][j]+=(j-1)*dp[i-1][j-2];
            if(i>j)dp[i][j]+=(i-j)*dp[i-1][j-1];
            dp[i][j]%=MOD;
        }
    }
    cout<<dp[cnt][cnt2]<<endl;
    return 0;
}