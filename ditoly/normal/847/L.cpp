#include<cstdio>
#define MN 1000
int f[MN+5][MN+5],z[MN+5][MN+5],p[MN+5],x[MN+5],y[MN+5],u[MN+5];
char s[MN*100+5];
int read(int&x)
{
	int res=0;
	for(;s[x]>='0'&&s[x]<='9';++x)res=res*10+s[x]-'0';++x;
	return res;
}
int main()
{
	int n,i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%s",s);
		for(j=k=0;k<n-1;)
		{
			k+=z[i][++p[i]]=read(j);
			for(l=0;l<z[i][p[i]];++l)f[i][read(j)]=p[i];
		}
	}
	for(l=1;l<n;++l)
	{
		for(i=1;i<=n;++i)if(!u[i]&&p[i]==1)break;
		if(i>n)return 0*puts("-1");
		for(j=1;j<=n;++j)if(!u[j]&&z[j][f[j][i]]==1)break;
		if(j>n)return 0*puts("-1");
		for(k=1;k<=n;++k)if(!u[k]&&k!=i&&k!=j)
		{
			if(f[k][i]!=f[k][j])return 0*puts("-1");
			--z[k][f[k][i]];
		}
		x[l]=i;y[l]=j;--p[j];u[i]=1;
	}
	printf("%d\n",n-1);
	for(i=1;i<n;++i)printf("%d %d\n",x[i],y[i]);
}