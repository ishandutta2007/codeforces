#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int pre=0,sum=0,ans=1,n,k;
	scanf("%d%d",&n,&k);
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		if(x==pre)
		{
			sum=1;
		}
		else sum++;
		ans=max(ans,sum);
		pre=x;
	}
	printf("%d\n",ans);
	return 0;
}