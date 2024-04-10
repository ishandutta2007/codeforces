#include <bits/stdc++.h>
using namespace std;
const int inf=1e8;
bool used[405];
long long n,m,x,y;
vector<int> v1[405];
vector<int> v2[405];
int a[405][405];
int d1[405];
int d2[405];
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j)
        if (a[i][j]==0){
            v2[i].push_back(j);
            v2[j].push_back(i);
        }
    }
    for (int i=1;i<=n;++i){
        d1[i]=inf;
        d2[i]=inf;
    }
    d1[1]=0;
    d2[1]=0;
    while (true){
        int v=-1;
        for (int i=1;i<=n;++i)
            if (used[i]==false && (v==-1 || d1[i]<d1[v])) v=i;
        if (v==-1 || d1[v]==inf) break;
        used[v]=true;
        for (int i=0;i<v1[v].size();++i){
            int to=v1[v][i];
            if (d1[to]>d1[v]+1) d1[to]=d1[v]+1;
        }
    }
    for (int i=1;i<=n;++i)
        used[i]=false;
    while (true){
        int v=-1;
        for (int i=1;i<=n;++i)
            if (used[i]==false && (v==-1 || d2[i]<d2[v])) v=i;
        if (v==-1 || d2[v]==inf) break;
        used[v]=true;
        for (int i=0;i<v2[v].size();++i){
            int to=v2[v][i];
            if (d2[to]>d2[v]+1) d2[to]=d2[v]+1;
        }
    }
    if (d1[n]==inf || d2[n]==inf) cout<<"-1";
    else if (d1[n]==d2[n]) cout<<d1[n]+1;
    else cout<<max(d1[n],d2[n]);
}