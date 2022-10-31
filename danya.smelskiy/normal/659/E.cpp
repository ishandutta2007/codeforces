#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
vector<int> v[1000005];
bool used[1000005];
bool t;
int ans;
void dfs(int x,int p){
    used[x]=1;
    for (int j=0;j<v[x].size();++j){
        int to=v[x][j];
        if (to==p) continue;
        if (used[to]==1) t=true;
        else if (used[to]==0) dfs(to,x);
    }
    used[x]=2;
}

int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i){
        if (used[i]==0) {
            t=false;
            dfs(i,-1);
            if (t==false) ++ans;
        }
    }
    cout<<ans;
}