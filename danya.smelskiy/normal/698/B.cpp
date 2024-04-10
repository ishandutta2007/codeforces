#include <bits/stdc++.h>
using namespace std;

int n;
int a[200001];
int used[200001];
int ans;
int q;
vector<int> v;
void dfs(int x,int pred=-1){
    used[x]=1;
    if (a[x]==x){
        if (q==-1) q=x;
        v.push_back(x);
        return;
    }
    if (used[a[x]]==1) v.push_back(a[x]);
    else if (used[a[x]]==0) dfs(a[x],x);
    used[x]=2;
}

int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    q=-1;
    int j=0;
    for (int i=1;i<=n;++i)
        if (used[i]==0) dfs(i);
    if (q==-1 && v.size()>0) {
        ++ans;
        q=v[0];
        a[v[0]]=v[0];
    }
    for (int i=j;i<v.size();++i){
        int y=v[i];
        if (a[y]!=q && y!=q) { ++ans; a[y]=q; }
    }
    cout<<ans<<'\n';
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
}