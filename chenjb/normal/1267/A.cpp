#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
const int N=200010;
typedef long long ll;
multiset<ll>s;
struct data
{
	int typ;
	ll x,t;
	bool operator<(const data&a){return x<a.x;}
}q[N<<1];
ll v[N<<1];
int n;
int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		ll a,b,t;
		scanf("%lld%lld%lld",&a,&b,&t);b-=t-1;
		q[2*i-1]={1,a,t};
		q[2*i]={-1,b,t};
	}
	sort(q+1,q+2*n+1);
	rep(i,2*n)v[i]=((ll)1e18)+10;
	for(int i=1;i<=2*n;)
	{
		int j=i;
		for(;j<=2*n&&q[j].x==q[i].x;j++)if(q[j].typ==-1)s.erase(s.find(q[j].t));else s.insert(q[j].t);
		if(s.size())v[i]=q[i].x+*s.begin();
		i=j;
	}
	for(int i=2*n-1;i;i--)v[i]=min(v[i],v[i+1]);
	ll now=q[1].x,ans=0;
	for(int i=1;i<=2*n;)
	{
		if(!s.size())
		{
			int j=i;
			for(;j<=2*n&&q[j].x==q[i].x;j++)if(q[j].typ==1)s.insert(q[j].t);else s.erase(s.find(q[j].t));
			now=max(now,q[i].x);
			i=j;
			continue;
		}
		//printf("%lld\n",q[i].x);
		ll t=*s.begin(),tmp=(q[i].x-now)/t;
		ans+=tmp;now+=tmp*t;
		int j=i;
		for(;j<=2*n&&q[j].x==q[i].x;j++)if(q[j].typ==-1)s.erase(s.find(q[j].t));else s.insert(q[j].t);
		if(now<q[i].x&&v[i]>now+t)now+=t,ans++;
		now=max(now,q[i].x);//printf("%lld %lld\n",now,ans);
		i=j;
	}
	printf("%lld\n",ans);
	return 0;
}