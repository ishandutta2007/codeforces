#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
struct P{int s,x;}p[MN+5];
bool cmp(const P&a,const P&b){return a.x>b.x;}
ll n,m;ll cnt,ss;
ll cal(ll x)
{
	if(x>cnt)return -1e18;
	ll res=0,s=1LL*x*m;
	for(ll i=1;i<=n;++i)
	{
		res+=min(s,1LL*p[i].s)*p[i].x;
		s-=min(s,1LL*p[i].s);
	}
	return res;
}
main()
{
	ll i,ans=0,l,r,mid,res,s;
	n=read();m=read();
	for(i=1;i<=n;++i)
		cnt+=p[i].s=read(),
		ans+=1LL*p[i].s*(p[i].x=read()),
		p[i].x=read()-p[i].x;
	ss=cnt;cnt=(cnt+m-1)/m;p[++n]=(P){cnt*m-ss,0};
	sort(p+1,p+n+1,cmp);
	for(l=0,r=cnt;l<=r;)
	{
		s=1LL*(mid=l+r>>1)*m;
		for(i=1;i<=n;++i)
		{
			if(s>0&&p[i].x<0)break;
			s-=p[i].s;
		}
		if(i<=n)r=mid-1;else res=mid,l=mid+1;
	}
	printf("%I64d",ans+max(cal(res),cal(res+1)));
}