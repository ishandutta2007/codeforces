#include <bits/stdc++.h>
using namespace std;



int n,k;
long long s;
long long dp[2][155][(155)*(156)/2];
long long a[155];

inline void update(int x){
    for (int i=0;i<=k;++i)
        for (int j=0;j<=(n)*(n+1)/2;++j)
        dp[x][i][j]=1e15;
    for (int j=0;j<=(n)*(n+1)/2;++j)
        dp[x][0][j]=0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>s;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    if (s>(n)*(n-1)/2) {
        sort(a+1,a+n+1);
        for (int i=2;i<=k;++i)
        a[1]+=a[i];
        cout<<a[1];
        return 0;
    }
    update(0);
    int x=0,y=1;
    for (int i=1;i<=n;++i) {
        swap(x,y);
        update(x);
        for (int j=0;j<=k;++j)
            for (int ii=0;ii<=(n)*(n+1)/2;++ii)
                dp[x][j][ii]=dp[y][j][ii];
        for (int j=1;j<=k;++j)
            for (int ii=i;ii<=(n)*(n+1)/2;++ii)
                dp[x][j][ii]=min(dp[x][j][ii-1],min(dp[x][j][ii],dp[y][j-1][ii-i]+a[i]));
    }
    long long ans=1e18;
    for (int i=1;i<=(n)*(n+1)/2;++i)
        if (i-(k)*(k+1)/2<=s) ans=min(ans,dp[x][k][i]);
    cout<<ans;
}