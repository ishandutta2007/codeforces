#include<bits/stdc++.h>
#define MaxN 5123
long double f[MaxN],g[MaxN];
int a[MaxN];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d",a+i);
	
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	if(a[i]>a[j])f[a[i]-a[j]]+=1.;
	
	long double coef=2./n/(n-1);
	for(int i=1;i<=5000;++i)f[i]*=coef;
	
	for(int i=1;i<=5000;++i)
	for(int j=1;j<i;++j)
	g[i]+=f[j]*f[i-j];
	
	for(int i=1;i<=5000;++i)g[i]+=g[i-1];
	
	long double ans=0;
	for(int i=1;i<=5000;++i)
	ans+=f[i]*g[i-1];
	
	std::cout<<std::setprecision(15)<<ans<<std::endl;
	return 0;
}