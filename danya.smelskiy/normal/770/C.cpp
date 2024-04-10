#include <bits/stdc++.h>
using namespace std;

int n,m;
int x,y;
vector<int> v[100005];
vector<int> ans;
bool used[100005];
bool used2[100005];
int a[100005];
void dfs(int x){
    used[x]=true;
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (used[to]==false) dfs(to);
    }
    ans.push_back(x);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i){
        cin>>x;
        for (int j=0;j<x;++j){
            cin>>y;
            v[i].push_back(y);
        }
    }
    for (int i=1;i<=m;++i)
        if (used[a[i]]==false) dfs(a[i]);
    for (int i=0;i<ans.size();++i){
        x=ans[i];
        for (int j=0;j<v[x].size();++j){
            if (used2[v[x][j]]==false) {
                cout<<"-1";
                return 0;
            }
        }
        used2[x]=true;
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i]<<" ";
}