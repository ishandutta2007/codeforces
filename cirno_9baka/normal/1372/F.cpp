#include<bits/stdc++.h>
using namespace std;
int n,x,y,i,ans[200005];
void color(int l,int r,int x)
{
	for(int i=l;i<=r;++i)
		ans[i]=x;
}
void dfs(int l,int r,int x,int y)
{
	int j;
	if(l>r)
		return;
	if(y==r-l+1)
	{
		color(l,r,x);
		return;
	}
	int a[(r-l+1)/y+5],b[(r-l+1)/y+5],k=0;
	for(j=l;j<=r;j+=y)
	{
		printf("? %d %d\n",j,min(j+y-1,r));
		fflush(stdout);
		int p,q;
		scanf("%d %d",&p,&q);
		a[++k]=p,b[k]=q;
	}
	a[k+1]=b[k+1]=0;
	int al,ar;
	for(j=1;j<=k;++j)
		if(a[j]==x)
		{
			if(a[j+1]==x||b[j]==y)
			{
				al=l+j*y-b[j],ar=l+j*y-b[j]+y-1;
				color(al,ar,x);
			}
			else
			if(j==k&&b[j]==(r-l)%y+1)
			{
				al=r-y+1,ar=r;
				color(al,ar,x);
			}
			else
			{
				printf("? %d %d\n",l+j*y-1,l+j*y-1);
				fflush(stdout);
				int p,q;
				scanf("%d %d",&p,&q);
				if(p==x)
				{
					al=l+j*y-b[j],ar=l+j*y-b[j]+y-1;
					color(al,ar,x);
				}
				else
				{
					al=l+j*y-y+b[j]-y,ar=l+j*y-y+b[j]-1;
					color(al,ar,x);
				}
			}
			break;
		}
	for(j=1;j<=k;++j)
	{
		int ul=l+j*y-y,ur=min(l+j*y-1,r);
		if(ul>=al&&ur<=ar)
			continue;
		if(ul<=al&&ur>=al)
		{
			if(a[j]==x)
			{
				printf("? %d %d\n",ul,al-1);
				fflush(stdout);
				int p,q;
				scanf("%d %d",&p,&q);
				dfs(ul,al-1,p,q);
			}
			else
				dfs(ul,al-1,a[j],b[j]);
			continue;
		}
		if(ul<=ar&&ur>=ar)
		{
			if(a[j]==x)
			{
				printf("? %d %d\n",ar+1,ur);
				fflush(stdout);
				int p,q;
				scanf("%d %d",&p,&q);
				dfs(ar+1,ur,p,q);
			}
			else
				dfs(ar+1,ur,a[j],b[j]);
			continue;
		}
		dfs(ul,ur,a[j],b[j]);
	}
}
int main()
{
	scanf("%d",&n);
	printf("? %d %d\n",1,n);
	fflush(stdout);
	scanf("%d %d",&x,&y);
	dfs(1,n,x,y);
	printf("! ");
	for(i=1;i<=n;++i)
		printf("%d ",ans[i]);
}