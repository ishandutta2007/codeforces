#include <bits/stdc++.h>
using namespace std;


int n,m,k;
vector<int> q;
bool used[100005];
int clr[100005];
vector<int> v[100005];
vector<int> vv[100005];
int all;
bool block[100005];
int cnt[100005];
int a[100005];
bool into[100005];

void dfs1(int x) {
    used[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used[to]==false) dfs1(to);
    }
    q.push_back(x);
}

void dfs2(int x,int y) {
    clr[x]=y;
    ++cnt[y];
    for (int i=0;i<vv[x].size();++i) {
        int to=vv[x][i];
        if (!clr[to]) dfs2(to,y);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    vector<pair<int,int> > qq;
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        int xx=(a[x]+1)%k;
        int yy=(a[y]+1)%k;
        if (xx==a[y]) { v[x].push_back(y); vv[y].push_back(x); }
        if (yy==a[x]) { v[y].push_back(x); vv[x].push_back(y); }
    }
    for (int i=1;i<=n;++i)
        if (used[i]==false) dfs1(i);
    reverse(q.begin(),q.end());
    for (int i=0;i<q.size();++i) {
        int x=q[i];
        if (!clr[x]) dfs2(x,++all);
    }
    for (int i=1;i<=n;++i)
    for (int j=0;j<v[i].size();++j) {
        int to=v[i][j];
        if (clr[i]!=clr[to]) into[clr[i]]=true;
    }
    int min_comp=1e9;
    int comp=1;
    for (int i=1;i<=all;++i)
    if (into[i]==false && cnt[i]<min_comp) {
        min_comp=cnt[i];
        comp=i;
    }
    cout<<cnt[comp]<<'\n';
    for (int i=1;i<=n;++i)
        if (clr[i]==comp) cout<<i<<" ";
}