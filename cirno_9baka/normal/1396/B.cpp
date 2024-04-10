#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=998244353;
int n,i,t;
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int s=0,mx=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
			s+=a[i];
		}
		if(mx*2<=s)
			puts(s&1?"T":"HL");
		else
			puts("T");
	}
}