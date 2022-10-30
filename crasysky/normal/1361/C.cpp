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
const int N=5e6+6;
int n,a[N],b[N],cnt[N],st[N],tp;
bool vis[N],go[N];
int head[N],to[N],nxt[N],ec;
void adde(int u,int v){
    go[u]=go[v]=false;
    to[ec]=v,nxt[ec]=head[u],head[u]=ec++;
    to[ec]=u,nxt[ec]=head[v],head[v]=ec++;
    vis[ec-2]=vis[ec-1]=false;
}
void dfs(int u){
    for (int &i=head[u];i;i=nxt[i]){
        if (!vis[i]){
            vis[i]=vis[i^1]=true;
            int v=to[i];
            dfs(v);
            if (v<=2*n) st[++tp]=v,go[v]=true;
        }
    }
}
int main(){
    scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&a[i],&b[i]);
    per(j,19,0){
        int k=(1<<j+1)-1;
        rep(i,0,k) cnt[i]=0;
        rep(i,1,n) ++cnt[a[i]&k],++cnt[b[i]&k];
        bool fl=false; int c=0;
        rep(i,0,k) if (cnt[i]&1){ fl=true; break; }
        if (fl) continue;
        rep(i,1,k+1+2*n) head[i]=0; ec=0;
        rep(i,1,n){
            adde(2*i-1,2*i);
            adde(2*i-1,2*n+(a[i]&k)+1);
            adde(2*i,2*n+(b[i]&k)+1);
        }
        tp=0; dfs(1);
        rep(i,1,2*n) if (!go[i]){ fl=true; break; }
        if (fl) continue;
        printf("%d\n",j+1);
        int l=1,r=tp;
        if (((st[1]-1)^1)!=st[2]-1) st[++tp]=st[1],l=2,r=tp;
        rep(i,l,r) printf("%d ",st[i]);
        return 0;
    }
    printf("0\n");
    rep(i,1,2*n) printf("%d ",i);
    return 0;
}