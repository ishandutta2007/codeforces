#include <bits/stdc++.h>
using namespace std;


long long n,m;
long long x,y,z;
vector<pair<long long,long long> > v[200005];
long long dp[300];
bool used[2000005];
long long len[100005];

void dfs(long long x){
    used[x]=true;
    for (long long i=0;i<v[x].size();++i) {
        long long to=v[x][i].first;
        if (used[to]) {
            long long l=len[x]^len[to]^v[x][i].second;
            for (long long j=32;j>=0;--j) if ((!dp[j] || dp[j]>l) && l&(1<<j)){
                dp[j]=l;
            } else l=min(l,l^dp[j]);
        } else {
            len[to]=len[x]^v[x][i].second;
            dfs(to);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (long long i=1;i<=m;++i) {
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    dfs(1);
    long long ans=len[n];
    for (long long i=32;i>=0;--i)
        ans=min(ans,ans^dp[i]);
    cout<<ans;
}