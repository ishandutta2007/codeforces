#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1000005],fl=-1;
bool vis[100000005];
void dfs(int dep,int ct,int sum,int tp)
{
	if(n-dep+1<ct) return;
//		printf("sum=%d\n",sum);
	if(dep==n+1)
	{
		if(tp==-1)
		{
			vis[sum]=0;
			return;
		}
		if(vis[sum])
		{
			fl=sum;
			return;
		}
		vis[sum]=1;
		return;
	}
	dfs(dep+1,ct,sum,tp);
	if(fl!=-1) return;
	if(ct) dfs(dep+1,ct-1,sum+a[dep],tp);
}
int q=0,b[1000005],tmp[1000005];
void dfs2(int dep,int ct,int sum)
{
	if(n-dep+1<ct) return;
	if(dep==n+1)
	{
		if(sum==fl)
		{
			q++;
			for(int i=1;i<=n;i++)
				if(tmp[i]) b[i]=q;
		}
		return;
	}
	tmp[dep]=0;
	dfs2(dep+1,ct,sum);
	if(q>=2) return;
	if(ct)
	{
		tmp[dep]=1;
		dfs2(dep+1,ct-1,sum+a[dep]);
	}
}
int f[1000005];
void print(int len)
{
	printf("YES\n");
	int t1=1,t2=2;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)
		{
			f[t1]=a[i];
			t1+=2;
		}
		if(b[i]==2)
		{
			f[t2]=a[i];
			t2+=2;
		}
	}
	printf("0 ");
	int nw=0;
	for(int i=1;i<2*len;i++)
	{
		nw=f[i]-nw;
		printf("%d ",nw);
	}
	for(int i=1;i<=n;i++)
		if(!b[i])
			printf("%d ",a[i]);
	printf("\n");
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==2)
	{
		if(a[1]==a[2])
		{
			printf("YES\n");
			printf("%d %d\n",0,a[1]);
		}
		else printf("NO\n");
		return 0;
	}
	sort(a+1,a+n+1);
	m=unique(a+1,a+n+1)-a-1;
	if(m!=n)
	{
		printf("YES\n");
		printf("0 ");
		for(int i=1;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
		return 0;
	}
	int ct0=0,ct1=0;
	for(int i=1;i<=n;i++)
		if(a[i]%2) ct1++;
		else ct0++;
	if(ct0==2&&ct1==1)
	{
		printf("NO\n");
		return 0;
	}
	if(ct0)
	{
		int id=-1,x=-1,y=-1;
		for(int i=1;i<=n;i++)
			if(a[i]%2==0)
			{
				id=i;
				break;
			}
		if(ct0>=3)
		{
			for(int i=1;i<=n;i++)
				if(a[i]%2==0&&i!=id)
				{
					if(x==-1) x=i;
					else if(y==-1) y=i;
				}
		}
		else if(ct1>=2)
		{
			for(int i=1;i<=n;i++)
				if(a[i]%2==1&&i!=id)
				{
					if(x==-1) x=i;
					else if(y==-1) y=i;
				}
		}
		int sum=(a[id]+a[x]+a[y])/2;
		printf("YES\n");
		printf("%d %d %d ",sum-a[id],sum-a[x],sum-a[y]);
		for(int i=1;i<=n;i++)
			if(i!=id&&i!=x&&i!=y)
				printf("%d ",a[i]-(sum-a[id]));
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		dfs(1,i,0,1);
		if(fl!=-1)
		{
			dfs2(1,i,0);
			print(i);
			return 0;
		}
		dfs(1,i,0,-1);
	}
	printf("NO\n");
	return 0;
}