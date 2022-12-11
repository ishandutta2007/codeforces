#include<cstdio>
int pw(int x,int y,int mod)
{
	int r=1;
	for(;y;y>>=1,x=1LL*x*x%mod)if(y&1)r=1LL*r*x%mod;
	return r;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	if(n==4)return 0*puts("YES\n1\n3\n2\n4");
	for(i=2;i*i<=n;++i)if(n%i==0)return 0*puts("NO");
	puts("YES\n1");if(n==1)return 0;
	for(i=2;i<n;++i)printf("%d\n",1LL*i*pw(i-1,n-2,n)%n);
	printf("%d",n);
}