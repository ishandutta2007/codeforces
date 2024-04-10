#include<bits/stdc++.h>
#define N 1000
#define Gmax(x,y) (x<(y)&&(x=(y)))
using namespace std;
int n;
int main()
{
	register int i,x,y,Size=0,now=0,ans=0;
	for(scanf("%d",&n),i=1;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		if(now+Size<=x) Size=0;else Size-=x-now;
		now=x,Size+=y,Gmax(ans,Size);
	}
	return printf("%d %d",now+Size,ans),0;
}