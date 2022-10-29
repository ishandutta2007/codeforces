#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
typedef long long ll;
ll map[1000][1000];
ll haix[1000];
ll haiy[1000];
int main()
{
	int mx,my;
	scanf("%d%d",&mx,&my);
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			scanf("%I64d",&map[i][j]);
			haix[i]+=map[i][j];
			haiy[j]+=map[i][j];
		}
	}
	int gx,gy;
	ll minix=2000000000000000000LL,miniy=2000000000000000000LL;
	for(int i=0;i<=mx;i++)
	{
		ll rx=0;
		for(int j=0;j<mx;j++)
		{
			rx+=abs(j*4+2-i*4)*abs(j*4+2-i*4)*haix[j];
		}
		if(minix>rx)
		{
			minix=rx;
			gx=i;
		}
	}
	for(int i=0;i<=my;i++)
	{
		ll ry=0;
		for(int j=0;j<my;j++)
		{
			ry+=abs(j*4+2-i*4)*abs(j*4+2-i*4)*haiy[j];
		}
		if(miniy>ry)
		{
			miniy=ry;
			gy=i;
		}
	}
	printf("%I64d\n",minix+miniy);
	printf("%d %d\n",gx,gy);
}