#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,l,vis[1000005],j;
long long a[1000005],b[1000005];
bool flag;
struct str{
	int i,l;
}f[1000005];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
	}
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&b[i]);
		b[i]+=b[i-1];
	}
	if(a[n]<b[n])
	{
		for(i=1;i<=n;++i)
			swap(a[i],b[i]);
		flag=1;
	}
	l=0;
	for(i=0;i<=n;++i)
	{
		while(l<n&&b[l+1]<=a[i])
			++l;
		if(vis[a[i]-b[l]])
		{
			if(flag)
			{
				printf("%d\n",l-f[a[i]-b[l]].l);
				for(j=f[a[i]-b[l]].l+1;j<=l;++j)
					printf("%d ",j);
				printf("\n");
				printf("%d\n",i-f[a[i]-b[l]].i);
				for(j=f[a[i]-b[l]].i+1;j<=i;++j)
					printf("%d ",j);
				printf("\n");
			}
			else
			{
				printf("%d\n",i-f[a[i]-b[l]].i);
				for(j=f[a[i]-b[l]].i+1;j<=i;++j)
					printf("%d ",j);
				printf("\n");
				printf("%d\n",l-f[a[i]-b[l]].l);
				for(j=f[a[i]-b[l]].l+1;j<=l;++j)
					printf("%d ",j);
				printf("\n");
			}
			return 0;
		}
		vis[a[i]-b[l]]=1;
		f[a[i]-b[l]].l=l;
		f[a[i]-b[l]].i=i;
	}
}