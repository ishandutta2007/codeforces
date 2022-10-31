#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6;
vector<int> G[N]; int cnt[2],d[N];
void dfs(int u,int f){
    d[u]=d[f]+1,++cnt[d[u]&1];
    rep0(i,G[u].size())
        if (G[u][i]!=f) dfs(G[u][i],u);
}
int main(){
    int n; cin>>n;
    rep(i,1,n-1){
        int u,v; scanf("%d%d",&u,&v);
        G[u].push_back(v),G[v].push_back(u);
    }
    dfs(1,0);
    cout<<min(cnt[0]-1,cnt[1]-1)<<endl;
}