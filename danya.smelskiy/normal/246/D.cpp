#include <bits/stdc++.h>
using namespace std;
int n,m,ans=1e9,x,y;
set<int> v[100001];
int a[100001];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        ans=min(ans,a[i]);
    }
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        if (a[x]==a[y]) continue;
        v[a[x]].insert(a[y]);
        v[a[y]].insert(a[x]);
    }
    for (int i=1;i<=n;++i){
        x=a[i];
        if (v[x].size()>v[ans].size()) ans=x;
        else if (v[x].size()==v[ans].size() && x<ans) ans=x;
    }
    cout<<ans;
}