#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define sit set<int>::iterator
#define ll long long
using namespace std;
const int N=1e6+6;
int fa[N],s[N],c[N],G[N][30],dp[N],st[N],tp,dc;
bool tg[N];
int dfs(int u){
    int dfn=dc+1;
    if (tg[u]) ++dc;
    st[++tp]=dp[u]-dfn,st[tp]=min(st[tp],st[tp-1]);
    rep(i,1,26){
        int v=G[u][i];
        if (v&&s[v]){
            dp[v]=dp[u]+1;
            if (tg[v]) dp[v]=min(dp[v],st[tp]+(dc+2));
            dfs(v);
        }
    }
    --tp;
}
int main(){
    int n; cin>>n;
    rep(i,1,n){
        int p; char c; scanf("%d %c",&p,&c);
        fa[i]=p,G[p][c-'a'+1]=i;
    }
    int k; cin>>k;
    rep(i,1,k){ scanf("%d",&c[i]); ++s[c[i]],tg[c[i]]=true; }
    per(i,n,1) s[fa[i]]+=s[i];
    dfs(0);
    rep(i,1,k) printf("%d ",dp[c[i]]);
    return 0;
}