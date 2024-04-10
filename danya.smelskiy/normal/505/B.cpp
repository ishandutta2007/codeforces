#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,z;
bool t;
bool used[200];
bool used2[200];
vector<pair<int,int> > v[200];
int kol;

void dfs(int x,int y,int p){
    used[x]=true;
    if (x==p){
        used[x]=false;
        t=true;
        return;
    }
    for (int j=0;j<v[x].size();++j){
        int to=v[x][j].first;
        int d=v[x][j].second;
        if (used[to]==true) continue;
        if (d!=y) continue;
        dfs(to,d,p);
    }
    used[x]=false;
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    cin>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        kol=0;
        for (int j=0;j<v[x].size();++j){
            t=false;
            int to=v[x][j].first;
            int d=v[x][j].second;
            if (used2[d]==false){
            dfs(to,d,y);
            if (t==true) ++kol;
            used2[d]=true;
            }
        }
        for (int j=0;j<v[x].size();++j)
            used2[v[x][j].second]=false;
        cout<<kol<<'\n';
    }
}