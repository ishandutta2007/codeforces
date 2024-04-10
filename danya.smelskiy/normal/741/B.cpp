#include <bits/stdc++.h>
using namespace std;

long long ans;
int n,m,w;
int x,y;
vector<int> v[1005];
long long sum[1005];
long long p[1005];
long long a[1005];
int sz;
long long b[1005];
bool used[1005];
vector<int> q[1005];
pair<bool,long long> dp[1005];
pair<bool,long long> dp2[1005];

void dfs(int x,int y){
    q[y].push_back(x);
    sum[y]+=a[x];
    p[y]+=b[x];
    used[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used[to]==false) {
            dfs(to,y);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>m>>w;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        cin>>b[i];
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
    if (used[i]==false) {
        ++sz;
        dfs(i,sz);
    }
    dp[0]=make_pair(true,0);
    for (int i=1;i<=sz;++i) {
        for (int j=sum[i];j<=w;++j) {
            if (dp[j-sum[i]].first) {
                dp2[j].first=true;
                dp2[j].second=max(dp2[j].second,dp[j-sum[i]].second+p[i]);
            }
        }
        for (int j=0;j<q[i].size();++j) {
            x=q[i][j];
            for (int k=a[x];k<=w;++k) {
                if (dp[k-a[x]].first) {
                    dp2[k].first=true;
                    dp2[k].second=max(dp2[k].second,dp[k-a[x]].second+b[x]);
                }
            }
        }
        for (int k=0;k<=w;++k)
        if (dp2[k].first==true) {
            dp[k].first=true;
            dp[k].second=max(dp[k].second,dp2[k].second);
        }
    }
    for (int i=0;i<=w;++i)
    if (dp[i].first) {
        ans=max(ans,dp[i].second);
    }
    cout<<ans;
}