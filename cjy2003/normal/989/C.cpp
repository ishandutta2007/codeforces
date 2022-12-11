#include<stdio.h>
#include<string.h>
int a[6],map[51][51];
int x,b,c,d,e;
int flag,flag1;
int main()
{	
	scanf("%d %d %d %d",&a[1],&a[2],&a[3],&a[4]);
	x=0;
	a[1]--;
	a[2]--;
	a[3]--;
	a[4]--;
	a[5]=a[1];
	for(int k=1;k<=4;k++)
	{
		x++;
		for(int i=1;i<=49;i++)
			map[x][i]=k;
		b=(a[k+1]+24)/25;
		for(int i=x+1;i<=x+2*b;i+=2)
			for(int j=1;j<=49;j++)
			{
				map[i+1][j]=k;
				if(a[k+1]>0&&(j&1))map[i][j]=k+1,a[k+1]--;
				else map[i][j]=k;
			}
		x=x+2*b;			
	}	
	printf("%d %d\n",x,49);
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=49;j++)
		{
			if(map[i][j]%4==1)printf("A");
			else if(map[i][j]==2)printf("B");
			else if(map[i][j]==3)printf("C");
			else if(map[i][j]==4)printf("D");	
		}
		printf("\n");	
	}
	return 0;
}