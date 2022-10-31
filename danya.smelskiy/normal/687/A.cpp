#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
bool t;
int color[100001];
vector<int> a;
vector<int> b;
vector<int> v[100001];
void dfs(int x,int cc){
    color[x]=cc;
    if (cc==1) a.push_back(x);
    else b.push_back(x);
    for (int j=0;j<v[x].size();++j){
        int to=v[x][j];
        if (color[to]==color[x]) {
            t=true;
            break;
        } else if (color[to]==0) dfs(to,cc%2+1);
    }
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        if (color[i]==0)
        dfs(i,1);
    if (t==true) cout<<"-1";
    else {
        cout<<a.size()<<'\n';
        for (int i=0;i<a.size();++i)
            cout<<a[i]<<" ";
        cout<<'\n';
        cout<<b.size()<<'\n';
        for (int i=0;i<b.size();++i)
            cout<<b[i]<<" ";
    }
}