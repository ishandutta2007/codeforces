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
const int MAXN=1e5+10;
int n,m,mod;
int fa[MAXN],sz[MAXN],cnt;
int Find(int x){
    if(fa[x]==x)return x;
    return fa[x]=Find(fa[x]);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>mod;
    rep(i,1,n)fa[i]=i,sz[i]=1;
    rep(i,1,m){
        int u,v;cin>>u>>v;
        if(Find(u)==Find(v))continue;
        sz[Find(u)]+=sz[Find(v)];fa[Find(v)]=Find(u);
    }
    ll ans=1;
    rep(i,1,n)if(Find(i)==i)cnt++;
    if(cnt==1){
        cout<<1%mod<<endl;
    }else{
        rep(i,1,cnt-2)ans=ans*n%mod;
        rep(i,1,n)if(Find(i)==i)ans=ans*sz[i]%mod;
        cout<<ans<<endl;
    }
    return 0;
}