#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
int dp[75][75];
int f[75][75][75][75],mx[75][75];
int a[75][75];
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int x=1;x<=j;x++)
                for(int y=0;y<k;y++) {
                    f[i][j][x][y]=f[i][j-1][x][y];
                    if(f[i][j - 1][x - 1][((y - a[i][j])%k + k) % k]||((y - a[i][j])%k + k) % k==0) {
                        f[i][j][x][y] = max(f[i][j - 1][x][y],
                                            f[i][j - 1][x - 1][((y - a[i][j]) % k + k) % k] + a[i][j]);
                    }
                    if(x<=m/2) mx[i][y]=max(mx[i][y],f[i][j][x][y]);
                }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++)
            for(int x=0;x<k;x++)
                if((mx[i][x]||x==0)&&(dp[i-1][(j-x+k)%k]||(j-x+k)%k==0))
                dp[i][j]=max(dp[i][j],dp[i-1][(j-x+k)%k]+mx[i][x]);
    }
    printf("%d\n",dp[n][0]);
    return 0;
}