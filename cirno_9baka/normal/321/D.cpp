#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[105][105],t[105],b[105][105],op[105],ans;
void dfs(int x)
{
	if(x>m)
	{
		int i,j,s=0;
		for(i=1;i<=n;++i)
			op[i]=op[i-1]^t[i];
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				b[i][j]=a[i][j];
		for(i=m;i<=n;++i)
			for(j=1;j<=n;++j)
				if(op[j]^op[max(j-m,0)])
					b[i][j]=-b[i][j];
		for(i=1;i<=n;++i)
			s+=b[m][i];
		for(i=1;i<m;++i)
		{
			for(j=m;j<=n;++j)
			{
				b[i][j]=-b[i][j];
				b[i+m][j]=-b[i+m][j];
			}
			int s1=0;
			for(j=1;j<m;++j)
				s1+=max(b[i][j]+b[i][j+m]+b[i+m][j]+b[i+m][j+m],-(b[i][j]+b[i][j+m]+b[i+m][j]+b[i+m][j+m]));
			s1+=b[i][m]+b[i+m][m];
			for(j=m;j<=n;++j)
			{
				b[i][j]=-b[i][j];
				b[i+m][j]=-b[i+m][j];
			}
			int s2=0;
			for(j=1;j<m;++j)
				s2+=max(b[i][j]+b[i][j+m]+b[i+m][j]+b[i+m][j+m],-(b[i][j]+b[i][j+m]+b[i+m][j]+b[i+m][j+m]));
			s2+=b[i][m]+b[i+m][m];
			s+=max(s1,s2);
		}
		ans=max(ans,s);
		return;
	}
	t[x]=0;
	dfs(x+1);
	t[x]=1;
	dfs(x+1);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	m=n/2+1;
	dfs(1);
	cout<<ans<<endl;
}