#include <bits/stdc++.h>
using namespace std;


int n,m,s,e;
vector<int> v[100005];
int a[100005],b[100005];
int dp[100005][305];
inline int get(int x,int y){
    if (!v[x].size()) return m+1;
    ++y;
    int l=0;
    int r=(v[x].size())-1;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (v[x][mid]>=y) r=mid;
        else l=mid;
    }
    if (v[x][l]>=y) r=l;
    if (v[x][r]>=y) return v[x][r];
    else return m+1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>s>>e;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=m;++i) {
        cin>>b[i];
        v[b[i]].push_back(i);
    }
    for (int i=0;i<=n+1;++i)
        for (int j=0;j<=s/e;++j)
            dp[i][j]=1e9;
    dp[0][0]=0;
    int ans=0;
    for (int i=0;i<=n+1;++i) {
        for (int j=0;j<=s/e;++j) if (dp[i][j]<1e9) {
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            if (i-1+dp[i][j]+j*e<=s) ans=max(ans,j);
            if (i && i<=n) {
                int x=get(a[i],dp[i][j]);
                if (x<=m) dp[i+1][j+1]=min(dp[i+1][j+1],x);
            }
        }
    }
    cout<<ans;
}