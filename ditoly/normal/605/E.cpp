#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 1000
int u[MN+5];
double p[MN+5][MN+5],v[MN+5],r[MN+5],z;
int main()
{
	int n=read(),i,j,k;
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)p[i][j]=read(),p[i][j]/=100;
	for(i=1;i<n;++i)r[i]=1;
	for(i=1;i<=n;++i)
	{
		if(i>1)
		{
			for(j=1,z=1e99;j<n;++j)if(!u[j]&&r[j]<1)
				if((v[j]+r[j])/(1-r[j])<z)z=(v[j]+r[j])/(1-r[j]),k=j;
			u[k]=1;v[k]=(v[k]+r[k])/(1-r[k]);
			if(k==1)return 0*printf("%.10lf",v[1]);
		}
		else k=n;
		for(j=1;j<n;++j)if(!u[j])v[j]+=r[j]*p[j][k]*(1+v[k]),r[j]-=r[j]*p[j][k];
	}
	printf("%.10lf",v[1]);
}