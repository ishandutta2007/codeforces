#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int n,m;
vector<pair<int,int> > ans;
int x,y;
int kol[1001];

//
//
//      ZAYDI
//
//      AMIN'
int main(){

    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
        ++kol[x];
        ++kol[y];
    }
    int v=0;
    for (int i=1;i<=n;++i)
        if (v==0 || (kol[i]<kol[v])) v=i;
    for (int i=1;i<=n;++i){
        if (i!=v){
            ans.push_back(make_pair(i,v));
        }
    }
    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}