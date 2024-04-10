#include <bits/stdc++.h>
using namespace std;


int n;
int a[6005];
short mt[1000005];
int b[6005];
short dp1[6005][6005];
short dp2[6005][6005];
vector<int> v[6005];
int ans;
short z=1;
int last;
void dfs(int x,int y){
    for (int i=a[x];i<=last;++i) {
        dp1[x][i]=1;
    }
    for (int i=a[x];i>0;--i)
        dp2[x][i]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x);
        for (int i=1;i<=last;++i) {
            ans=max(ans,dp1[to][i]+dp2[x][i+1]);
            ans=max(ans,dp2[to][i]+dp1[x][i-1]);
        }
        for (short i=1;i<=last;++i) {
            if (i==a[x]) dp1[x][i]=max(dp1[x][i],(short)(dp1[to][i-1]+z));
            dp1[x][i]=max(dp1[x][i],dp1[to][i]);
            dp1[x][i]=max(dp1[x][i],dp1[x][i-1]);
        }
        for (short i=last;i>0;--i) {
            if (i==a[x]) dp2[x][i]=max(dp2[x][i],(short)(dp2[to][i+1]+z));
            dp2[x][i]=max(dp2[x][i],dp2[to][i]);
            dp2[x][i]=max(dp2[x][i],dp2[x][i+1]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        b[i]=a[i];
    }
    for (int i=1;i<n;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    sort(b+1,b+n+1);
    for (int i=1;i<=n;++i) if (i==1 || b[i]!=b[i-1]) {
        ++last;
        mt[b[i]]=last;
    }
    for (int i=1;i<=n;++i)
    a[i]=mt[a[i]];
    dfs(1,-1);
    cout<<ans;
}