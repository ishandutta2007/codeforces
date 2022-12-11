#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,a[100010],m,b[100010];
int st[100010],tp,p[100010],from[100010];
bool usea[100010],useb[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);a[n+1]=0x3f3f3f3f;
	scanf("%d",&m);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]);
	sort(b+1,b+1+m);
	for(int i=1;i<=n+1;++i)
	{
		if(a[i]!=-1)
		{
			if(a[i]>st[tp])st[++tp]=a[i],p[tp]=i,from[i]=p[tp-1];
			else 
			{
				int x=lower_bound(st+1,st+1+tp,a[i])-st;
				p[x]=i,st[x]=a[i],from[i]=p[x-1];
			}
		}
		else
		{
			if(b[m]>st[tp])st[++tp]=b[m],p[tp]=p[tp-1];
			int last=m;
			for(int j=tp;j;--j)
			{
				while(b[last-1]>st[j-1])--last;
				if(st[j]>=b[last])st[j]=b[last],p[j]=p[j-1];
			}
		}
	//	for(int j=1;j<=tp;++j)printf("%d ",st[j]);printf("\n");
	//	for(int j=1;j<=tp;++j)printf("%d ",p[j]);printf("\n");
	}
//	printf("%d\n",tp);
	int x=p[tp];
	while(x)
	{
//		printf("%d ",x);
		usea[x]=1;
		x=from[x];
	}
//	printf("\n");
	int cnt=0,last=1,lw=0;
	queue<int>q;
	for(int i=1;i<=n+1;++i)
		if(usea[i])
		{
			while(last<m&&b[last]<=lw)++last;
			while(!q.empty()&&b[last]>lw&&b[last]<a[i])
			{
				useb[last]=1;
				a[q.front()]=lw=b[last];
				q.pop();
				while(last<m&&b[last]<=lw)++last;
			}
			while(!q.empty())q.pop();
			lw=a[i];
		}
		else if(a[i]==-1)q.push(i);
//	for(int i=1;i<=n;++i)printf("%d ",a[i]);printf("\n");
//	for(int i=1;i<=m;++i)printf("%d ",useb[i]);printf("\n");
	last=1;
	for(int i=1;i<=n;++i)
		if(a[i]==-1)
		{
			while(useb[last])++last;
			a[i]=b[last];++last;
		}
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}