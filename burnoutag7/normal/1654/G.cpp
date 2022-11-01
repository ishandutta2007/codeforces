#include<bits/stdc++.h>
using namespace std;

int n,h[200005],c[200005],ans[200005];
vector<int> g[200005],fh[200005],vh[200005];
vector<pair<int,int>> tr[200005];
bool f[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(h,-1,sizeof(h));
    {
        queue<int> q;
        for(int i=1;i<=n;i++){
            int lodge;
            cin>>lodge;
            if(lodge){
                q.emplace(i);
                h[i]=0;
            }
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int y:g[x])if(h[y]==-1){
                h[y]=h[x]+1;
                q.emplace(y);
            }
        }
    }
    memcpy(ans,h,sizeof(h));
    for(int i=1;i<=n;i++){
        vh[h[i]].emplace_back(i);
        for(int j:g[i])if(h[i]==h[j]){
            f[i]=1;
            fh[h[i]].emplace_back(i);
            break;
        }
        for(int j:g[i])if(h[i]<h[j])tr[h[i]].emplace_back(i,j);
    }
    for(int ch=0;ch<n;ch++)if(!fh[ch].empty()){
        memset(c,0x3f,sizeof(c));
        queue<int> q;
        for(int x:fh[ch]){
            c[x]=0;
            q.emplace(x);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int y:g[x])if(h[y]==h[x]&&c[y]>c[x]+1){
                c[y]=c[x]+1;
                q.emplace(y);
            }
        }
        for(int l=ch;l<n;l++){
            for(auto &[u,v]:tr[l]){
                c[v]=min(c[v],c[u]?c[u]-1:0);
                q.emplace(v);
            }
            while(!q.empty()){
                int x=q.front();
                q.pop();
                for(int y:g[x])if(h[y]==h[x]&&c[y]>c[x]+1){
                    c[y]=c[x]+1;
                    q.emplace(y);
                }
            }
        }
        for(int i=1;i<=n;i++)if(c[i]<=0){
            ans[i]=max(ans[i],2*h[i]-ch);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }

    return 0;
}