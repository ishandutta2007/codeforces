#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define mem(x) memset(x,0,sizeof(x))
#define memn(x,n) memset(x,0,sizeof(ll)*((n)+1))
typedef long long ll;const ll N=2222221,mod=1e9+7,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];aN size,next,head,to,d,can;
ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll cnt=0;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs0(ll u,ll fa,ll n){
    size[u]=1;ll max=0;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v^fa)dfs0(v,u,n),size[u]+=size[v],
    max=std::max(max,size[v]);can[u]=size[u]*2>=n&&max*2<=n;
}int dfs2(ll u,ll fa){
    ll flag=1,cnt=0;ll max=0;size[u]=1;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(to[i]^fa&&flag)flag=dfs2(v,u),
    size[u]+=size[v],max=std::max(max,size[v]),cnt++;return flag&&(!cnt||(cnt==2&&size[u]==max*2+1));
}int dfs3(ll u,ll fa,ll lim){
    ll flag=1,cnt=0;ll max=0;size[u]=1;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(to[i]^fa&&flag)flag=dfs3(v,u,lim),
    size[u]+=size[v],max=std::max(max,size[v]),cnt++;if(u==lim)size[u]++,cnt--;return flag&&(!cnt||(cnt==2&&size[u]==max*2+1));
}int calc(){
    ll n=(1ll<<readll())-2,u,v;rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u),d[u]++,d[v]++;
    dfs0(1,0,n);ll l=0,f=0,cnt=0;rep(i,1,n)if(can[i])cnt++,f=f?:i,l=i;if(cnt>2)return puts("0");
    if(cnt==2&&dfs2(l,f)&&dfs2(f,l))return printf("2\n%lld %lld\n",f,l);//puts("???");
    rfor(ll root=f;root;root==l?root=0:root=l){//printf("root=%lld %lld %lld\n",root,f,l);
    d[root]++;cnt=0;rep(i,1,n)switch(d[i]){case 1:case 3:break;case 2:case 4:cnt++,f=i;break;default:cnt=2;}//printf("%lld %lld\n",cnt,f);
    d[root]--;if(cnt!=1||!dfs3(root,0,f))continue;return printf("1\n%lld\n",f);}return puts("0");
}int main(){calc();return 0;}