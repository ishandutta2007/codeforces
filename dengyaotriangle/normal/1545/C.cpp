#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=505;
const int mdn=998244353;

int n;
int a[maxn*2][maxn];
int sel[maxn];
vector<int> adj[maxn*2];
vector<int> cs[maxn][maxn];
int cnt[maxn][maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n*2;i++)sel[i]=-1,adj[i].clear();
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cs[i][j].clear(),cnt[i][j]=0;
        for(int i=1;i<=n*2;i++){
            for(int j=1;j<=n;j++)cin>>a[i][j],cs[j][a[i][j]].push_back(i),cnt[j][a[i][j]]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(cnt[i][j]==1)q.push(cs[i][j].front());
        while(!q.empty()){
            int cid=q.front();q.pop();
            if(sel[cid]!=-1)continue;
            sel[cid]=1;
            for(int i=1;i<=n;i++){
                for(int v:cs[i][a[cid][i]]){
                    if(sel[v]==-1)sel[v]=-2;
                }
                cs[i][a[cid][i]].clear();
                cnt[i][a[cid][i]]=0;
            }
            for(int i=1;i<=n*2;i++)if(sel[i]==-2){
                sel[i]=0;
                for(int j=1;j<=n;j++){
                    cnt[j][a[i][j]]--;
                    if(cnt[j][a[i][j]]==1)for(int k:cs[j][a[i][j]])q.push(k);
                }
            }
        }
        for(int i=1;i<=n*2;i++){
            if(sel[i]==-1){
                for(int j=1;j<=n;j++){
                    for(int k:cs[j][a[i][j]])if(k!=i&&sel[k]==-1){
                        adj[i].push_back(k);
                    }
                }
            }
        }
        function<void(int)> dfs=[&](int u){
            for(int i=0;i<(int)adj[u].size();i++){
                int v=adj[u][i];
                if(sel[v]==-1){
                    sel[v]=!sel[u];
                    dfs(v);
                }
            }
        };
        int ans=1;
        for(int i=1;i<=n*2;i++){
            if(sel[i]==-1){
                sel[i]=1;
                dfs(i);
                ans=ans*2%mdn;
            }
        }
        cout<<ans<<'\n';
        for(int i=1;i<=n*2;i++)if(sel[i])cout<<i<<' ';
        cout<<'\n';
    }
    return 0;
}