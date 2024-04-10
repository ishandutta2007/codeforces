#include <bits/stdc++.h>
using namespace std;
int n,m;
int x,y;
int kol[100001];
vector<int> v[100001];
int depth[100001];
long long ans;
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        if (x>y) swap(x,y);
        v[x].push_back(y);
        ++kol[x];
        ++kol[y];
    }
    for (int i=1;i<=n;++i){
        depth[i]=max(depth[i],1);
        ans=max(ans,1ll*kol[i]*depth[i]);
        for (int j=0;j<v[i].size();++j){
            int to=v[i][j];
            depth[to]=max(depth[to],depth[i]+1);
        }
    }
    cout<<ans;
}