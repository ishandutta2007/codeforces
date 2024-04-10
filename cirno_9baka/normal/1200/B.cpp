#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2520;
int n,m,k,t,i,h[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&k);
		for(i=1;i<=n;i++)
			scanf("%d",&h[i]);
		for(i=1;i<n;i++)
		{
			if(h[i]+m<h[i+1]-k)
				break;
			m+=min(h[i]-h[i+1]+k,h[i]);
		}
		if(i==n)
			printf("YES\n");
		else
			printf("NO\n");
	}
}