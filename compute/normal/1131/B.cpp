#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
int main()
{
	int n;
	int cx=0,cy=0;
	scanf("%d",&n);
	long long ans=1;
	for(int i=0,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		if(cx==cy)
		{
			ans+=min(x,y)-cx;
		}
		else if(cx<cy)
		{
			if(x>=cy)
			{
				ans+=1;
				ans+=min(x,y)-cy;
			}
		}
		else{
			if(y>=cx)
			{
				ans+=1;
				ans+=min(x,y)-cx;
			}
		}
		cx=x,cy=y;
	}
	printf("%lld\n",ans);
}