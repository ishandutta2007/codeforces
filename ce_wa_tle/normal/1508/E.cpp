#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=6e5+9;typedef ll aN[N];
ll readll(){
    ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN deep,fa,next,head,to,f,in,a,sx;ll cnt,tp,out,u,v,now;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs(ll u,ll fa){deep[u]=deep[f[u]=fa]+1;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v^fa)dfs(v,u);}
inline void calc(ll&a,ll&b){std::swap(sx[a],sx[b]),std::swap(a,b);}
int dfs2(ll u,ll x){in[u]=++tp;if(a[u]>x&&a[u]!=++now)return 0;
rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(!dfs2(v,x))return 0;return a[u]==++out||a[u]>=x;}
int main(){
    ll n=readll(),g=0,s=0;rep(i,1,n)sx[a[i]=readll()]=i;rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);dfs(1,0);
    memset(head,cnt=0,(n+1)<<3);per(i,n,1)add(f[sx[i]],sx[i]);rep(i,1,n)if(a[f[f[i]]]>a[f[i]]&&a[i]>a[f[i]])s=f[i];
    while(a[f[s]]==a[f[f[s]]?:s]+1)calc(a[s],a[f[s]]),s=f[s],g++;if(!dfs2(1,now=a[1]))puts("NO");
    else{puts("YES");rep(i,1,a[1]-1)g+=deep[sx[i]]-1;printf("%lld\n",g);rep(i,1,n)printf("%lld ",in[i]);}return 0;
}
/*
7
5 2 3 4 6 1 7
1 2
2 3
3 4
1 5
5 6
6 7
*/