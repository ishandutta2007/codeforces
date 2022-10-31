#include <bits/stdc++.h>
using namespace std;


int n,m;
int ans;
int used[300005];
int dp[300005];
vector<int> v[300005],q;
string s;

void dfs(int x,int y=-1) {
    used[x]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used[to]==0) dfs(to,x);
        else if (used[to]==1) {
            cout<<"-1";
            exit(0);
        }
    }
    used[x]=2;
}


void dfs2(int x) {
    used[x]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used[to]==0) dfs2(to);
    }
    q.push_back(x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    for (int i=1;i<=n;++i)
        dfs(i);
    memset(used,0,sizeof(used));
    for (int i=1;i<=n;++i)
        if (used[i]==false) dfs2(i);
    for (int i=0;i<26;++i) {
        memset(dp,0,sizeof(dp));
        for (int j=0;j<q.size();++j) {
            int x=q[j];
            int cur=0;
            if (s[x-1]-'a'==i) ++cur;
            dp[x]=cur;
            for (int k=0;k<v[x].size();++k) {
                int to=v[x][k];
                dp[x]=max(dp[x],dp[to]+cur);
            }
            if (dp[x]>ans) ans=dp[x];
        }
    }
    cout<<ans;
}