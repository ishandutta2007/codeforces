#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,i,ans,j,k,m,ex,t[2000005],s;
long long p[2000005],inv[2000005];
void dfs(int i,int l,int r,bool f)
{
	if(l==r)
	{
		if(f)
			t[i]=1;
		return;
	}
	if(r-l+1>=2&&i!=1)
		if(!f)
		{
			t[i<<1|1]=1;
			if(t[i]!=-1)
				t[i<<1]=t[i]^t[i<<1|1];
		}
		else
		{
			t[i<<1]=0;
			if(t[i]!=-1)
				t[i<<1|1]=t[i]^t[i<<1];
		}
	int mid=l+r>>1;
	dfs(i<<1,l,mid,0);
	dfs(i<<1|1,mid+1,r,1);
}
int main()
{
	scanf("%d",&n);
	for(i=1;(1<<i)-1<=n;i++);
	i--;
	m=i;
	ex=n-((1<<m)-1);
	memset(t,-1,sizeof(t));
	dfs(1,1,1<<m-1,0);
	for(i=(1<<m-1);i<(1<<m);i++)
	{
		if(t[i]==1)
			ex--;
		if(t[i]==-1)
			s++;
	}
	if(ex<0||ex>s)
	{
		printf("0");
		return 0;
	}
	inv[0]=inv[1]=p[0]=1;
	for(i=2;i<=2000000;i++)
		inv[i]=inv[M%i]*(M-M/i)%M;
	for(i=1;i<=2000000;i++)
	{
		inv[i]=inv[i-1]*inv[i]%M;
		p[i]=p[i-1]*i%M;
	}
	cout<<(p[s]*inv[ex]%M*inv[s-ex]%M+M)%M;
}