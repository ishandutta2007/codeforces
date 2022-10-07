#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N],ans[N],i,st[N],tr[N],id[N*N],j;
int main()
{
	scanf("%d",&n);
	scanf("%d %d",&tr[0],&st[0]);
	for(i=1;i<=n+2;++i)
		id[(i-1)*(i-2)/2]=i;
	memset(a,-1,sizeof(a));
	for(i=1;i<=n-1;++i)
	{
		printf("+ %d\n",i);
		fflush(stdout);
		scanf("%d %d",&tr[i],&st[i]);
		if(tr[i]>tr[i-1])
		{
			ans[i]=id[tr[i]-tr[i-1]]-1;
			a[i]=ans[i]+1;
		}
	}
	printf("+ %d\n",1);
	fflush(stdout);
	scanf("%d %d",&tr[n],&st[n]);
	ans[1]=id[tr[n]-tr[n-1]]-2;
	a[1]=ans[1]+1;
	if(a[2]==-1&&a[3]==-1)
	{
		if(st[1]==st[2])
		{
			ans[3]=0;
			a[3]=1;
			ans[2]=st[n]-st[n-1]-1;
			a[2]=st[n]-st[n-1];
		}
		else
		{
			ans[3]=1;
			a[3]=2;
			ans[2]=(st[n]-st[n-1])/2-1;
			a[2]=(st[n]-st[n-1])/2;
		}
	}
	else
		if(a[2]==-1)
		{
			ans[2]=(st[n]-st[n-1])/a[3]-1;
			a[2]=(st[n]-st[n-1])/a[3];
		}
		else
		{
			ans[3]=(st[n]-st[n-1])/a[2]-1;
			a[3]=(st[n]-st[n-1])/a[2];
		}
	for(i=3;i<n;++i)
	{
		if(a[i]==-1)
		{
			a[i]=2;
			ans[i]=1;
		}
		if(st[i]-st[i-1]==a[i-1]*a[i-2])
		{
			a[i+1]=1;
			ans[i+1]=0;
		}
	}
	++a[1];
	for(i=0;i<=n;++i)
	{
		ans[n]=i;
		a[n]=i;
		int s=0;
		for(j=1;j<=n-2;++j)
			s+=a[j]*a[j+1]*a[j+2];
		if(s==st[n])
			break;
	}
	printf("!");
	for(i=1;i<=n;++i)
		printf(" %d",ans[i]);
}