#include<bits/stdc++.h>
using namespace std;
const int N=105,M=998244353,E=502;
const long long inf=5000000000000000000ll;
int n,a[205][205],t[205][205],ans[205];
long long p[205][205],dp[205][205],s[205][205];
long long dfs(int l,int r){
    if(l==r){
        t[l][r]=l;
        return p[l][r];
    }
    if(l>r)
        return 0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    dp[l][r]=inf;
    for(int i=l;i<=r;++i){
        long long z=dfs(l,i-1)+dfs(i+1,r);
        if(z<dp[l][r]){
            dp[l][r]=z;
            t[l][r]=i;
        }
    }
    dp[l][r]+=p[l][r];
    return dp[l][r];
}
void dd(int fa,int l,int r){
    if(l>r)
        return;
    ans[t[l][r]]=fa;
    dd(t[l][r],l,t[l][r]-1);
    dd(t[l][r],t[l][r]+1,r);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            s[i][j]=s[i][j-1]+a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j)
            for(int k=1;k<=n;++k)
                if(k<i||k>j)
                    p[i][j]+=s[k][j]-s[k][i-1];
    memset(dp,-1,sizeof(dp));
    dfs(1,n);
    dd(0,1,n);
    for(int i=1;i<=n;++i)
        printf("%d ",ans[i]);
}