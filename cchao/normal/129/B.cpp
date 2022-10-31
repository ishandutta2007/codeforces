#include<bits/stdc++.h>
using namespace std;
int cnt[200],visit[200];
bool flag;
vector<int>g[1000];
void dfs(int u){
    if(visit[u]||!cnt[u]) return;
    visit[u]=1;
    int c=0;
    for(int i=0;i<g[u].size();i++){
        if(cnt[g[u][i]]) c++;
    }
    for(int i=0;i<g[u].size();i++){
        if(cnt[g[u][i]])
            dfs(g[u][i]);

    }
    if(c==1) {
        cnt[u]=0,flag=true;
    }
}
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        cnt[u]=cnt[v]=1;
    }
    int ans=0;
    while(true) {
        flag = false;
        memset(visit,0,sizeof visit);
        for(int i=1;i<=n;i++){
            if(!visit[i]){
                dfs(i);
            }
        }
        if(flag) ans++;
        else break;
    }
    cout<<ans<<endl;
    return 0;
}