#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=100010;

int t,a[N],n; 

int main()
{
	cin>>t;
	while(t--)
	{
		int bl1=1,bl2=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		if(n==1)
		{
			puts("YES");
			continue;
		}
		int d=1;
		for(int i=1;i<n;i++)
		{
			int x=a[i]+d;
			if(x==n+1) x=1;
			if(x==0) x=n;
			if(x!=a[i+1]) bl1=0;
		}
		d=-1;
		for(int i=2;i<n;i++)
		{
			int x=a[i]+d;
			if(x==n+1) x=1;
			if(x==0) x=n;
			if(x!=a[i+1]) bl2=0;
		}
		if(!bl1&&!bl2) puts("NO");
		else puts("YES");
	}
	return 0;
}