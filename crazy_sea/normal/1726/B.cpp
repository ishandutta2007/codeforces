#include<cstdio>
using namespace std;
int T,n,m;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		if(n>m) {printf("No\n");continue;}
		if(n==m)
		{
			printf("Yes\n");
			for(int i=1;i<=n;i++) printf("1%c"," \n"[i==n]);
		}
		else if(n%2==0)
		{
			if(m%2==0)
			{
				printf("Yes\n");
				for(int i=1;i<=n-2;i++) printf("1 ");
				printf("%d %d\n",(m-n+2)/2,(m-n+2)/2);
			}
			else printf("No\n");
		}
		else
		{
			printf("Yes\n");
			for(int i=1;i<n;i++) printf("1 ");
			printf("%d\n",m-n+1);
		}
	}
}