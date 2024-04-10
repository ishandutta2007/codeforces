#include <bits/stdc++.h>
using namespace std;



int n,m,s;
int x,y;
vector<int> v[5005];
vector<int> vv[5005];
vector<int> q;
bool used[5005];
int ans;
int all;
int clr[5005];

void dfs(int x) {
    used[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (!used[to]) dfs(to);
    }
    q.push_back(x);
}

void dfs2(int x) {
    clr[x]=all;
    for (int i=0;i<vv[x].size();++i) {
        int to=vv[x][i];
        if (!clr[to]) dfs2(to);
    }
}


bool used3[5005];

void dfs3(int x) {
    used3[x]=true;
    for (int i=0;i<vv[x].size();++i) {
        int to=vv[x][i];
        if (used3[to]==false) dfs3(to);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>s;
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        vv[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        if (!used[i]) dfs(i);
    for (int i=q.size()-1;i>=0;--i) {
        int x=q[i];
        if (clr[x]) continue;
        ++all;
        dfs2(x);
    }
    for (int i=1;i<=n;++i)
        vv[i].clear();
    memset(used,false,sizeof(used));
    for (int i=1;i<=n;++i) {
        for (int j=0;j<v[i].size();++j) {
            int to=v[i][j];
            if (clr[i]!=clr[to]) {
                vv[clr[i]].push_back(clr[to]);
                used[clr[to]]=true;
            }
        }
    }
    dfs3(clr[s]);
    for (int i=1;i<=all;++i)
        if (!used[i] && !used3[i]) ++ans;
    cout<<ans;
}