#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 2000
int x[MN+5],y[MN+5];
double f[MN+5][MN+5];
int main()
{
	int n,m,a=0,b=0,i,j;
	n=read();m=read();
	while(m--)x[read()]++?0:++a,y[read()]++?0:++b;
	for(i=n;i>=0;--i)for(j=n;j>=0;--j)if(i<n||j<n)
		f[i][j]=(1+(double)(n-i)/n*j/n*f[i+1][j]+
				   (double)i/n*(n-j)/n*f[i][j+1]+
				   (double)(n-i)/n*(n-j)/n*f[i+1][j+1])/(1-(double)i/n*j/n);
	printf("%.10lf",f[a][b]);
}