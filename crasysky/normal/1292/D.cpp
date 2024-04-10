#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=5003;
int n,mx[N][N],c[N][N],p[N],t,sz[100005],sum[100005];
map< pr,int > S; int cnt; pr to[100005];
vector<int> G[100005];
bool tag[N];
pr st[N];
ll ans;
bool is_fa(pr f,pr u){
    if (u==f) return false;
    if (f.fi==1&&f.se==1) return true;
    int l=min(f.fi,u.fi),r=max(f.fi,u.fi);
    return u.se<=f.se&&mx[l+1][r]<=f.se;
}
pr lca(pr u,pr v){
    int l=min(u.fi,v.fi),r=max(u.fi,v.fi);
    pr s=mp(l,mx[l+1][r]);
    if (p[s.se]>s.fi) return mp(1,1);
    while (s.fi>1&&mx[s.fi][s.fi]<s.se) --s.fi;
    return s;
}
void link(pr f,pr u){
    if (!S.count(f)) S[f]=++cnt,to[cnt]=f;
    if (!S.count(u)) S[u]=++cnt,to[cnt]=u;
    int x=S[f],y=S[u];G[x].pb(y),G[y].pb(x);
}
ll dep(pr u){ return c[u.fi][t]-c[u.fi][u.se-1]; }
void dfs(int u,int f){
    sum[u]=sz[u];
    rep(i,0,G[u].size()-1){
        int v=G[u][i];
        if (v!=f) dfs(v,u),sum[u]+=sum[v];
    }
}
int getrt(int u,int f){
    rep(i,0,G[u].size()-1){
        int v=G[u][i];
        if (v!=f&&sum[v]>=(n+1)/2) return getrt(v,u);
    }
    return u;
}
void solve(int u,int f){
    rep(i,0,G[u].size()-1){
        int v=G[u][i];
        if (v!=f){
            solve(v,u),sz[u]+=sz[v];
            ans+=fabs(dep(to[v])-dep(to[u]))*sz[v];
        }
    }
}
int read(){
    int c=0; char ch=getchar();
    while (ch<'0'||'9'<ch) ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c;
}
int main(){
    int m=5000;
    rep(i,2,m)
        if (!tag[i]) rep(j,2,m/i) tag[i*j]=true;
    rep(i,2,m) if (!tag[i]) p[++t]=i;
    p[t+1]=m+1;
    rep(i,2,m){
        int x=i;
        for (int j=1;j<=t&&x!=1;++j){
            while (x%p[j]==0) x/=p[j],++c[i][j];
            if (x==1) mx[i][i]=j;
        }
    }
    rep(i,1,m)
        rep(j,i+1,m) mx[i][j]=max(mx[i][j-1],mx[j][j]);
    rep(i,1,m)
        rep(p,1,t) c[i][p]+=c[i][p-1];
    rep(p,1,t)
        rep(i,1,m) c[i][p]+=c[i-1][p];
    // cout<<lca(mp(3,1),mp(4,1)).fi<<" "<<lca(mp(3,1),mp(4,1)).se<<endl;
    //cout<<is_fa(mp(1,1),mp(3,1));
    int tp=0;
    rep(i,1,m){
        if (tp==0){ st[++tp]=mp(i,1); continue; }
        pr f=lca(st[tp],mp(i,1));
        while (tp>1&&is_fa(f,st[tp])){
            if (st[tp-1]==f||is_fa(st[tp-1],f)){
                link(f,st[tp]);
                if (f!=st[--tp]) st[++tp]=f;
                break;
            }
            link(st[tp-1],st[tp]),--tp;
        }
        st[++tp]=mp(i,1);
    }
    while (tp>1) link(st[tp-1],st[tp]),--tp;
    n=read(); rep(i,1,n) ++sz[S[mp(max(read(),1),1)]];
    dfs(S[mp(1,1)],0),solve(getrt(S[mp(1,1)],0),0);
    cout<<ans<<endl;
    return 0;
}
/*
11
5000 5000 5000 5000 5000 5000 0 1 0 1 0

77835
*/