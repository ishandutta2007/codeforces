#include <bits/stdc++.h>
using namespace std;




int ans,kol;
bool used[300005];
vector<int> v[300005];
vector<pair<int,pair<int,int> > > vv[300005];
char res[300005];
int n,m,s;

void dfs(int x){
    ++ans;
    used[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used[to]==false) dfs(to);
    }
    for (int i=0;i<vv[x].size();++i) {
        int to=vv[x][i].first;
        if (used[to]) continue;
        if (vv[x][i].second.first==0) res[vv[x][i].second.second]='+';
        else res[vv[x][i].second.second]='-';
        dfs(to);
    }
}
void dfs2(int x){
    ++ans;
    used[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used[to]==false) dfs2(to);
    }
    for (int i=0;i<vv[x].size();++i) {
        int to=vv[x][i].first;
        if (used[to]) continue;
        if (vv[x][i].second.first==0) res[vv[x][i].second.second]='-';
        else res[vv[x][i].second.second]='+';
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>s;
    for (int i=1;i<=m;++i) {
        int t,x,y;
        cin>>t>>x>>y;
        if (t==1) {
            v[x].push_back(y);
        } else {
            ++kol;
            vv[x].push_back(make_pair(y,make_pair(0,kol)));
            vv[y].push_back(make_pair(x,make_pair(1,kol)));
        }
    }
    for (int i=1;i<=kol;++i)
        res[i]='-';
    dfs(s);
    cout<<ans<<'\n';
    for (int i=1;i<=kol;++i)
        cout<<res[i];
    cout<<'\n';
    for (int i=1;i<=n;++i) {
        used[i]=false;
    }
    for (int i=1;i<=kol;++i)
        res[i]='-';
    ans=0;
    dfs2(s);
    cout<<ans<<'\n';
    for (int i=1;i<=kol;++i)
        cout<<res[i];
    cout<<'\n';
}