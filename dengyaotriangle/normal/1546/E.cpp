#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=505;
const int mdn=998244353;

int n;
int a[maxn*2][maxn];
int sel[maxn];
vector<int> adj[maxn*2];
int cnt[maxn][maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n*2;i++)sel[i]=-1,adj[i].clear();
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cnt[i][j]=0;
        for(int i=1;i<=n*2;i++){
            for(int j=1;j<=n;j++)cin>>a[i][j],cnt[j][a[i][j]]++;
        }
        while(1){
            int cid=-1;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(cnt[i][j]==1){
                        for(int k=1;k<=n*2;k++)if(sel[k]==-1&&a[k][i]==j){
                            cid=k;break;
                        }
                        break;
                    }
                }
                if(cid!=-1)break;
            }
            if(cid==-1)break;
            sel[cid]=1;
            for(int i=1;i<=n;i++)cnt[i][a[cid][i]]--;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n*2;j++)if(sel[j]==-1){
                    if(a[j][i]==a[cid][i]){
                        sel[j]=0;
                        for(int k=1;k<=n;k++)cnt[k][a[j][k]]--;
                    }
                }
            }
        }
        for(int i=1;i<=n*2;i++){
            if(sel[i]==-1){
                for(int j=1;j<=n;j++){
                    for(int k=1;k<=n*2;k++)if(sel[k]==-1&&a[k][j]==a[i][j]&&k!=i){
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