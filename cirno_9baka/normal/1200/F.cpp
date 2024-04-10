#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2520;
int n,i,k,j,e[1005][15],vis[1005][2520],a[1005],m[1005],ans[1005][2520],q,x,y,u[1005];
int dfs(int i,int c)
{
	c=(c%M+M)%M;
	if(ans[i][c]!=0)
		return ans[i][c];
	if(vis[i][c]==1)
	{
		int p=i,t=c,s=0;
		while(1)
		{
			t+=a[p];
			t=(t%M+M)%M;
			p=e[p][t%m[p]];
			if(u[p]==0)
			{
				u[p]=1;
				s++;
			}
			if(t==c&&p==i)
				break;
		}
		while(1)
		{
			t+=a[p];
			t=(t%M+M)%M;
			p=e[p][t%m[p]];
			u[p]=0;
			if(t==c&&p==i)
				break;
		}
		return ans[i][c]=s;
	}
	vis[i][c]=1;
	int cc=(c+a[i]);
	cc=(cc%M+M)%M;
	return ans[i][c]=dfs(e[i][cc%m[i]],cc);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
		for(j=0;j<m[i];j++)
			scanf("%d",&e[i][j]);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",dfs(x,y));
	}
}