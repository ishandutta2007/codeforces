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
const int MAXN=3e5+10;
int n,a[MAXN],b[MAXN],pos[MAXN],dfn[MAXN],dfntot,tag[MAXN],depth[MAXN],vistag[MAXN];
int fa[MAXN],sz[MAXN],vis[MAXN],tot,arr[MAXN],minn[MAXN];
vector<int>e[MAXN];
struct BIT{
    int t[MAXN];
    void upd(int x,int v){
        for(;x<=n;x+=lowbit(x))t[x]+=v;
    }
    int qry(int x){
        int S=0;
        for(;x;x-=lowbit(x))S+=t[x];
        return S;
    }
    int qry(int L,int R){
        return qry(R)-qry(L-1);
    }
}bit;
ll sum;
void dfs(int u){
    dfn[u]=++dfntot;minn[u]=a[u];
    sz[u]=1;
    for(auto v:e[u])if(v!=fa[u]){
        fa[v]=u;depth[v]=depth[u]+1;
        dfs(v);
        sz[u]+=sz[v];
        minn[u]=min(minn[u],minn[v]);
    }
}
void dfs2(int u){
    minn[u]=b[u];
    for(auto v:e[u])if(v!=fa[u]){
        dfs2(v);
        minn[u]=min(minn[u],minn[v]);
    }
}
int check(int u){
    return bit.qry(dfn[u],dfn[u]+sz[u]-1)==sz[u];
}
bool cmp(int x,int y){
    return vis[x]<vis[y];
}
int st[MAXN],top;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)cin>>a[i],pos[a[i]]=i;
    rep(i,1,n-1){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    int pre=0;
    rep(i,1,n){ 
        int p=pos[i];
        top=0;
        int tmp=p;
        while(tmp && !vis[tmp]){
            st[++top]=tmp;
            tmp=fa[tmp];
        }
        if(top && st[top]!=1){
            while(pre!=fa[st[top]]){
                if(!check(pre)){
                    cout<<"NO\n";
                    return 0;
                }
                pre=fa[pre];
            }
        }
        reverse(st+1,st+1+top);
        rep(j,1,top)vis[st[j]]=++tot;
        sum+=depth[p];vistag[p]=1;
        bit.upd(dfn[p],1);
        if(!check(p)){
            int cur=0;
            rep(j,1,n)if(vis[j])arr[++cur]=j;
            sort(arr+1,arr+1+cur,cmp);
            rep(j,1,cur)b[arr[j]]=j;
            rep(k,cur+1,n){
                int p=pos[k];
                if(b[p]){
                    cout<<"NO\n";
                    return 0;
                }
                b[p]=k;
            }
            rep(j,1,n)if(!vistag[j] && a[j]!=b[j]+bit.qry(dfn[j],dfn[j]+sz[j]-1)){
                cout<<"NO\n";return 0;
            }
            dfs2(1);
            rep(j,1,n)if(minn[j]<b[j]){
                cout<<"NO\n";return 0;
            }
            cout<<"YES\n";
            cout<<sum<<'\n';
            rep(j,1,n)cout<<b[j]<<' ';
            return 0;   
        }
        pre=p;
    }
    int cur=0;
    rep(j,1,n)if(vis[j])arr[++cur]=j;
    sort(arr+1,arr+1+cur,cmp);
    rep(j,1,cur)b[arr[j]]=j;
    cout<<"YES\n";
    cout<<sum<<'\n';
    rep(i,1,n)cout<<b[i]<<' ';
    return 0;
}