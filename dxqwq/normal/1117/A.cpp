#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,maxa=-1,now,ans=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) 
	{
		scanf("%d",&a);
		if(a>maxa) 
		{
			maxa=a;
			now=0;
			ans=1;
		}
		if(a==maxa) now++;
		else now=0;
		if(now>ans) ans=now;
	}
	printf("%d",ans);
	return 0;
}