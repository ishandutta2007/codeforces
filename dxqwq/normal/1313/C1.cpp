#include<bits/stdc++.h>
using namespace std;
int a[500003],ans;
long long MaX=-1;
int main()
{
	int n;
	long long x;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=n; i++) 
	{
		long long now=a[i];
		x=a[i];
		for(int j=i-1; j>=1; j--) if(a[j]<now) now=a[j],x+=now; else x+=now;
		now=a[i];
		for(int j=i+1; j<=n; j++) if(a[j]<now) now=a[j],x+=now; else x+=now;
		if(x>MaX) MaX=x,ans=i;
	}
	for(int i=ans-1; i>=1; i--) if(a[i]>a[i+1]) a[i]=a[i+1];
	for(int i=ans+1; i<=n; i++) if(a[i]>a[i-1]) a[i]=a[i-1];
	for(int i=1; i<=n; i++) printf("%d ",a[i]);
	return 0;
}