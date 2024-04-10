#include<bits/stdc++.h>
using namespace std;
const int N=105,M=998244353,E=502;
const long long inf=5000000000000000000ll;
int t,n,p[5005],a[5005];
long long dp[5005][5005],C[5005][5005];
long long CC(int n,int m){
    return m<0||n<m?0:C[n][m];
}
long long dfs(int i,int u){
    if(i==0&&u==n/2-1)
        return 1;
    if(i==0)
        return 0;
    if(dp[i][u]!=-1)
        return dp[i][u];
    long long X=CC(u-(n-1-i-u)+(u==n/2-1),i-p[i]-1)*dfs(p[i],u+1);
    long long Y=CC(u-(n-1-i-u)+(u==n/2-1),i-p[i])*dfs(p[i],u);
    // cout<<i<<' '<<u<<' '<<Y<<' '<<CC(u-(n-1-i-u)+(u==n/2-1),i-p[i])<<endl;
    return dp[i][u]=(X+Y)%M;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d",&t);
    for(int i=0;i<=5000;++i){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;++j)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
    }
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        for(int i=1;i<=n;++i)
            if(a[i]==a[i-1])
                p[i]=p[i-1];
            else
                p[i]=i-1;
        for(int i=0;i<=n;++i)
            for(int j=0;j<=n;++j)
                dp[i][j]=-1;
        if(a[n]==a[n-1])
            puts("0");
        else
            cout<<(dfs(n-1,0)%M+M)%M<<endl;
    }
}