#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pb push_back
#define LL long long
#define int LL
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N=2e5+50,mod=1e9+7;
int n,k,a[N],sz[N],dat,sum,rt,nn[N][2],ss[N][2],mxx,ans;bool vis[N];
struct node{
    int a[N],st[N],tp;
    void add(int x,int y){st[++tp]=x;for(;x<=n;x+=x&-x)(a[x]+=y)%=mod;}
    int ask(int x){LL z=0;for(;x;x-=x&-x)z+=a[x];return z%mod;}
    int query(int x){return x>0?ask(x):0;}
    void clear(int x){for(;x<=n;x+=x&-x)a[x]=0;}
    void clear(){while(tp)clear(st[tp--]);}
}sm[2],num[2];
vector<pii>v[N];
void cmax(int &x,int y){y>x?x=y:0;}
void findr(int x,int ff){
    sz[x]=1;int now=0;
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i].fi;
        if(y==ff||vis[y])continue;
        findr(y,x);cmax(now,sz[y]);
        sz[x]+=sz[y];
    }
    cmax(now,sum-sz[x]);
    if(now<dat)dat=now,rt=x;
}
void dfs(int x,int ff,int la,int z,int zu,int quan){
    nn[z][zu]++;(ss[z][zu]+=quan)%=mod;
    cmax(mxx,z);
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i].fi;
        if(y==ff||vis[y])continue;
        if(v[x][i].se==la)dfs(y,x,la,z,zu,(quan+a[y])%mod);
        else dfs(y,x,v[x][i].se,z+1,zu,(quan+a[y])%mod);
    }
}
void solve(int x){
    vis[x]=1;
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i].fi,op=v[x][i].se;
        if(vis[y])continue;mxx=0;
        dfs(y,x,op,1,op,a[y]);
        for(int j=1;j<=mxx;j++){
            ans=(ans+1ll*ss[j][op]*num[op^1].query(k+1-j)+1ll*nn[j][op]*sm[op^1].query(k+1-j))%mod;
        // if(x==2)cout<<y<<" "<<ans<<"----"<<endl;
            ans=(ans+1ll*ss[j][op]*num[op].query(k+2-j)+1ll*nn[j][op]*sm[op].query(k+2-j))%mod;
        // if(x==2)cout<<y<<" "<<ans<<"----"<<endl;
        }
        for(int j=1;j<=mxx;j++){
            num[op].add(j,nn[j][op]);sm[op].add(j,(ss[j][op]+1ll*nn[j][op]*a[x])%mod);
            ss[j][op]=nn[j][op]=0;
        }
        // for(int j=mxx,l=0,now=0;j;j--){
        //     while(l<mxx&&j+l+1<=k+1)l++,ans=(ans+1ll*num[j][op^1]*ss[l][op]+1ll*sum[j][op^1]*nn[l][])
        // }
    }
    ans=(0ll+ans+sm[0].query(k+1)+sm[1].query(k+1))%mod;
    sm[0].clear();sm[1].clear();num[0].clear();num[1].clear();
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i].fi;
        if(vis[y])continue;
        sum=sz[y];dat=1e9;findr(y,x);solve(rt);
    }
}
signed main(){
    // sm[0].clear();sm[1].clear();num[0].clear();num[1].clear();
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),(ans+=a[i])%=mod;
    for(int i=1,x,y,z;i<n;i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        v[x].pb(mp(y,z));
        v[y].pb(mp(x,z));
    }
    dat=1e9;sum=n;findr(1,0);solve(rt);
    printf("%lld\n",ans);
    return 0;
}
// 5 4
// 1 3 2 6 4
// 1 2 1
// 1 4 0
// 3 2 1
// 2 5 0