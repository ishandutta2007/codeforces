#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 400
int r[MN+5],g[MN+5][MN+5],q[MN+5],qn;
double f[MN+5],F[MN+5];
double ans,a,b,c;
vector<int> v[MN+5];
int main()
{
	int n,m,i,j,k,l;
	n=read();m=read();
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(i!=j)g[i][j]=n;
	while(m--)++r[i=read()],++r[j=read()],g[i][j]=g[j][i]=1;
	for(k=1;k<=n;++k)for(i=1;i<=n;++i)for(j=1;j<=n;++j)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(i=1;i<=n;++i)
	{
		for(j=0;j<n;++j)v[j].clear();
		for(j=1;j<=n;++j)v[g[i][j]].push_back(j);
		for(j=a=0;j<n;++j)if(v[j].size())
		{
			b=1./v[j].size();
			memset(f,0,sizeof(f));
			for(k=qn=0;k<v[j].size();++k)for(l=1;l<=n;++l)
				if(g[v[j][k]][l]==1)f[l]?0:q[++qn]=l,f[l]+=b/r[v[j][k]];
			for(k=1;k<=n;++k)
			{
				for(l=1;l<=qn;++l)F[g[k][q[l]]]=max(F[g[k][q[l]]],f[q[l]]);
				for(c=0,l=1;l<=qn;++l)if(F[g[k][q[l]]])
					c+=F[g[k][q[l]]],F[g[k][q[l]]]=0;
				b=max(b,c);
			}
			a+=b*v[j].size()/n;
		}
		ans=max(ans,a);
	}
	printf("%.12lf",ans);
}