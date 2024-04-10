#include<bits/stdc++.h>  
using namespace std;
typedef long long ll;
#define ri register int
const int M=1000000007;
int n,t,i,j,a[55][55];
bool flag=false;
int Ask(int a,int b,int c,int d)
{
	printf("? %d %d %d %d\n",a,b,c,d);
	fflush(stdout);
	int i;
	scanf("%d",&i);
	return i;
}
int main()
{
	scanf("%d",&n);
	a[1][1]=1;
	for(i=1;i<=n;i++)
	{
		if(i%2==1)
			j=1;
		else
			j=2;
		for(;j+2<=n;j+=2)
		{
			if(Ask(i,j,i,j+2)==1)
				a[i][j+2]=a[i][j];
			else
				a[i][j+2]=a[i][j]^1;
		}
		if(i%2==1&&i!=n)
		{
			if(Ask(i,1,i+2,1))
				a[i+2][1]=a[i][1];
			else
				a[i+2][1]=a[i][1]^1;
			if(Ask(i,1,i+1,2))
				a[i+1][2]=a[i][1];
			else
				a[i+1][2]=a[i][1]^1;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(i%2==1)
			j=2;
		else
			j=1;
		for(;j+2<=n;j+=2)
		{
			if(Ask(i,j,i,j+2)==1)
				a[i][j+2]=a[i][j];
			else
				a[i][j+2]=a[i][j]^1;
		}
		if(i+2<=n)
		{
		if(i%2==1)
		{
			if(Ask(i,2,i+2,2))
				a[i+2][2]=a[i][2];
			else
				a[i+2][2]=a[i][2]^1;
		}
		else
			if(Ask(i,1,i+2,1))
				a[i+2][1]=a[i][1];
			else
				a[i+2][1]=a[i][1]^1;
		}
	}
	if(Ask(1,2,2,3)==a[2][3])
		for(i=2;i<=n;i+=2)
			for(j=1;j<=n;j+=2)
				a[i][j]^=1;
	for(i=1;i+2<=n;i++)
		for(j=1;j+2<=n;j++)
			if((i+j)%2==0)
				if(a[i][j]==1&&a[i+2][j+2]==0)
				{
					if(a[i+1][j+1]!=a[i][j+2])
					{
						if(Ask(i,j,i+1,j+2)!=a[i+1][j+2])
							flag=true;
					}
					else
					{
						if(a[i][j+2]==1)
						{
							if(a[i][j+1]==a[i+1][j+2])
							{
								if(Ask(i,j,i+1,j+2)!=a[i+1][j+2])
									flag=true;
							}
							else
								if(Ask(i+1,j,i+2,j+2)==a[i][j+1])
									flag=true;
						}
						else
						{
							if(a[i][j+1]!=a[i+1][j+2])
							{
								if(Ask(i,j,i+1,j+2)!=a[i+1][j+2])
									flag=true;
							}
							else
								if(Ask(i+1,j,i+2,j+2)==a[i][j+1])
									flag=true;
						}
					}
					if(flag)
						for(i=1;i<=n;i++)
							for(j=1;j<=n;j++)
								if((i+j)%2==1)
									a[i][j]^=1;
					printf("!\n");
					for(i=1;i<=n;i++)
					{
						for(j=1;j<=n;j++)
							printf("%d",a[i][j]);
						printf("\n");
					}
					return 0;
				}
}