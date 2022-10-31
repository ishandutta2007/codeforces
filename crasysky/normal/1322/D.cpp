#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define ll long long
using namespace std;
const int N=4003,INF=1e9;
vector<int> dp[N],g;//last_level remain
int l[N],c[N],v[N];
int main(){
    int n,m; cin>>n>>m;
    rep(i,1,n) cin>>l[i];
    rep(i,1,n) cin>>c[i];
    rep(i,1,n+m) cin>>v[i];
    per(i,n,1){
        g.clear(); int s=1;
        rep(j,1,l[i])
            if (dp[j].size()) s=max(s,(int)(dp[j].size()-1>>l[i]-j)+1);
        g.resize(s);
        rep(i,1,s-1) g[i]=-INF;
        rep(j,1,l[i])
            rep(k,0,dp[j].size()-1){
                int x=dp[j][k],y=k;
                for (int t=j+1;t<=l[i]&&y;++t) y>>=1,x+=v[t]*y;
                g[y]=max(g[y],x);
            }
        rep(j,dp[l[i]].size(),s) dp[l[i]].push_back(-INF);
        dp[l[i]][0]=max(dp[l[i]][0],0);
        rep(j,0,s-1) dp[l[i]][j+1]=max(dp[l[i]][j+1],g[j]+v[l[i]]-c[i]);
    }
    int ans=0;
    rep(j,1,m)
        rep(k,0,dp[j].size()-1){
            int x=dp[j][k],y=k;
            for (int t=j+1;y;++t) y>>=1,x+=v[t]*y;
            ans=max(ans,x);
        }
    cout<<ans<<endl;
    return 0;
}