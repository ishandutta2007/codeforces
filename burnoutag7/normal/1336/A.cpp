#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> g[200005];
int sz[200005];
int dep[200005];

int dfs(int x,int p){
    for(int &y:g[x]){
        if(y!=p){
            dep[y]=dep[x]+1;
            sz[x]+=dfs(y,x)+1;
        }
    }
    return sz[x];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1);
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    sort(v.begin(),v.end(),[](const int &a,const int &b){
        return sz[a]-dep[a]>sz[b]-dep[b];
    });
    long long ans=0;
    for(int i=0;i<n-k;i++){
        ans+=sz[v[i]]-dep[v[i]];
    }
    cout<<ans<<endl;

    return 0;
}