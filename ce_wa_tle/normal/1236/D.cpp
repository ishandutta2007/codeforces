#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define mem(x) memset(x,0,sizeof(x))
#define memn(x,n) memset(x,0,sizeof(ll)*((n)+1))
typedef long long ll;const ll N=2222221,mod=998244353,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];ll cnt=0,lx=0,ly=0,rx,ry;
ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN head,next,to;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
const ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};ll n,m,k,sum,x,y;
ll solve(ll x,ll y,ll w){
    ll f=0;switch(w){
        case 0:f=ry;for(ll i=head[x],v;v=to[i]-n,i;i=next[i])if(v>y)f=std::min(f,v);lx=x;return f-y-1;
        case 1:f=rx;for(ll i=head[y+n],v;v=to[i],i;i=next[i])if(v>x)f=std::min(f,v);ry=y;return f-x-1;
        case 2:f=ly;for(ll i=head[x],v;v=to[i]-n,i;i=next[i])if(v<y)f=std::max(f,v);rx=x;return y-f-1;
        case 3:f=lx;for(ll i=head[y+n],v;v=to[i],i;i=next[i])if(v<x)f=std::max(f,v);ly=y;return x-f-1;
    }return 0;
}
int main(){
    n=readll(),m=readll(),k=readll(),sum=n*m-k;rep(i,1,k)x=readll(),y=readll()+n,add(x,y),add(y,x);rx=n+1,ry=m+1;
    rfor(ll x=1,y=0,w=0,f;(f=solve(x,y,w));w=(w+1)%4)sum-=f,x+=f*dx[w],y+=f*dy[w];puts(sum?"No":"Yes");return 0; 
}