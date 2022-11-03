#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>

using namespace std;

int a[12]={0},mod=1000000007;
int C[101][101]={0};
int dp[11][101]={0};

int solve(int n) {
/*  int ret=0,s=0;
    for(int i=0;i<10;++i) s+=a[i];
    for(int j=0;s+j<=n-(s==a[0]);++j) {
        int tmp=a[0];
        a[0]+=j;
        int cur=1;
        for(int i=0;i<10;++i) {
            if (i==0) cur=(1LL*cur*C[n-1][a[i]])%mod;
            else cur=(1LL*cur*C[n][a[i]])%mod;
            n-=a[i];
        }
        for(int i=0;i<n;++i) cur=(9LL*cur)%mod;
        ret=(ret+cur)%mod;
        a[0]=tmp;
    }*/
    int ret=0;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<10;++i) {
        for(int j=0;j<=n;++j)
            if (dp[i][j]) {
                for(int k=a[i];k<=n-(i==0);++k) {
                    if (i==0) {
                        if (j+k<=n) dp[i+1][j+k]=(dp[i+1][j+k]+1LL*dp[i][j]*C[n-1][k])%mod;
                    } else {
                        if (j+k<=n&&n-j>=k) dp[i+1][j+k]=(dp[i+1][j+k]+1LL*dp[i][j]*C[n-j][k])%mod;
                    }
                }
            }
    }
    return dp[10][n];
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    for(int i=0;i<10;++i)
        cin >> a[i];
    int ans=0,s=0;
    for(int i=0;i<10;++i) s+=a[i];
    C[0][0]=1;
    for(int i=1;i<=100;++i) {
        C[i][0]=1;
        for(int j=1;j<=i;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    for(int i=max(a[0]+1,s);i<=n;++i)
        ans=(ans+solve(i))%mod;
    cout << ans << endl;
    return 0;
}