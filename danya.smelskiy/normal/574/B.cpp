#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;
long long kol[4005];
int a[4005][4005];
vector<int> v[4005];
long long ans=1000000;
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        ++kol[x];
        ++kol[y];
        a[x][y]=1;
        a[y][x]=1;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i){
        for (int j=0;j<v[i].size();++j){
            x=v[i][j];
            for (int jj=0;jj<v[x].size();++jj){
                y=v[x][jj];
                if (a[i][y]==1) ans=min(ans,kol[i]+kol[x]+kol[y]-6);
            }
        }
    }
    if (ans==1000000) cout<<"-1";
    else
    cout<<ans;
}