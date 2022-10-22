#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=33333,inf=1e17,mod=998244353;typedef ll aN[N];aN s,l,v,f[16][16],pos[16][16],chs[16][16];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
void calc(ll cases){
    ll n=readll(),z=(1<<n)-1,li=0,lj=0;ref(i,0,n)s[1<<i]=readll(),v[i]=i+1;rep(i,2,z)s[i]=s[i&~-i]+s[i&-i],l[i]=l[i>>1]+1;
    rep(i,1,n)ref(j,0,n)memset(f[i][j],0x3f,sizeof(ll)<<n);rep(S,1,z)f[1][l[S&-S]][S]=s[S]/*,printf("f[%lld][%lld][%lld]=%lld\n",1ll,l[S&-S],S,f[1][l[S&-S]][S])*/;(void)cases;
    rep(i,1,n)ref(j,0,n)rep(S,1,z)if(S>>j&1)if(f[i][j][S]<inf&&(/*printf("f[%lld][%lld][%lld]=%lld\n",i,j,S,f[i][j][S]),*/S==z?li=i,lj=j:1))
    rfor(ll T=z^S,d,tj;(d=T>>j);T=(T-1)&~S)if(s[T]>f[i][j][S]&&s[T]<f[i+1][tj=l[d&-d]+j][T^S])
    /*printf("s[%lld]=%lld %lld %lld\n",T,s[T],tj,d),*/f[i+1][tj][T^S]=s[T],pos[i+1][tj][T^S]=j,chs[i+1][tj][T^S]=S;
    printf("%lld\n",n-li);for(ll lS=z,t,T;T=lS^chs[li][lj][lS],li;lS=chs[li][lj][t=lS],lj=pos[li][lj][t],li--)
    ref(i,0,n)if((T>>i&1)&&i!=lj){printf("%lld %lld\n",v[i],v[lj]);ref(j,i+1,n)v[j]--;}
}
int main(){ll T=readll(),cnt=0;while(T --> 0)calc(++cnt);return 0;}
/*
1
2
3 3
1
3
3 2 1
*/