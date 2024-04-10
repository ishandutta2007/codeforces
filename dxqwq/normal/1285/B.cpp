#include<bits/stdc++.h>
using namespace std;
long long a[100003];
int main()
{
	int t,n;
	long long pre,tot;
	bool f,ff;
	scanf("%d",&t);
	while(t--)
	{ 
		tot=0;
		pre=0;
		f=ff=1;
		scanf("%d",&n);
		for(int i=1; i<=n; i++) scanf("%I64d",&a[i]),tot+=a[i];
		for(int i=1; i<n; i++) 
		{
			pre+=a[i];
			if(pre<0) pre=0;
			if(pre>=tot) 
			{
				printf("NO\n"),ff=0;
				break;
			} 
		}
		pre=0;
		if(ff)for(int i=2; i<=n; i++) 
		{
			pre+=a[i];
			if(pre<0) pre=0;
			if(pre>=tot) 
			{
				printf("NO\n"),ff=0;
				break;
			} 
		}
		if(ff) printf("YES\n");
	}
	return 0;
}