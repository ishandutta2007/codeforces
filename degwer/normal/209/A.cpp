#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int ruio[1000001],ruie[1000001];
int mod=1000000007;
int main()
{
	int num;
	scanf("%d",&num);
	ruio[1]=1;
	int ret=0;
	for(int i=2;i<=num;i++)
	{
		if(i%2==1)
		{
			ruie[i]=ruie[i-1];
			ruio[i]=ruie[i]+ruio[i-1];
			ruio[i]%=mod;
		}
		else
		{
			ruio[i]=ruio[i-1];
			ruie[i]=ruio[i]+ruie[i-1];
			ruie[i]%=mod;
		}
		ret+=ruio[i];
		ret%=mod;
		ret+=ruie[i];
		ret%=mod;
	}
	ret++;
	printf("%d\n",ret);
}