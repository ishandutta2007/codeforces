#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=716333,inf=1e17,mod=1e9+9,k=1000007;typedef ll aN[N];aN p,c,hs;ll flag=0;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct dl{
    ll lim,h,t,q[114514],r[114514];void clear(ll k){lim=k,h=1,t=0;}ll top(){return q[h];}
    void push(ll x){ll now=r[t]+1;while(h<=t&&q[t]<=x)t--;q[++t]=x,r[t]=now;while(r[t]-r[h]+1>lim)h++;}
}t;ll s[55][111111],f[55][111111];
int main(){
    ll n=readll(),m=readll(),k=readll(),max;rep(i,1,n)rep(j,1,m)s[i][j]=s[i][j-1]+readll();
    rep(i,1,m-k+1)f[1][i]=s[1][i+k-1]-s[1][i-1];
    rep(i,2,n+1){
        //f[i][j]=f[i-1][l]+s[j..j+k -1]+s[l..l+k -1](l<=j-k)
        //                 +s[l..j+k -1](j-k<l<=j)
        //                 +s[j..l+k -1](j<=l<j+k)
        //                 +s[j..j+k -1]+s[l..l+k -1](j+k<=l)
        t.clear(k),max=-inf;rep(j,1,m-k+1)j>k&&(max=std::max(max,f[i-1][j-k]+s[i][j-1]-s[i][j-k-1])),
        t.push(f[i-1][j]-s[i][j-1]),f[i][j]=std::max(std::max(f[i][j],max+s[i][j+k-1]-s[i][j-1]),t.top()+s[i][j+k-1]);
//        rep(j,1,m-k+1)printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
        t.clear(k),max=-inf;per(j,m-k+1,1)j+k<=m-k+1&&(max=std::max(max,f[i-1][j+k]+s[i][j+2*k-1]-s[i][j+k-1])),
        t.push(f[i-1][j]+s[i][j+k-1]),f[i][j]=std::max(std::max(f[i][j],max+s[i][j+k-1]-s[i][j-1]),t.top()-s[i][j-1]);
//        rep(j,1,m-k+1)printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
    }printf("%lld\n",f[n+1][m-k+1]);return 0;
}
/*
10 6 2
418 599 255 191 383 201
451 540 635 441 598 383
358 449 561 520 221 25
172 210 456 621 586 161
97 421 192 517 271 394
614 241 267 144 398 429
26 18 39 32 253 171
219 199 384 373 233 248
60 449 336 240 157 653
457 526 236 350 85 541
*/