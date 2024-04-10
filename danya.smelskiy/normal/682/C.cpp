#include <bits/stdc++.h>
using namespace std;


int n;
int x,y,z;
long long a[100005];
vector<pair<int,int> > v[100005];
int sz[100005];
long long ans;
void dfs2(int x,int pred=-1){
    sz[x]=1;
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i].first;
        if (to==pred) continue;
        dfs2(to,x);
        sz[x]+=sz[to];
    }
}
void dfs(int x,long long y,int pred=1){
    if (a[x]<y) {
        ans+=sz[x];
        return;
    }
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i].first;
        if (to==pred) continue;
        if (y<0) dfs(to,v[x][i].second,x);
        else dfs(to,v[x][i].second+y,x);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i){
        x=i+1;
        cin>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    dfs2(1);
    for (int i=0;i<v[1].size();++i){
        int to=v[1][i].first;
        dfs(to,v[1][i].second);
    }
    cout<<ans;
}