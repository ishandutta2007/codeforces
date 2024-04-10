#include <bits/stdc++.h>
using namespace std;
long long n,m,x,y,a[200001],ans;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        ans+=min(a[x],a[y]);
    }
    cout<<ans;
}