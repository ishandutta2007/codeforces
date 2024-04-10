#include<cstdio>
#include<algorithm>
using namespace std;
int n,tot=0,seq[100005];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
	int x,y;
	scanf("%d",&n);
	if(n==2)
	{
		printf("1\n1\n");
		return 0;
	}
	if(n==4)
	{
		printf("1\n1\n");
		return 0;
	}
	/*if(n%2==0)
	{
		printf("%d\n",n/2);
		for(int i=1;i<n-2;i+=2)printf("%d ",i);
		printf("%d\n",n-1);
		return 0;
	}*/
	int ans=1;
	for(int i=1;i<n;i++)
	{
		int tmp=gcd(i,n);
		if(tmp==1)
		{
			ans=1ll*ans*i%n;
				seq[++tot]=i;
		}
	}
	if(ans!=1)tot--;
	printf("%d\n",tot);
	for(int i=1;i<tot;i++)printf("%d ",seq[i]);
	printf("%d\n",seq[tot]);
	return 0;
}