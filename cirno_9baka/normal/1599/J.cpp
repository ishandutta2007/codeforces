#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
const int N=200005;
int f[14000005],a[N],b[N],k,n,i,m,fi,vis[N],av[N],tot,j,nm;
vector<int> g[3];
void dfs(int i,int s,int su)
{
	if(i>m)
	{
		if(f[s]==1)
			fi=s;
		f[s]=1;
		return;
	}
	if(su<nm&&fi==-1)
		dfs(i+1,s+a[i],su+1);
	if(su+n-i>=nm&&fi==-1)
		dfs(i+1,s,su);
}
void dfs2(int i,int s,int su)
{
	if(i>m)
	{
		if(s==fi)
		{
			++tot;
			for(j=1;j<=n;++j)
				if(vis[j])
					av[j]|=tot;
		}
		return;
	}
	if(su<nm&&tot<2)
	{
		vis[i]=1;
		dfs2(i+1,s+a[i],su+1);
	}
	if(su+n-i>=nm&&tot<2)
	{
		vis[i]=0;
		dfs2(i+1,s,su);
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	if(n==2)
	{
		if(a[1]==a[2])
			puts("YES");
		cout<<0<<' '<<a[1]<<endl;
		return 0;
	}
	if(n==3)
	{
		if((a[1]+a[2]+a[3])%2==0)
		{
			puts("YES");
			int x=(a[1]+a[2]+a[3])/2;
			cout<<x-a[1]<<' '<<x-a[2]<<' '<<x-a[3];
		}
		else
			puts("NO");
		return 0;
	}
	for(i=1;i<=n;++i)
		if(a[i]&1^1)
			break;
	if(i<=n)
	{
		puts("YES");
		for(i=1;i<=n;++i)
			if(a[i]&1^1)
				b[++k]=a[i];
		if(k>=3)
		{
			int x=(b[1]+b[2]+b[3])/2;
			cout<<x-b[1]<<' '<<x-b[2]<<' '<<x-b[3]<<' ';
			int w=x-b[1];
			for(i=4;i<=k;++i)
				cout<<b[i]-w<<' ';
			for(i=1;i<=n;++i)
				if(a[i]&1)
					cout<<a[i]-w<<' ';
		}
		else
		{
			int y=k;
			for(i=1;i<=n;++i)
				if(a[i]&1)
					b[++k]=a[i];
			int x=(b[y]+b[y+1]+b[y+2])/2;
			int w=x-b[y];
			cout<<x-b[y]<<' '<<x-b[y+1]<<' '<<x-b[y+2]<<' ';
			for(i=1;i<=n;++i)
				if(i<y||i>y+2)
					cout<<b[i]-w<<' ';
		}
		return 0;
	}
	fi=-1;
	m=min(n,26);
	for(i=1;i<=m/2;++i)
	{
		memset(f,0,sizeof(f));
		nm=i;
		dfs(1,0,0);
		if(fi!=-1)
		{
			dfs2(1,0,0);
			for(i=1;i<=n;++i)
				g[av[i]%3].push_back(a[i]);
			puts("YES");
			cout<<0<<' ';
			int las=0;
			for(i=0;i<g[1].size();++i)
			{
				cout<<g[1][i]-las<<' ';
				las=g[1][i]-las;
				if(i+1!=g[1].size())
				{
					cout<<g[2][i]-las<<' ';
					las=g[2][i]-las;
				}
			}
			for(i=0;i<g[0].size();++i)
				cout<<g[0][i]<<' ';
			return 0;
		}
	}
	puts("NO");
}