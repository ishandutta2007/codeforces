#include<bits/stdc++.h>
using namespace std;
#define MN 100
#define MM 100000
long long a[MN+5];int b[MN+5];
int main()
{
	int n,m,i,j,k;
	long long a1=0,a2=0,a3=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(i=2;i<=2*m;++i)
	{
		for(j=1;j<=n;++j)b[j]=a[j]%i;
		sort(b+1,b+n+1);b[n+1]=m;
		if(~i&1)
		{
			for(j=1,k=0;j<=n;++j)if(b[j]>=i/2)++k;
			if(k&1)++a2;else ++a3;
		}
		for(j=1;j<=n+1;++j)
		{
			int l=max(i/2+1,b[j-1]+1),r=min(min(m,i-1),b[j]);
			if(l>r)continue;
			k=i-max(b[j-1],b[n-1]/2);
			if(r>=k)a1+=r-max(k,l)+1,r=k-1;
			if(l>r)continue;
			if((n+1-j)&1)a2+=r-l+1<<1;
			else
			{
				k=i-b[n]/2;
				if(r>=k)a1+=r-max(k,l)+1,r=k-1;
				if(l<=r)a3+=r-l+1<<1;
			}
		}
	}
	printf("%lld %lld %lld %lld",a1,a1,a2,a3);
}