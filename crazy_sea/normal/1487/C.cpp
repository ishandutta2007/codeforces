#include<cstdio>
using namespace std;
int n,T;
int dis(int y,int x)
{
	if(n-(x-y)<x-y) return n-(x-y);
	else return x-y;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(n%2==0&&dis(i,j)==n/2) printf("0 ");
				else printf("%d ",dis(i,j)==j-i?1:-1);
		printf("\n");
	}
}