#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=0;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return f?x:-x;
}
#define MN 500
#define MK 101
#define eps 1e-12
double g[MN+5][MN+5],v[MN+5][MN+5],f[MN+5],s[MN+5],ans;
int a[MN+5][MN+5],t[MN+5],cnt,r[MN+5],p[MN+5],c[MN+5];
void solve(int n)
{
	int i,j,k;
	for(i=1;i<=n;++i)
	{
		for(j=i;j<=n;++j)if(g[j][i]>eps)
		{
			for(k=i;k<=n;++k)swap(g[i][k],g[j][k]);
			p[i]=j;break;
		}
		for(j=i;++j<=n;)
		{
			v[i][j]=g[j][i]/g[i][i];
			for(k=i;k<=n;++k)g[j][k]-=v[i][j]*g[i][k];
		}
	}
}
void cal(int n,int x)
{
	int i,j;
	for(i=1;i<=n;++i)f[c[i]=i]=(double)a[x][i]/r[x];
	for(i=1;i<=n;++i)
	{
		swap(f[i],f[p[i]]);swap(c[i],c[p[i]]);
		for(j=i;++j<=n;)f[j]-=v[i][j]*f[i];
	}
	for(i=n;i;s[c[i]]=f[i]/=g[i][i],--i)for(j=i;++j<=n;)f[i]-=g[i][j]*f[j];
}
struct mat
{
	double z[MK][MK];
	friend mat operator*(const mat&a,const mat&b)
	{
		mat c;memset(c.z,0,sizeof(c.z));
		for(int i=0;i<MK;++i)for(int j=0;j<MK;++j)
			for(int k=0;k<MK;++k)c.z[i][j]+=a.z[i][k]*b.z[k][j];
		return c;
	}
}x,y;
int main()
{
	int n,m,k,i,j;
	n=read();m=read();k=read()-2;
	for(i=1;i<=n;++i)t[i]=read()?++cnt:0;
	while(m--)++r[i=read()],++r[j=read()],++a[i][j],++a[j][i];
	for(i=1;i<=n;g[i][i]=1,++i)for(j=1;j<=n;++j)g[j][i]=t[i]?0:-(double)a[i][j]/r[i];
	solve(n);
	for(i=1;i<=n;++i)if(t[i])
	{
		cal(n,i);
		for(j=1;j<=n;++j)if(t[j])x.z[t[i]-1][t[j]-1]=s[j];
		y.z[t[i]-1][t[i]-1]=1;
	}
	for(;k;k>>=1,x=x*x)if(k&1)y=y*x;
	cal(n,1);
	for(i=1;i<=n;++i)if(t[i])ans+=s[i]*y.z[t[i]-1][cnt-1];
	printf("%.8lf",ans);
}