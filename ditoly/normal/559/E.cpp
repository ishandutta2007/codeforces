#include<cstdio>
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
#define MN 100
int a[MN+5],l[MN+5],r[MN+5],c[MN*3+5],cn,g[MN*3+5][MN*3+5],f[MN*3+5];
vector<int> v[MN*3+5],vv[MN*3+5];
int main()
{
	int n=read(),i,j,k,p,x,u;
	for(i=1;i<=n;++i)
	{
		c[++cn]=a[i]=read();l[i]=read();
		c[++cn]=a[i]-l[i];c[++cn]=a[i]+l[i];
	}
	sort(c+1,c+cn+1);cn=unique(c+1,c+cn+1)-c-1;
	for(i=1;i<=n;++i)
	{
		vv[r[i]=lower_bound(c+1,c+cn+1,a[i]+l[i])-c].push_back(i);
		l[i]=lower_bound(c+1,c+cn+1,a[i]-l[i])-c;
		v[a[i]=lower_bound(c+1,c+cn+1,a[i])-c].push_back(i);
	}
	for(i=1;i<=cn;++i)for(g[i][i]=j=1;j<i;++j)for(k=0;k<v[j].size();++k)if(r[v[j][k]]>=i)
	{
		for(p=i,x=j;--p>=x;)for(u=0;u<v[p].size();++u)
			if(v[p][u]!=v[j][k])x=min(x,l[v[p][u]]);
		g[i][x]=1;
	}
	for(i=1;i<=cn;++i)for(j=1;j<=i;++j)for(k=1;k<=j;++k)g[i][k]|=g[i][j]&g[j][k];
	for(i=1;i<=cn;++i)
	{
		f[i]=f[i-1];
		for(p=x=i;p>=x;--p)for(u=0;u<v[p].size();++u)x=min(x,l[v[p][u]]);
		for(j=1;j<=x;++j)if(g[x][j])f[i]=max(f[i],f[j-1]+c[i]-c[j]);
		for(j=0;j<vv[i].size();++j)
		{
			for(p=i,x=a[vv[i][j]];p>=x;--p)for(u=0;u<v[p].size();++u)
				if(v[p][u]!=vv[i][j])x=min(x,l[v[p][u]]);
			for(k=1;k<=x;++k)if(g[x][k])f[i]=max(f[i],f[k-1]+c[i]-c[k]);
		}
	}
	printf("%d",f[cn]);
}