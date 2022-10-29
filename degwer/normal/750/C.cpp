#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	int now=0,lb=-1000000000,ub=1000000000;
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		if(zb==1)lb=max(lb,1900-now);
		else ub=min(ub,1899-now);
		now+=za;
	}
	if(ub<lb)printf("Impossible\n");
	else if(ub==1000000000)printf("Infinity\n");
	else printf("%d\n",ub+now);
}