#include<bits/stdc++.h>
using namespace std;
bool a[300003],b[300003];
int t[500003];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int x;
		bool f=1;
		scanf("%d",&x);
		for(int i=1; i<=x; i++) scanf("%d",&t[i]);
		for(int i=1; i<=x; i++) 
		{
			if(t[i]<i-1) break;
			a[i]=1;
		}
		for(int i=x; i>=1; i--)
		{
			if(t[i]<x-i) break;
			b[i]=1;
		}
		for(int i=1; i<=x; i++) if(a[i]&&b[i]) 
		{
			f=0; break;
		}
		if(f) printf("No\n"); else printf("Yes\n");
	}
	return 0;
}