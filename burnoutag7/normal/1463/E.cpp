#include<bits/stdc++.h>
using namespace std;

int n,m,root,fa[300005],uf[300005],op[300005];
vector<int> g[300005],ans;
bool vis[300005];

int find(const int& x){
    if(uf[x]==x)return x;
    return uf[x]=find(uf[x]);
}

void dfs(const int& x){
    vis[x]=true;
    for(const int& y:g[x])if(!vis[y])dfs(y);
    ans.emplace_back(x);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>fa[i];
        if(fa[i]==0)root=i;
    }
    iota(uf+1,uf+1+n,1);
    for(int i=1;i<=m;i++){
        static int x,y;
        cin>>x>>y;
        uf[y]=find(x);
        op[x]=y;
    }
    for(int i=1;i<=n;i++)g[fa[i]].emplace_back(find(i));
    for(int i=1;i<=n;i++)if(op[i])g[i].emplace_back(op[i]);
    dfs(root);
    reverse(ans.begin(),ans.end());
    int cnt=0;
    set<int> t;
    t.emplace(0);
    bool fail=ans.size()!=n;
    for(const int& x:ans){
        if(t.find(fa[x])==t.end())fail=true;
        t.emplace(x);
    }
    for(int i=0;i+1<ans.size();i++){
        const int& x=ans[i],& y=ans[i+1];
        cnt+=op[x]==y;
    }
    fail|=cnt!=m;
    if(fail)cout<<"0\n";
    else{
        for(const int& x:ans)cout<<x<<' ';
        cout<<endl;
    }

    return 0;
}