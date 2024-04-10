#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1e5+5,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N],aN30[N*30];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
const ll mod1=1e9+7,mod2=1e9+7,k1=114,k2=514;aN p1,p2,val1,val2;char s[N];ll now=0;
struct str{
    ll len,start,*val1,*val2;
    void read(){
        scanf("%s",s+1),val1=::val1+now,val2=::val2+now,start=now,now+=len=strlen(s+1);
        rep(i,1,len)val1[i]=(val1[i-1]*k1+s[i])%mod1,val2[i]=(val2[i-1]*k2+s[i])%mod2;
    }
    ll hash(ll l,ll r){
        return(val1[r]-val1[l-1]*p1[r-l+1]%mod1+mod1)%mod1*mod2+(val2[r]-val2[l-1]*p2[r-l+1]%mod2+mod2)%mod2;
    }
}st[33];
int eq(ll x,ll n,ll y){ll l=std::min(st[x].len-n+1,st[y].len);
//printf("==%lld %lld %lld %lld %lld %lld\n",x,n,y,l,st[x].hash(n,n+l-1),st[y].hash(1,l));
return st[x].hash(n,n+l-1)==st[y].hash(1,l);}
aN head,vis,in;ll cnt=0,flag=0;aN30 next,to;
void add(ll u,ll v){/*printf("add %lld %lld\n",u,v);*/next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs(ll u){
    if((flag|=in[u])||vis[u])return;vis[u]=in[u]=1;
    rfor(ll i=head[u];i;i=next[i])if(flag)return;else dfs(to[i]);in[u]=0;
}
int check(ll l,ll r){
    memset(vis,flag=cnt=0,sizeof vis),memset(in,0,sizeof in),memset(head,0,sizeof head);
    rep(i,l,r)add(0,st[i].start+1);
    rep(i,l,r)rep(now,1,st[i].len)rep(j,l,r)if(eq(i,now,j)){
//        printf("==%lld %lld %lld %lld %lld %lld %lld\n",i,now,j,st[i].len-now+1,st[j].len,st[j].start,st[i].len-j+2);
        if(st[i].len-now+1<st[j].len)add(st[i].start+now,st[j].start+st[i].len-now+2);
        if(st[i].len-now+1==st[j].len)if(now!=1)add(st[i].start+now,0);
        if(st[i].len-now+1>st[j].len)add(st[i].start+now,st[i].start+st[j].len+now);
    }
    rep(i,0,::now)dfs(i);/*printf("%lld %lld %lld\n",l,r,flag);*/return!flag;
}
int main(){
    ll n=readll(),ans=0;p1[0]=p2[0]=1;rep(i,1,N)p1[i]=p1[i-1]*k1%mod1,p2[i]=p2[i-1]*k2%mod2;rep(i,1,n)st[i].read();
    ll r=0;rep(l,1,n){while(r<l-1||(r<n&&check(l,r+1)))r++;ans+=r-l+1;}printf("%lld\n",ans);return 0;
    return 0;
}