#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define mem(x,y) memset(x,y,sizeof(x))
typedef long long ll;const ll N=422222,mod=998244353;typedef ll aN[N];aN a,f[2]; 
void qmin(ll&a,ll b){if(a>b)a=b;}
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll getbit(ll a,ll w){if(w>=64)return 0;else return a>>w&1;}
void sort(ll c,ll n,ll*a){if(c<0)return;
    ll w[2]={0,0};static ll b[N];memcpy(b+1,a+1,sizeof(ll)*n);
    rep(i,1,n)w[getbit(a[i],c)]++;w[0]+=w[1];per(i,n,1)a[w[getbit(b[i],c)]--]=b[i];
}int main(){
    ll n=readll();rep(i,1,n)a[i]=readll();std::sort(a+1,a+n+1);rep(i,1,n)a[i]=a[n]-a[i];mem(f[1],0x3f),f[1][0]=0;
    rep(w,0,69){
        sort(w-1,n,a),memcpy(f[0],f[1],sizeof(f[0])),mem(f[1],0x3f);ll cnt=0,now=0;rep(i,1,n)cnt+=getbit(a[i],w);
        rep(i,0,n)now+=getbit(a[i],w),qmin(f[1][i+cnt-now],f[0][i]+now*2+n-i-cnt),qmin(f[1][now],f[0][i]+i+cnt-now*2);
    }printf("%lld\n",f[1][0]);return 0; 
}