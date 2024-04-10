#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3010;
int n,a[N],c[N],m;LL ans=1e18,dp[N][N];
void cmin(LL &x,LL y){y<x?x=y:0;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),c[i]=a[i]-=i;
    sort(c+1,c+n+1);m=unique(c+1,c+n+1)-c-1;
    for(int i=1;i<=n;i++)a[i]=lower_bound(c+1,c+m+1,a[i])-c;
    for(int i=1;i<=n;i++){
        LL mn=1e18;
        for(int j=1;j<=m;j++){
            cmin(mn,dp[i-1][j]);
            dp[i][j]=mn+abs(c[a[i]]-c[j]);
        }
    }
    for(int i=1;i<=m;i++)cmin(ans,dp[n][i]);
    cout<<ans;
    return 0;
}