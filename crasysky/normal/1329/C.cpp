#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define sit set<int>::iterator
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ll long long
using namespace std;
const int N=2e6+6;
pr v[N];
int l[N], r[N], d[N];
int merge(int x, int y){
    if (! x || ! y) return x + y;
    if (v[x].fi > v[y].fi) swap(x, y);
    r[x] = merge(r[x], y);
    if (d[l[x]] < d[r[x]]) swap(l[x], r[x]);
    d[x] = d[r[x]] + 1;
    return x;
}
void pop(int &x){
    x = merge(l[x], r[x]);
}
int rt[N],h,g,ans[N];
bool tg[N];
ll s;
void dfs(int u,int d){
    rt[u]=u;
    if (d<h){
        dfs(u<<1,d+1),dfs(u<<1|1,d+1);
        rt[u]=merge(rt[u],rt[u<<1]),rt[u]=merge(rt[u],rt[u<<1|1]);
    }
    if (d<=g){
        if (d<g)
            while (v[rt[u]].fi<max(ans[u<<1],ans[u<<1|1])) pop(rt[u]);
        s+=(ans[u]=v[rt[u]].fi),tg[v[rt[u]].se]=true,pop(rt[u]);
    }
}
int read(){
    int c=0,f=1; char ch=getchar();
    while ((ch<'0'||'9'<ch)&&ch!='-') ch=getchar();
    if (ch=='-') f=-1,ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c*f;
}
int main(){
    int T=read();
    while (T--){
        h=read(),g=read(); s=0;
        rep(i,1,(1<<h)-1) v[i]=mp(read(),i),l[i]=r[i]=d[i]=tg[i]=false;
        dfs(1,1);
        printf("%lld\n",s);
        per(i,(1<<h)-1,1) if (!tg[i]) printf("%d ",i);
        putchar('\n');
    }
    return 0;
}