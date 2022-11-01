#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n;
    cin>>n;
    vector<vector<int>> g(n+1);
    vector<int> a(n+1),b(n+1),c(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]++;
    }
    int mx=max_element(c.begin(),c.end())-c.begin();
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(mx!=a[i]&&mx!=b[i])g[a[i]].emplace_back(b[i]);
    }
    vector<int> vis(n+1);
    function<bool(int)> dfs=[&](int x){
        vis[x]=1;
        for(int y:g[x])if(!vis[y]){
            if(!dfs(y))return false;
        }else if(vis[y]==1)return false;
        vis[x]=2;
        return true;
    };
    for(int i=1;i<=n;i++)if(!vis[i]&&!dfs(i)){
        cout<<"WA\n";
        return;
    }
    cout<<"AC\n";
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}