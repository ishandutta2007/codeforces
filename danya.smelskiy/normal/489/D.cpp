#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
long long ans;
vector<int> v[3001];
int a[3001][3001];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        cin>>x>>y;
        v[x].push_back(y);
     //   v[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
    for (int j=0;j<v[i].size();++j){
        int to=v[i][j];
        for (int k=0;k<v[to].size();++k)
            if (v[to][k]!=i)
            ++a[i][v[to][k]];
    }
        for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j)
            ans+=(a[i][j])*(a[i][j]-1)/2;
    }
    cout<<ans;
}