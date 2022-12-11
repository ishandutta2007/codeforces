#include<stdio.h>
#include<string.h>
char dc[301][100001],a[100001];
int n,w,m,maxi,sum,flag,z,s[301];
bool check(int x1,int y1,int x2,int y2)
{
	for(int i=0;i<=y1-x1;i++)
		if(strcmp(dc[x1+i],dc[x2+i])!=0)return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf(" %s",dc[i]);
		z+=strlen(dc[i]);
		s[i]=s[i-1]+strlen(dc[i]);
	}
	z+=n-1;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			sum=s[j]-s[i-1]-1;
			flag=0;
			for(int k=j+1;k<=n-j+i;k++)
				if(check(i,j,k,k+j-i))
				{
					flag=1;
					sum+=s[j]-s[i-1]-1;
					k=k+j-i;	
				}
			if(sum>maxi&&flag)maxi=sum;
		}
	printf("%d",z-maxi);
	return 0;
}