#include <bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,z,ans;
vector<pair<int,long long> > v[100001];
bool used[100001];
int main(){
    cin>>n>>m>>k;
    for (int i=1;i<=m;++i){
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    ans=10000000000;
    for (int i=1;i<=k;++i){
        cin>>x;
        used[x]=true;
    }
    for (int i=1;i<=n;++i)
    if (used[i]==true){
        for (int j=0;j<v[i].size();++j){
            int to=v[i][j].first;
            if (used[to]==false) ans=min(ans,v[i][j].second);
        }
    }
    if (ans==10000000000) cout<<"-1";
    else cout<<ans;
}