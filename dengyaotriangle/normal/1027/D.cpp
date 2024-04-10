#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
int a[maxn];
int c[maxn];
int idg[maxn];
bool de[maxn],vis[maxn];

int dfs(int u){
    int v=a[u];
    int ans=c[u];
    if(!vis[v]){
        vis[v]=1;
        ans=min(ans,dfs(v));
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        idg[a[i]]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(idg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int v=q.front();q.pop();
        de[v]=1;
        idg[a[v]]--;
        if(idg[a[v]]==0) q.push(a[v]);
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(!de[i]){
            if(!vis[i]){
                vis[i]=1;
                ans+=dfs(i);
            }
        }
    }
    cout<<ans;
    return 0;
}