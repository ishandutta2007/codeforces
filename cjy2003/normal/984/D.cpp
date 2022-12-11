#include<stdio.h>
#include<string.h>
int n,q,s[5001][5001],x,y;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[1][i]);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			s[i][j]=s[i-1][j+1]^s[i-1][j];
		//	printf("%d ",s[i][j]);
		}
	//	printf("\n");
				
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
		{
			if(s[i-1][j]>s[i][j])s[i][j]=s[i-1][j];
			if(s[i-1][j+1]>s[i][j])s[i][j]=s[i-1][j+1];
		}	
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",s[y-x+1][x]);	
	}
	return 0;
}