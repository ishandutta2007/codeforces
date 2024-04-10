#include <bits/stdc++.h>
using namespace std;

using ll=long long;

constexpr int N=2e5+5;

vector<int> e[N];
int n,m;
int a[N];
int u[N],v[N],w[N];
int mp[N][30];
int ans[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        if(u[i]>v[i]) swap(u[i],v[i]);
    }
    for(int j=0;j<30;j++){
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<=m;i++){
            if((w[i]>>j)&1){
                if(u[i]==v[i]) mp[u[i]][j]=1;
                else{
                    e[u[i]].push_back(v[i]);
                    e[v[i]].push_back(u[i]);
                }
            }
            else{
                mp[u[i]][j]=-1;
                mp[v[i]][j]=-1;
            }
        }
        for(int i=1;i<=n;i++) if(mp[i][j]==-1){
            for(auto it:e[i]) mp[it][j]=1;
        }
        for(int i=1;i<=n;i++){
            if(mp[i][j]<1){
                for(auto it:e[i]) if(it>i) mp[it][j]=1;
            }
            else{
                if(mp[i][j]==1) ans[i]|=(1<<j);
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";

    return 0;
}