#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6,INF=1e9;
vector<int> G[N],v[N];
int a[N],cnt[N];
int main(){
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m){
        int u,v; scanf("%d%d",&u,&v);
        G[u].pb(v),G[v].pb(u);
    }
    rep(i,1,n)
        scanf("%d",&a[i]),v[a[i]].pb(i);
    rep(i,1,n){
        rep0(j,G[i].size()) ++cnt[a[G[i][j]]];
        if (cnt[a[i]]){ cout<<-1<<endl; return 0; }
        rep(j,1,a[i]-1)
            if (!cnt[j]){ cout<<-1<<endl; return 0; }
        rep0(j,G[i].size()) --cnt[a[G[i][j]]];
    }
    rep(i,1,n)
        rep0(j,v[i].size()) printf("%d ",v[i][j]);
    return 0;
}