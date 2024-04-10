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
const int N=3003;
int s[N][N],fru[N][N],frv[N][N];
bool vis[N][N],inq[N][N];
vector<int> G[N];
queue< pr > q;
ll f[N][N];
void dfs(int u,int f,int rt){
    s[rt][u]=1;
    rep(i,0,G[u].size()-1){
        int v=G[u][i];
        if (v!=f) dfs(v,u,rt),s[rt][u]+=s[rt][v];
    }
}
int read(){
    int c=0; char ch=getchar();
    while (ch<'0'||'9'<ch) ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c;
}
int main(){
    int n=read();
    rep(i,1,n-1){
        int u=read(),v=read(); G[u].pb(v),G[v].pb(u);
    }
    rep(i,1,n) dfs(i,0,i);
    rep(u,1,n)
        rep(j,0,G[u].size()-1){
            int v=G[u][j];
            fru[u][v]=v,frv[u][v]=u;
            f[u][v]=s[u][v]*s[v][u];
            q.push(mp(u,v));
        }
    ll ans=0;
    while (!q.empty()){
        int u=q.front().fi,v=q.front().se; q.pop();
        ans=max(ans,f[u][v]),inq[u][v]=false;
        rep(i,0,G[u].size()-1){
            int u2=G[u][i]; ll d=f[u][v]+s[u][u2]*s[u][v];
            if (u2!=fru[u][v]&&d>f[u2][v]){
                fru[u2][v]=u,frv[u2][v]=frv[u][v],f[u2][v]=d;
                if (!inq[u2][v]&&!inq[v][u2]) q.push(mp(u2,v));
            }
        }
        rep(i,0,G[v].size()-1){
            int v2=G[v][i]; ll d=f[u][v]+s[v][v2]*s[v][u];
            if (v2!=frv[u][v]&&d>f[u][v2]){
                fru[u][v2]=fru[u][v],frv[u][v2]=v,f[u][v2]=d;
                if (!inq[u][v2]&&!inq[v2][u]) q.push(mp(u,v2));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}