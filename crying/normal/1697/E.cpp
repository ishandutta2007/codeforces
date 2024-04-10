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
const ll MAXN=110,mod=998244353,INF=1e18;
int n,x[MAXN],y[MAXN],fa[MAXN],sz[MAXN];
ll mind[MAXN];
ll d(int a,int b){
    ll xa=x[a]-x[b],ya=y[a]-y[b];
    return abs(xa)+abs(ya);
}
int Find(int x){
    if(fa[x]==x)return x;
    return fa[x]=Find(fa[x]);
}
void Merge(int x,int y){
    x=Find(x);y=Find(y);if(x==y)return;
    fa[x]=y;sz[y]+=sz[x];
}
int check(vector<int> a,vector<int> b){
    sort(a.begin(),a.end());sort(b.begin(),b.end());
    int sza=a.size(),szb=b.size();if(sza!=szb)return 0;
    rep(i,0,sza-1)if(a[i]!=b[i])return 0;
    return 1;
}
int a[MAXN],tot;
int dp[MAXN][MAXN],p[MAXN][MAXN];
int main(){
    cin>>n;
    rep(i,1,n){
        rep(j,1,i){
            p[i][j]=1;
            rep(k,1,j)p[i][j]=1ll*p[i][j]*(i-k+1)%mod;
        }
    }
    rep(i,1,n)fa[i]=i,sz[i]=1;
    rep(i,1,n)cin>>x[i]>>y[i];
    rep(i,1,n){
        mind[i]=INF;
        rep(j,1,n)if(i!=j)mind[i]=min(mind[i],d(i,j));
    }
    rep(i,1,n){
        int flag=1;vector<int>std;std.clear();std.push_back(i);
        rep(j,1,n)if(d(i,j)==mind[i])std.push_back(j);
        for(auto u:std){
            if(mind[u]!=mind[i]){flag=0;break;}
            vector<int>cmp;cmp.clear();cmp.push_back(u);
            rep(v,1,n)if(d(u,v)==mind[u])cmp.push_back(v);
            if(!check(std,cmp)){flag=0;break;}
        }
        if(flag){
            for(auto u:std)Merge(u,i);
        }
    }
    rep(i,1,n)if(Find(i)==i)a[++tot]=sz[i];
    dp[0][0]=1;
    rep(i,0,tot-1)rep(j,0,n-1){
        dp[i+1][j+1]=(dp[i+1][j+1]+1ll*dp[i][j]*(n-j)%mod)%mod;
        if(n-j>=a[i+1] && a[i+1]!=1){
            dp[i+1][j+a[i+1]]=(dp[i+1][j+a[i+1]]+1ll*dp[i][j]*p[n-j][a[i+1]]%mod)%mod;
        }
    }
    int ans=0;
    rep(i,1,n)ans=(ans+dp[tot][i])%mod;
    cout<<ans;
    return 0;
}