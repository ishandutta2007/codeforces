#include<cstdio>
#include<algorithm>
using namespace std;

int n,w[200010];
int A,B;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		 scanf("%d",w+i);
		 if (w[i]) B=i;
		 else A=i;
	}
	printf("%d\n",min(A,B));
	return 0;
}