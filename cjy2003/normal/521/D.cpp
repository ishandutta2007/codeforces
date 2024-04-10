#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int k,n,m;
long long a[100010];
pair<int,int>s[100010];
priority_queue<pair<int,int> >q[100010];
priority_queue<pair<double,int> >Q;
int tp;
pair<double,int>mu[100010];
int pre[100010],pos,c[100010];
double sum[100010],ans;
int res[100010],cnt;
bool cmp(int x,int y){return c[x]<c[y];}
int main()
{
	scanf("%d %d %d",&k,&n,&m);
	for(int i=1;i<=k;++i)scanf("%d",&a[i]);
	int t,x,y;
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d %d",&t,&x,&y);
		c[i]=t;
		if(t==1)s[x]=max(s[x],make_pair(y,i));
		else if(t==2)q[x].push(make_pair(y,i));
		else mu[++tp]=make_pair(log(y),i);
	}
	for(int i=1;i<=k;++i)
	{
		if(s[i].first>a[i])q[i].push(make_pair(s[i].first-a[i],s[i].second));
		if(q[i].size())Q.push(make_pair(log(a[i]+q[i].top().first)-log(a[i]),i));
	}
	sort(mu+1,mu+1+tp);
	for(int i=tp;i;--i)sum[i]=sum[i+1]+mu[i].first;
	double now=0;
	ans=sum[max(1,tp-m+1)];
	for(int i=1;i<=m;++i)
	{
		if(!Q.size())break;
		auto p=Q.top();Q.pop();
		x=p.second;now+=p.first;
		pre[i]=q[x].top().second;
		a[x]+=q[x].top().first;
		q[x].pop();
		if(q[x].size())Q.push(make_pair(log(a[x]+q[x].top().first)-log(a[x]),x));
		if(now+sum[max(1,tp-m+1+i)]>ans)
		{
			ans=now+sum[max(1,tp-m+1+i)];
			pos=i;
		}
	}
	for(int i=1;i<=pos;++i)res[++cnt]=pre[i];
	for(int i=max(1,tp-m+1+pos);i<=tp;++i)res[++cnt]=mu[i].second;
	sort(res+1,res+1+cnt,cmp);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)printf("%d ",res[i]);
	return 0;
}