#include <bits/stdc++.h>
using namespace std;


long long n,k;
long long dp[5005][5005];
long long dp2[805][5005];
long long a[5005][5005];
void solve(long long x,long long l,long long r,long long ll,long long rr){
    if (l>r) return;
    long long mid=(l+r)>>1;
    long long res=1e15;
    long long pos=ll;
    for (int i=ll;i<min(mid,rr+1);++i){
        long long q=dp2[x-1][i]+dp[i+1][mid];
        if (q<res) {
            res=q;
            pos=i;
        }
    }
    dp2[x][mid]=res;
    if (l==r) return;
    solve(x,l,mid-1,ll,pos);
    solve(x,mid+1,r,pos,rr);
}
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            char c;
            cin>>c;
            a[i][j]=c-'0';
        }
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n-i+1;++j) if (i==1) dp[j][j]=a[j][j];
        else dp[j][j+i-1]=(dp[j][j+i-2]+dp[j+1][j+i-1]-dp[j+1][j+i-2]+a[j][j+i-1]+a[j+i-1][j]);
    for (int i=1;i<=n;++i)
        dp2[0][i]=1e15;
    for (int i=1;i<=k;++i)
        solve(i,0,n,0,n);
    cout<<dp2[k][n]/((long long)2);
}