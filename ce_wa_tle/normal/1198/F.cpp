#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define nxt y=(y+k[x]%2520+2520)%2520,x=to[x][y%m[x]]
typedef long long ll;const ll N=1e6+7,inf=0x3f3f3f3f3f3f3f3f,mod=998244353;typedef ll aN[N];
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}ll p[22],s[222],id[222],c[22],d[N],a[N];bool f[222][1<<18];
ll n;const ll k=9;
int check(ll s1,ll s2,ll n){
	ll tp=0,ta=0,now,top=0;
	now=a[s1];rfor(ll i=2;i*i<=now;i++)if(now%i==0){p[++tp]=i;while(now%i==0)now/=i;}if(now!=1)p[++tp]=now;ta=tp;
	now=a[s2];rfor(ll i=2;i*i<=now;i++)if(now%i==0){p[++tp]=i;while(now%i==0)now/=i;}if(now!=1)p[++tp]=now;
//	rep(i,1,ta)printf("%lld\n",p[i]);
	rep(i,1,n)if(i!=s1&&i!=s2){ll g=0,fg=0;rep(j,1,tp)if(a[i]%p[j])fg|=1<<(j-1),(c[j]<=k)&&(g=j);
	if(g)++c[g],s[++top]=fg,id[top]=i;}
	const ll m=top,fa=(1<<ta)-1,fp=(1<<tp)-1,fb=fp^fa;memset(f,0,sizeof(f[0])*(m+1));f[0][0]=1;
//	rep(i,1,m)printf("%lld %lld\n",id[i],s[i]);
	rep(i,1,m){const bool*const lst=f[i-1];bool*const now=f[i];rep(S,0,fp)if(lst[S])now[S|(s[i]&fa)]=now[S|(s[i]&fb)]=1;}
	if(!f[m][fp])return 0;puts("YES");ll g=fp;per(i,m,1){/*printf("%lld %lld\n",g,ta);*/const bool*const lst=f[i-1];
	rep(S,0,fp)if(lst[S]){if((S|(s[i]&fa))==g){d[id[i]]=1,g=S;break;}if((S|(s[i]&fb))==g){d[id[i]]=2,g=S;break;}}}
	d[s2]=2;rep(i,1,n)printf("%lld ",d[i]+!d[i]);return 1;
}int main(){
	n=readll();rep(i,1,n)a[i]=readll();
	if(n<=2*(k+1)){rep(i,1,(1<<n)-2){ll g1=0,g2=0;rep(j,1,n)if(i>>(j-1)&1)g1=gcd(g1,a[j]);else g2=gcd(g2,a[j]);
	if(g1==1&&g2==1){puts("YES");ref(j,0,n)printf("%lld ",(i>>j&1)+1);return 0;}}puts("NO");return 0;}
	rep(i,1,10)if(check(1,rand()%(n-1)+2,n))return 0;puts("NO");return 0; 
}