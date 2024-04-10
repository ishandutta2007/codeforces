#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
int n,m,p[MAXN],x[MAXN],y[MAXN];
int idx[MAXN],vis[MAXN];
int now,deg[MAXN];
map<array<int,2>,int>f;
vector<int>e[MAXN],occ[MAXN];
queue<int>q;
int cmp(int x,int y){
    if(idx[x]>idx[now] && idx[y]>idx[now])return idx[x]<idx[y];
    if(idx[x]>idx[now])return 1;
    if(idx[y]>idx[now])return 0;
    return idx[x]<idx[y];
}
void solve(){
    rep(i,1,m){
        f[{x[i],y[i]}]=f[{y[i],x[i]}]=i;
        occ[x[i]].push_back(y[i]);
        occ[y[i]].push_back(x[i]);
    }
    rep(i,1,n)if(vis[i])continue;else{
        int u=i,tot=1;
        idx[u]=1;vis[u]=1;
        while(1){
            u=p[u];if(u==i)break;
            idx[u]=++tot;vis[u]=1;
        }
    }
    rep(i,1,n){
        now=i;
        sort(occ[i].begin(),occ[i].end(),cmp);
        int sz=occ[i].size()-1;
        rep(j,0,sz-1){
            int x=f[{i,occ[i][j]}],y=f[{i,occ[i][j+1]}];
            e[x].push_back(y);
            deg[y]++;
        }
    }
    rep(i,1,m){
        if(!deg[i]){
            cout<<i<<' ';
            q.push(i);
        }
    }
    while(q.size()){
        int u=q.front();q.pop();
        for(auto v:e[u]){
            deg[v]--;
            if(!deg[v]){
                cout<<v<<' ';
                q.push(v);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,n)cin>>p[i];
    rep(i,1,m)cin>>x[i]>>y[i];
    solve();

    return 0;
}