#include<bits/stdc++.h>
using namespace std;

int n,t,a[1020],b[1020];
pair<int,int> p1[1020],p2[1020];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int t1=0,t2=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i*2>n) p1[++t1]=make_pair(min(a[i],a[n+1-i]),max(a[i],a[n+1-i]));
		}
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&b[i]);
			if(i*2>n) p2[++t2]=make_pair(min(b[i],b[n+1-i]),max(b[i],b[n+1-i]));
		}
		int bl=1;
		if(n%2==1) if(a[n/2+1]!=b[n/2+1]) bl=0;
		sort(p1+1,p1+t1+1);
		sort(p2+1,p2+t2+1);
		for(int i=1;i<=t1;i++) if(p1[i].first!=p2[i].first||p1[i].second!=p2[i].second) bl=0;
		if(bl) puts("Yes");
		else puts("No");
	}
	return 0;
}