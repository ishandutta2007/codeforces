#include<cstdio>
#define MN 100000
int x[MN+5],y[MN+5];double p[MN+5];
inline int z(int x){return x<0?-x:x;}
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
inline int cal(int a,int b)
{
	if(x[a]==x[b])return z(y[a]-y[b]);
	if(y[a]==y[b])return z(x[a]-x[b]);
	return gcd(z(x[a]-x[b]),z(y[a]-y[b]));
}
int main()
{
	int n,i,j;double ans=0;
	scanf("%d",&n);
	for(i=0;i<n;++i)scanf("%d%d",&x[i],&y[i]);
	for(p[0]=i=1;i<=n;++i)p[i]=p[i-1]+p[i-1];
	for(i=0;i<n;++i)for(j=1;j<=60&&j<n;++j)
	{
		long long s=1LL*x[i]*y[(i+j)%n]-1LL*y[i]*x[(i+j)%n]-cal(i,(i+j)%n);
		ans+=n<60?s*(p[n-j-1]-1)/(p[n]-1-n-1LL*n*(n-1)/2):s/p[j+1];
	}
	printf("%.10lf",ans/2+1);
}