#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int n,x,y;
int a[100005];
int b[100005];
vector<int> v[100005];
void dfs(int x,int y,int yy,int p){
    int t=0;
    if (y%2==1) a[x]=(a[x]+1)%2;
    if (a[x]!=b[x]){
        t=1;
        ans.push_back(x);
    }
    for (int j=0;j<v[x].size();++j){
        int to=v[x][j];
        if (to==p) continue;
        dfs(to,yy,y+t,x);
    }
}
int main(){
    cin>>n;
    for (int i=1;i<=n-1;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int j=1;j<=n;++j)
        cin>>b[j];
    dfs(1,0,0,-1);
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i]<<'\n';
}