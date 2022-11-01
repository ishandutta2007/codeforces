#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,k;
ll a[300005],sum;
bool vis[300005];
vector<pair<int,int>> g[300005];
vector<int> af,ab;

void dfs(int x){
    vis[x]=true;
    for(pair<int,int> &e:g[x]){
        int y=e.first,z=e.second;
        if(!vis[y]){
            dfs(y);
            if(a[x]+a[y]>=k){
                a[x]+=a[y]-k;
                af.push_back(z);
            }else{
                ab.push_back(z);
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum<(ll)n*k-k){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
    }
    dfs(1);
    for(int x:af)cout<<x<<'\n';
    reverse(ab.begin(),ab.end());
    for(int x:ab)cout<<x<<'\n';

    return 0;
}