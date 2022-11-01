#include<bits/stdc++.h>
using namespace std;

bool u[200005];
vector<int> g[200005];
int n,k,r;
long long ans;

int dfs(int x,int p){
    int res=u[x];
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(y!=p){
            res+=dfs(y,x);
        }
    }
    while(2*res>r){
        res-=2;
        r-=2;
    }
    ans+=res;
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=k*2;i++){
        int t;
        cin>>t;
        u[t]=true;
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    r=k*2;
    dfs(1,-1);
    cout<<ans<<endl;

    return 0;
}