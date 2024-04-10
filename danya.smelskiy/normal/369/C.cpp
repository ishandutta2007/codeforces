#include <bits/stdc++.h>
using namespace std;


vector<int> ans;
vector<int> v[1000005];
bool t[1000005];
int b[1000005];
int n,x,y,z;

void dfs(int x,int y=-1){
    if (t[x]==true) b[x]=1;
    for (int j=0;j<v[x].size();++j){
        int to=v[x][j];
        if (to!=y) {
            dfs(to,x);
            b[x]+=b[to];
        }
    }
    if (t[x]==true && b[x]==1) ans.push_back(x);
}
int main(){
    cin>>n;
    for (int i=1;i<n;++i){
        cin>>x>>y>>z;
        v[x].push_back(y);
        v[y].push_back(x);
        if (z==2){
            t[x]=true;
            t[y]=true;
        }
    }
    dfs(1);
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i]<<'\n';
}