#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
int n,m,i,head[500005],Next[1000005],adj[1000005],sta[500005],top,dfn[500005],s[500005],p,u[500005],v[500005],d[500005],num[500005],vis[500005],k,j;
long long e,p2[500015],ans,sum;
vector<int> ex[500005];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int fa)
{
	int j,m;
	dfn[i]=++k;
	sta[++top]=i;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
		{
			if(dfn[adj[j]]==0)
				dfs(adj[j],i);
			else
				if(dfn[adj[j]]<dfn[i])
				{
					p++;
					for(m=top;;m--)
					{
						num[p]+=d[sta[m]];
						vis[sta[m]]++;
						ex[sta[m]].push_back(p);
						s[p]++;
						if(sta[m]==adj[j])
							break;
					}
				}
		}
	top--;
}
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&u[i],&v[i]);
		Push(u[i],v[i]);
		Push(v[i],u[i]);
		d[u[i]]++;
		d[v[i]]++;
	}
	k=0;
	dfs(1,0);
	p2[0]=1;
	for(i=1;i<=n+5;i++)
		p2[i]=p2[i-1]*2%M;
	e=(n*p2[n-1]-m*p2[n-2])%M;
	for(i=1;i<=p;i++)
		e=(e+p2[n-s[i]])%M;
	e=e*qpow(p2[n],M-2)%M;
	ans=(ans-e*e)%M;
	sum=(-m*qpow(4,M-2)+n*qpow(2,M-2))%M;
	for(i=1;i<=p;i++)
	{
		sum=(sum+qpow(p2[s[i]],M-2))%M;
		ans=(ans-qpow(p2[s[i]],M-2)*qpow(p2[s[i]],M-2)+qpow(p2[s[i]],M-2))%M;
	}
	ans=(ans+sum*sum)%M;
	for(i=1;i<=p;i++)
		ans=(ans-qpow(p2[s[i]+2],M-2)*2*(num[i]-s[i])-qpow(p2[s[i]+2],M-2)*4*s[i]+qpow(p2[s[i]+1],M-2)*2*s[i])%M;
	long long tot=qpow(16,M-2);
	ans+=tot*m*2;
	for(i=1;i<=m;i++)
		ans=(ans+tot*(d[u[i]]+d[v[i]]-1))%M;
	ans=(ans+qpow(4,M-2)*n)%M;
	ans=(ans-qpow(8,M-2)*m*2*2)%M;
	for(i=1;i<=n;i++)
	{
		sum=0;
		long long ru=0;
		for(j=0;j<ex[i].size();j++)
		{
		    long long tmp=qpow(p2[s[ex[i][j]]],M-2);
			sum=(sum+tmp)%M;
			ru=(ru+tmp*tmp)%M;
		}
		ans=(ans+sum*sum-ru)%M;
	}
	cout<<(ans%M+M)%M;
}