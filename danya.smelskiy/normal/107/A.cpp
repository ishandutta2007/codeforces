#include <bits/stdc++.h>
using namespace std;
const int inf=2*1e9;

int n,m,x,y,z;
vector<pair<int,pair<int,int> > > ans;
bool t1[1005];
bool t2[1005];
bool used[1005];
vector<pair<int,int> > v[1005];

inline bool cmp(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){
    return a.first<b.first;
}
void dfs(int x,int p,int l){
    used[x]=true;
    if (t2[x]==false && x!=p) {
        ans.push_back(make_pair(p,make_pair(x,l)));
        return;
    }
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i].first;
        if (used[to]) continue;
        dfs(to,p,min(l,v[x][i].second));
    }
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        t1[y]=true;
        t2[x]=true;
    }
    for (int i=1;i<=n;++i)
        if (t1[i]==false) { for (int j=1;j<=n;++j) used[j]=false; dfs(i,i,inf);}
    sort(ans.begin(),ans.end(),cmp);
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<'\n';
}