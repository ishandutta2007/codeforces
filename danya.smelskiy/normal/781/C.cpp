#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int z,x,y;
vector<int> v[200005];
vector<int> ans[200005];
bool used[200005];
vector<int> q;
void dfs(int x){
    used[x]=true;
    q.push_back(x);
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (used[to]==false) {
            dfs(to);
            q.push_back(x);
        }
    }
}
int main(){
    cin>>n>>m>>k;
    z=(n*2)/k;
    if ((n*2)%k) ++z;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    int last=0;
    for (int i=1;i<=k;++i){
        int r=last+z;
        for (;last<r && last<q.size();++last)
            ans[i].push_back(q[last]);
        if (ans[i].size()==0) ans[i].push_back(1);
        cout<<ans[i].size()<<" ";
        for (int j=0;j<ans[i].size();++j)
            cout<<ans[i][j]<<" ";
        cout<<'\n';
    }
}