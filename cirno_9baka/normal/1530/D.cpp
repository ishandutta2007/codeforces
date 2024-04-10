#include<bits/stdc++.h>
using namespace std;
const int M=998244353,L=5000,N=1000005;
int n,i,t,m,j,a[N],b[N],p[N],vis[N],u[N],id[N];
vector<int> x,y,z;
bool cmp(int x,int y)
{
	return u[x]<u[y];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			u[i]=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			vis[i]=p[i]=0;
			id[i]=i;
			++u[a[i]];
		}
		sort(id+1,id+1+n,cmp);
		vis[0]=2;
		for(int k=1;k<=n;++k)
		{
			i=id[k];
			if(!vis[i])
			{
				int las=0;
				for(j=i;!vis[j];j=a[j])
				{
					las=j;
					vis[j]=1;
				}
				if(i!=j)
				{
					if(vis[j]==1)
						a[las]=0;
					for(j=i;vis[j]==1;j=a[j])
						vis[j]=2;
				}
			}
		}
		for(i=1;i<=n;++i)
			if(a[i])
				if(!p[a[i]])
					p[a[i]]=1;
				else
					a[i]=0;
		x.clear(),y.clear(),z.clear();
		int s=0;
		for(i=1;i<=n;++i)
		{
			if(a[i]!=0)
				++s;
			if(p[i]==0&&a[i]==0)
				z.push_back(i);
			else
				if(p[i]==0)
					x.push_back(i);
				else
					if(a[i]==0)
						y.push_back(i);
		}
		for(i=0;i<z.size();++i)
		{
			a[z[i]]=x[0];
			x[0]=z[i];
		}
		for(i=0;i<x.size();++i)
			a[y[i]]=x[i];
		printf("%d\n",s); 
		for(i=1;i<=n;++i)
			printf("%d ",a[i]);
		printf("\n");
	}
}