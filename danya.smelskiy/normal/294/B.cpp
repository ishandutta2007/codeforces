#include <bits/stdc++.h>
using namespace std;

int n;
int dp[2][202][202];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    dp[0][0][0]=true;
    int x=0,y=1;
    for (int i=1;i<=n;++i) {
        int z1,z2;
        cin>>z1>>z2;
        swap(x,y);
        for (int j=0;j<=n+n;++j)
            for (int k=0;k<=n+n;++k)
                dp[x][j][k]=false;
        for (int j=0;j<=n+n;++j)
            for (int k=0;k<=n+n;++k)
        if (dp[y][j][k]) {
            dp[x][j+z1][k]=true;
            if (k+z2<=n+n) dp[x][j][k+z2]=true;
        }
    }
    for (int i=0;i<=n*2;++i)
        for (int j=0;j<=i;++j)
    if (dp[x][i][j]==true) {
        cout<<i;
        return 0;
    }
}