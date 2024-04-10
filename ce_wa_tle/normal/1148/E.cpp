#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1.5e6+7,mod=1e9+7,mod2=mod*mod,inf=1e18;typedef ll aN[N];aN a,b,c,s;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{ll i,j,d;void print(int c=0){printf("%lld %lld %lld",i,j,d);if(c)putchar(c);}}ans[N];
int cmp(ll x,ll y){return a[x]<a[y];}ll top=0,cnt=0;
int main(){
    ll n=readll();rep(i,1,n)a[c[i]=i]=readll();rep(i,1,n)b[i]=readll();std::sort(b+1,b+n+1),std::sort(c+1,c+n+1,cmp);
    rep(i,1,n){a[c[i]]-=b[i];while(top>=0&&a[c[i]]>0)ans[++cnt]=(node){s[top],c[i],std::min(a[c[i]],-a[s[top]])},
    a[c[i]]+a[s[top]]<0?a[s[top]]+=a[c[i]],a[c[i]]=0:a[c[i]]+=a[s[top--]];if(a[c[i]]>0)break;a[c[i]]&&(s[++top]=c[i]);}
    if(top!=0)return puts("NO"),0;puts("YES");printf("%lld\n",cnt);rep(i,1,cnt)ans[i].print('\n');return 0; 
}