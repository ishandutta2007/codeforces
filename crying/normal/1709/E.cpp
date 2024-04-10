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
int n,a[MAXN];
vector<int>e[MAXN];
int sz[MAXN],son[MAXN],fa[MAXN],f[MAXN];
void dfs1(int u){
    f[u]=a[u]^f[fa[u]];
    sz[u]=1;
    for(auto v:e[u])if(v!=fa[u]){
        fa[v]=u;
        dfs1(v);
        sz[u]+=sz[v];
        if(!son[u] || sz[son[u]]<sz[v])son[u]=v;
    }
}
int ans;
int tag[MAXN];
set<int>S;
int dfs3(int u,int rt){
    if(S.find( (f[u]^a[rt]) ) !=S.end())return 1;
    for(auto v:e[u])if(v!=fa[u] && !tag[v]){
        if(dfs3(v,rt))return 1;
    }
    return 0;
}
void dfs4(int u){
    S.insert(f[u]);
    for(auto v:e[u])if(v!=fa[u] && !tag[v])dfs4(v);
}
void dfs2(int u){
    if(!son[u]){
        S.insert(f[u]);return;
    }
    for(auto v:e[u])if(v!=fa[u] && v!=son[u])dfs2(v),S.clear();
    if(son[u])dfs2(son[u]);
    if(son[u] && tag[son[u]])S.clear();
    if(S.find( (f[u]^a[u]) )!=S.end()){
        ans++;
        tag[u]=1;
        return;
    }
    S.insert(f[u]);
    for(auto v:e[u])if(v!=fa[u] && v!=son[u] && !tag[v]){
        if(dfs3(v,u)){
            ans++;
            tag[u]=1;
            return;
        }
        dfs4(v);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;rep(i,1,n)cin>>a[i];
    rep(i,1,n-1){
        int x,y;cin>>x>>y;
        e[x].push_back(y);e[y].push_back(x);
    }
    dfs1(1);dfs2(1);
    cout<<ans;
    return 0;
}