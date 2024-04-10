#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n,m;
		scanf("%lld%lld",&n,&m);
		long long x1,x2,y1,y2;
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		long long black=n*m/2,white=black;
		if(n*m%2==1) white++;
		long long x3,x4,y3,y4;
		scanf("%lld%lld%lld%lld",&x3,&y3,&x4,&y4);
		black-=(x2-x1+1)*(y2-y1+1)/2;
		white+=(x2-x1+1)*(y2-y1+1)/2;
		if((x2-x1+1)%2==1&&(y2-y1+1)%2==1&&(x1+y1)%2==1&&(x2+y2)%2==1) white++,black--;
		long long xc1=max(x1,x3),yc1=max(y1,y3),xc2=min(x2,x4),yc2=min(y2,y4);
		if(xc1<=xc2&&yc1<=yc2)
		{
			white-=(xc2-xc1+1)*(yc2-yc1+1)/2;
			if((xc2-xc1+1)%2==1&&(yc2-yc1+1)%2==1&&(xc1+yc1)%2==1) black++,white--;
			black+=(xc2-xc1+1)*(yc2-yc1+1)/2;
		}
		black+=(x4-x3+1)*(y4-y3+1)/2;
		white-=(x4-x3+1)*(y4-y3+1)/2;
		if((x4-x3+1)%2==1&&(y4-y3+1)%2==1&&(x3+y3)%2==0) black++,white--;
		printf("%lld %lld\n",white,black);
	}
}