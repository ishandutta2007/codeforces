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
const int MAXN=5e4+10,MAXM=(1<<10),mod=998244353;
int n,m,g[10][10];
int G[MAXM][10];
int f[2][MAXM];
int main(){
    cin>>n>>m;
    rep(i,1,m){
        int u,v;cin>>u>>v;
        g[u][v]=g[v][u]=1;
    }
    rep(i,0,(1<<10)-1){
        rep(j,0,9)if(i>>j&1)continue;else{
            rep(k,0,9)if(g[k][j]){
                if(k<j)G[i][j]|=(1<<k);
                if(i>>k&1)G[i][j]|=(1<<k);
            }
        }
    }
    f[0][0]=1;
    rep(i,0,n-1){
        memset(f[(i+1)&1],0,sizeof f[(i+1)&1]);
        rep(j,0,(1<<10)-1)rep(k,0,9)if(j>>k&1)continue;else{
            f[(i+1)&1][G[j][k]]=(f[(i+1)&1][G[j][k]]+f[i&1][j])%mod;
        }
    }
    int ans=0;
    rep(j,0,(1<<10)-1)ans=(ans+f[n&1][j])%mod;
    cout<<ans;


    return 0;
}