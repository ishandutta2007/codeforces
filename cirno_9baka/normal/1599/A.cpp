#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=1000005;
int n,a[N],i,j,f[N],o[N];
char c[N];
bool cmp(int a,int b)
{
	return a>b;
}
char x(int f)
{
	return f?'R':'L';
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	scanf("%s",c+1);
	for(i=1;i<=n;++i)
		if(c[i]=='L')
			f[i]=-1;
		else
			f[i]=1;
	int u=f[n];
	for(i=n;i>=1;--i)
	{
		a[i]*=u;
		u*=-1;
	}
	int al=1,ar=n,v=n-1;
	for(i=n-1;i>=1;--i)
		if(1ll*f[i]*a[ar]>0)
			o[i+1]=a[al++];
		else
			o[i+1]=a[ar--];
	o[1]=a[al];
	for(i=1;i<=n;++i)
		printf("%d %c\n",abs(o[i]),x(o[i]>0));
}