#include <bits/stdc++.h>
using namespace std;
int n,m,ans,x,y;
int a[105][105];
vector<int> v[105];
bool used[105];
void dfs(int x){
    used[x]=true;
    for (int j=0;j<v[x].size();++j){
        int to=v[x][j];
        if (used[to]==false) dfs(to);
    }
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>x;
        for (int j=1;j<=x;++j){
            cin>>y;
            a[i][y]=1;
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            for (int k=1;k<=m;++k)
            if (a[i][k]==1 && a[j][k]==1){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    int kol=0;
    for (int i=1;i<=n;++i)
    if (used[i]==false){
        if (v[i].size()==0) ++kol;
        else {dfs(i);}
        ++ans;
    }
    if (kol==ans) cout<<kol;
    else cout<<ans-1;
}