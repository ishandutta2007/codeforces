#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i;
bool check(int x,int y)
{
	x-=y*m;
	if(x<y) return 0;
	int s=0;
	while(x)
	{
		if(x&1) s++;
		x/=2;
	}
	return s<=y;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<=1000;i++)
	{
		if(check(n,i))
		{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}