#include<bits/stdc++.h>
using namespace std;

int n,m,k,dep[200005],tot=1;
vector<pair<int,int>> g[200005];
vector<int> chs[200005];
char ans[200005];

void dfs(int x){
    if(x>n){
        cout<<ans+1<<'\n';
        k--;
        if(!k)exit(0);
        return;
    }
    for(auto &y:chs[x]){
        ans[y]='1';
        dfs(x+1);
        ans[y]='0';
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
        ans[i]='0';
    }
    queue<int> q;
    q.emplace(1);
    dep[1]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto &[y,z]:g[x]){
            if(!dep[y]){
                dep[y]=dep[x]+1;
                q.emplace(y);
            }
        }
    }
    for(int i=2;i<=n;i++){
        for(auto &[y,z]:g[i])if(dep[y]+1==dep[i]){
            chs[i].emplace_back(z);
        }
        tot=min((long long)k,tot*(long long)chs[i].size());
    }
    cout<<tot<<'\n';
    dfs(2);

    return 0;
}