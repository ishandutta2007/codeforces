#include<cstdio>
int main()
{
	int x,y[3],i;
	scanf("%d %d",&x,&y[2]);
	y[0]=y[1]=y[2];
	for(i=0;y[0]<x||y[1]<x||y[2]<x;i++)
	{
		y[i%3]=y[(i+1)%3]+y[(i+2)%3]-1;
		if(y[i%3]>x)y[i%3]=x;
	}
	printf("%d",i);
}