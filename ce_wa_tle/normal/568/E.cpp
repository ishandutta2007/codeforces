#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1e5+5,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll n,t,h,m;aN a,b,c,vis,len,sum;
int check(ll l,ll r){
    return~a[l]&&a[l]<a[r]&&len[l]<len[r]&&sum[r]-sum[l]>=len[r]-len[l]-1&&
    std::lower_bound(b+1,b+t+1,a[r])-std::upper_bound(b+1,b+t+1,a[l])>=len[r]-len[l]-1;
}
int main(){
    n=readll()+2,a[1]=-inf,a[n]=inf;rep(i,2,n-1)a[i]=readll(),sum[i]=sum[i-1]+!~a[i];sum[n]=sum[n-1];m=readll();
    rep(i,1,m)b[i]=readll();std::sort(b+1,b+m+1),t=0,h=m+1;rep(i,1,m)c[b[i]==b[i-1]?--h:++t]=b[i];
//    rep(i,1,n)printf("%lld ",sum[i]);puts("");
//    rep(i,1,t)printf("%lld ",c[i]);puts("");
    memcpy(b,c,sizeof(ll)*(m+1)),memset(c,0x3f,sizeof(ll)*(n+1)),c[h=0]=-inf;
    rep(i,1,n){
        if(~a[i])c[len[i]=a[i]>c[h]?++h:std::lower_bound(c,c+h+1,a[i])-c]=a[i];
        else rfor(ll j=t,l=h+1;j;j--){while(b[j]<=c[l-1])l--;l>h&&++h,c[l]=b[j];/*printf("s=%lld\n",b[j]);*/}
//        printf("%lld %lld\n",a[i],h);rep(i,1,h)printf("%lld ",c[i]);puts("");
    }//printf("%lld\n",h);rep(i,1,h)printf("%lld ",c[i]);puts("");
//    rep(i,1,m)printf("%lld ",b[i]);puts("");
//    rep(i,1,n)printf("%lld ",a[i]);puts("");
    rfor(ll i=n;i;){
        ll j=i-1;while(!check(j,i)&&j)j--;ll lj=j;//printf("%lld %lld %lld %lld\n",i,j,a[i],a[j]);
        rfor(ll now=std::upper_bound(b+1,b+t+1,a[j])-b;j<i&&b[now]<a[i];j++)if(!~a[j])a[j]=b[now],vis[now++]=1;i=lj;
    }
//    rep(i,2,n-1)printf("%lld ",a[i]);puts("");
    ll now=1;rep(i,2,n-1)if(!~a[i]){while(vis[now])now++;printf("%lld ",b[now++]);}else printf("%lld ",a[i]);
   	return 0;
}
/*
10
15 15 -1 6 12 8 5 20 -1 17
10
18 1 12 16 5 6 17 5 12 16
*/
/*
100
-1 2 3 74 90 39 37 18 23 -1 5 -1 56 88 99 49 72 11 19 6 81 24 8 23 64 -1 100 77 61 87 23 -1 20 15 -1 55 25 40 4 25 73 85 87 72 5 98 46 49 -1 67 81 58 3 -1 22 14 -1 -1 92 -1 78 53 64 23 84 10 -1 54 83 55 24 -1 79 23 92 41 -1 -1 93 -1 59 90 64 93 95 22 -1 67 -1 33 41 84 37 73 -1 -1 18 49 50 58
20
57 23 22 93 77 19 85 32 79 94 20 59 78 35 16 92 33 94 42 11
*/