#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int g=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}
int n,m,cnta,cntb,a[100010],b[100010],cnt,cnt1;
long long ans;
vector<int>r[200020];
pair<int,int>q[200020];
map<int,bool>mpa,mpb;
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%d",&cnta);
	for(int i=1;i<=cnta;++i)scanf("%d",&a[i]),mpa[a[i]]=1;
	scanf("%d",&cntb);
	for(int i=1;i<=cntb;++i)scanf("%d",&b[i]),mpb[b[i]]=1;
	int g=gcd(n,m);
	if(g>cnta+cntb)return printf("-1"),0;
	sort(a+1,a+1+cnta);
	sort(b+1,b+1+cntb);
	for(int i=1;i<=cnta;++i)if(!mpb[a[i]%m])ans=max(ans,1ll*a[i]),mpb[a[i]%m]=1;
	for(int i=1;i<=cntb;++i)if(!mpa[b[i]%n])ans=max(ans,1ll*b[i]),mpa[b[i]%n]=1;
//	printf("%lld\n",ans);
	for(int i=1;i<=cnta;++i)r[a[i]%g].push_back(a[i]);
	for(int i=1;i<=cntb;++i)r[b[i]%g].push_back(b[i]);
	n/=g,m/=g;
	int x,y;
	exgcd(n,m,x,y);
	(x-=x/m*m)<0?x+=m:0;
	(y-=y/n*n)<0?y+=n:0;
	for(int i=0;i<g;++i)
	{
		if(!r[i].size())return printf("-1"),0;
		cnt=0;cnt1=0;
		for(auto p:r[i])q[++cnt]=make_pair(1ll*p/g*x%m,p);
		sort(q+1,q+1+cnt);
		for(int j=1;j<=cnt;++j)
			if(j==1||q[j].first!=q[cnt1].first)q[++cnt1]=q[j];
		cnt=cnt1;
	//	for(int j=1;j<=cnt;++j)printf("%d %d\n",q[j].first,q[j].second);
		q[cnt+1]=q[1];q[cnt+1].first+=m;
		for(int j=1;j<=cnt;++j)if(q[j+1].first-q[j].first>1)ans=max(ans,1ll*n*g*(q[j+1].first-q[j].first-1)+q[j].second);
		
		cnt=0;cnt1=0;
		for(auto p:r[i])q[++cnt]=make_pair(1ll*p/g*y%n,p);
		sort(q+1,q+1+cnt);
		for(int j=1;j<=cnt;++j)
			if(j==1||q[j].first!=q[cnt1].first)q[++cnt1]=q[j];
		cnt=cnt1;
	//	for(int j=1;j<=cnt;++j)printf("%d %d\n",q[j].first,q[j].second);
		q[cnt+1]=q[1];q[cnt+1].first+=n;
		for(int j=1;j<=cnt;++j)if(q[j+1].first-q[j].first>1)ans=max(ans,1ll*m*g*(q[j+1].first-q[j].first-1)+q[j].second);
	}
	printf("%lld",ans);
	return 0;
}