#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
vector<int> adj[maxn];
int prm[maxn],prc;
int a[maxn];
bool vis[maxn];
bool ntp[maxn];
map<int,int> ml[maxn];
int ans;

void dfs(int u){
    vis[u]=1;
    int tm=a[u];
    for(int i=2;i*i<=a[u];i++){
        if(tm%i==0){
            while(tm%i==0) tm/=i;
            ml[u][i]=1;
            ans=max(ans,1);
        }
    }
    if(tm!=1){
        ml[u][tm]=1;
        ans=max(ans,1);
    }
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!vis[v]){
            dfs(v);
            for(map<int,int>::iterator it=ml[v].begin();it!=ml[v].end();it++){
                int q=(*it).first,s=(*it).second;
                if(ml[u][q]){
                    if(ml[u][q]==1){
                        ml[u][q]=s+1;
                        ans=max(ans,s+1);
                    }else{
                        ans=max(ans,ml[u][q]+s);
                        ml[u][q]=max(ml[u][q],s+1);
                    }
                }
            }
            ml[v].clear();
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout<<ans;
    return 0;
}//orzzz