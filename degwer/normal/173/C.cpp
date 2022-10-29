#include<stdio.h>
int map[502][502];
int rui[502][502];
int main()
{
	int mx,my;
	scanf("%d%d",&mx,&my);
	for(int k=0;k<mx;k++)
	{
		for(int l=0;l<my;l++)
		{
			scanf("%d",&map[k+1][l+1]);
		}
	}
	for(int m=0;m<502;m++)
	{
		rui[m][0]=0;
		rui[0][m]=0;
	}
	for(int n=0;n<=mx;n++)
	{
		for(int o=0;o<=my;o++)
		{
			rui[n][o]=rui[n-1][o]+rui[n][o-1]-rui[n-1][o-1]+map[n][o];
		}
	}
	int max=-100000000;
	for(int p=1;p<=mx;p++)
	{
		for(int q=1;q<=my;q++)
		{
			int sum=map[p][q];
			for(int r=1;;r++)
			{
				if(p-r<1||q-r<1||p+r>mx||q+r>my)
				{
					break;
				}
				int squ=rui[p+r][q+r]+rui[p-r-1][q-r-1]-rui[p+r][q-r-1]-rui[p-r-1][q+r];
				sum=squ-sum-map[p-r+1][q-r];
				if(max<sum)
				{
					max=sum;
				}
			}
		}
	}
	printf("%d\n",max);
}