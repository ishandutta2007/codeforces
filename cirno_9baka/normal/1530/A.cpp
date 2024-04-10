#include<bits/stdc++.h>
using namespace std;
const int M=998244353,L=5000,N=1000005;
int n,i,t;
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
		int ans=0;
		while(n)
		{
			ans=max(ans,n%10);
			n/=10;
		}
		printf("%d\n",ans);
	}
}