#include<cstdio>
#include<algorithm>
#define mid ((l+r)>>1)
#define N 400010
#define ll long long
using namespace std;
struct node{
	ll k,b;
}b[N],c[N],s[N];
int n,k,T,len;
ll a[N],x,ss;
ll ans;
node operator +(node a,node b)
{
	return (node){a.k+b.k,a.b+b.b};
}
node operator -(node a,node b)
{
	return (node){a.k-b.k,a.b-b.b};
}
bool cmp(node a,node b)
{
	return 1ll*a.b*b.k>1ll*b.b*a.k;
}
ll calc(node a,ll x)
{
	return x*a.k+a.b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i].b);
	scanf("%d",&T);
	b[1]=(node){1,0};
	for(int i=1;i<=n;i++)
	{
		for(int j=i+i;j<=n;j+=i)
		{
			a[j]=a[j]-a[i];
			b[j]=b[j]-b[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i].k==0)
		{
			ss+=abs(b[i].b-a[i]);
			continue;
		}
		c[++len]=(node){b[i].k,b[i].b-a[i]};
		if(c[len].k<0) c[len]=(node){-c[len].k,-c[len].b};
	}
	sort(c+1,c+len+1,cmp);
	for(int i=1;i<=len;i++) s[i]=s[i-1]+c[i];
	while(T--)
	{
		scanf("%lld",&x);
		int l=1,r=len;
		while(l<r)
		{
			if(calc(c[mid],x)>=0) l=mid+1;
			else r=mid;
		}
		if(calc(c[l],x)<0) l--;
		ans=calc(s[l],x)-calc(s[len]-s[l],x);
		printf("%lld\n",ans+ss);
	}
}