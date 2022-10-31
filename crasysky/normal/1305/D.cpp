#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define sit set<int>::iterator
#define ll long long
using namespace std;
const int N=1e3+3,INF=1e9;
vector <int> G[N];
bool del[N];
int d[N];
int main(){
    int n; cin>>n;
    for (int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v),G[v].push_back(u);
        ++d[u],++d[v];
    }
    for (int i=1;i<=n/2;++i){
        int a1=0,a2=0;
        for (int j=1;j<=n;++j)
            if (d[j]==1&&!del[j]){
                if (!a1) a1=j;
                else{ a2=j; break; }
            }
        cout<<"? "<<a1<<" "<<a2<<endl;
        cout.flush();
        int lca; cin>>lca;
        if (lca==a1||lca==a2){ cout<<"! "<<lca<<endl; return 0; }
        del[a1]=true,del[a2]=true;
        rep(j,0,G[a1].size()-1) --d[G[a1][j]];
        rep(j,0,G[a2].size()-1) --d[G[a2][j]];
    }
    for (int i=1;i<=n;++i)
        if (!del[i]){ cout<<"! "<<i<<endl; return 0; }
    return 0;
}