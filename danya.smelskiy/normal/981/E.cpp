#include <bits/stdc++.h>
using namespace std;

int n,m,sz;
vector<int> t[500005];
int x,y,z;
bitset<100005> dp[105];
bitset<100005> ans;

void update(int l,int r,int ll,int rr,int x,int z) {
    if (l>r || ll>r || l>rr || ll>rr) return ;
    if (l>=ll && r<=rr) {
        t[x].push_back(z);
        return;
    }
    int mid=(l+r)>>1;
    update(l,mid,ll,rr,x+x,z);
    update(mid+1,r,ll,rr,x+x+1,z);
}

void dfs(int l,int r,int x,int y) {
    if (l>r || l>n) return;
    dp[y]=dp[y-1];
    for (int i=0;i<t[x].size();++i) {
        int z=t[x][i];
        dp[y]|=(dp[y]<<z);
    }
    if (l==r) {
        ans|=dp[y];
        return;
    }
    int mid=(l+r)>>1;
    dfs(l,mid,x+x,y+1);
    dfs(mid+1,r,x+x+1,y+1);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=m;++i) {
        cin>>x>>y>>z;
        update(1,sz,x,y,1,z);
    }
    dp[0][0]=1;
    dfs(1,sz,1,1);
    vector<int> qq;
    qq.clear();
    for (int i=1;i<=n;++i)
        if (ans[i]==1) qq.push_back(i);
    cout<<qq.size()<<'\n';
    for (int i=0;i<qq.size();++i)
        cout<<qq[i]<<" ";
}