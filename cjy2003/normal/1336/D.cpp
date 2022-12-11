#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,t[110],s[110],a[110];
int main()
{
	scanf("%d",&n);
	scanf("%d %d",&t[0],&s[0]);
	printf("+ %d\n",2);fflush(stdout);
	scanf("%d %d",&t[1],&s[1]);
	printf("+ %d\n",1);fflush(stdout);
	scanf("%d %d",&t[2],&s[2]);
	printf("+ %d\n",3);fflush(stdout);
	scanf("%d %d",&t[3],&s[3]);
	printf("+ %d\n",1);fflush(stdout);
	scanf("%d %d",&t[4],&s[4]);
	for(int i=5;i<=n;++i)
	{
		printf("+ %d\n",i-1);fflush(stdout);
		scanf("%d %d",&t[i],&s[i]);
	}
	for(int j=2;j<=n+1;++j)if(j*(j-1)/2==t[4]-t[3]){a[1]=j-1;break;}
	a[2]=s[4]-s[3]-(s[2]-s[1])-1;
	a[3]=(s[2]-s[1])/(a[2]+1);
	if(n==4)
	{
		a[4]=(s[3]-s[2]-(a[1]+1)*(a[2]+1))/(a[2]+1);
	}
	else
	{
		if(t[5]-t[4])
		{
			for(int j=2;j<=n;++j)if(j*(j-1)/2==t[5]-t[4]){a[4]=j;break;}
		}
		else
		{
			if(s[3]-s[2]-(a[1]+1)*(a[2]+1))a[4]=1;
			else a[4]=0;
		}
		for(int i=5;i<n;++i)
		{
			if(t[i+1]-t[i])
			{
				for(int j=2;j<=n;++j)if(j*(j-1)/2==t[i+1]-t[i]){a[i]=j;break;}
			}
			else
			{
				if(s[i]-s[i-1]-(a[i-3]+1)*(a[i-2]+1))a[i]=1;
				else a[i]=0;
			}
		}
	//	printf("%d %d\n",s[n],s[n-1]);
		a[n]=(s[n]-s[n-1]-(a[n-3]+1)*(a[n-2]+1))/(a[n-2]+1);
	}
	printf("! ");
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	fflush(stdout);
	return 0;
}