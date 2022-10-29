#include<stdio.h>
int main()
{
	int num,fir;
	scanf("%d%d",&num,&fir);
	bool han=true;
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		if(za==zb||za+zb==7||za==fir||zb==fir||za==7-fir||zb==7-fir)
		{
			han=false;
		}
	}
	if(han)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}