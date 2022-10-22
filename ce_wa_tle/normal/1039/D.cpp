#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=4e5+9,mod=998244353;typedef ll aN[N];aN next,to,head,d,deep,t,f,used,ans,id,l;
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll cnt=0,m=0;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v,d[u]++;}
void dfs0(ll u,ll fa,ll lst){
    deep[u]=deep[fa]+1;rfor(ll i=head[u];i;i=next[i])if(to[i]^fa)dfs0(to[i],u,u==1||d[u]!=2?u:lst);
    if(u==1||d[u]!=2)t[id[u]=++m]=lst,l[m]=deep[u]-deep[lst];
}ll getans(ll k){
    ll res=0;rep(i,1,m){
        if(used[i])res++,f[i]=-1;if((f[i]+=l[i])>k)res+=f[i]/(k+1),f[i]%=k+1;
        if(f[i]+f[t[i]]>=k)used[t[i]]=1;if(f[i]>f[t[i]])f[t[i]]=f[i];used[i]=f[i]=0;
    }return res;
}void calc(ll l,ll r,ll ql,ll qr){//printf("%lld %lld %lld %lld\n",l,r,ql,qr);
    if(ql>qr)return;if(l==r){rep(i,ql,qr)ans[i]=l;return;}ll mid=(ql+qr)>>1;ans[mid]=getans(mid);
    calc(ans[mid],r,ql,mid-1),calc(l,ans[mid],mid+1,qr);
}int main(){
    ll n=readll(),u,v;rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);dfs0(1,0,1);rep(i,1,m)t[i]=id[t[i]];
    ans[0]=n;calc(0,n,1,n-1);rep(i,0,n-1)printf("%lld\n",ans[i]);return 0;
}