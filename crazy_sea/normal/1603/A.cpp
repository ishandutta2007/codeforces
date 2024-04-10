#include<cstdio>
#define N 1000010
using namespace std;
int p,T,n,a[N];
bool check()
{
	for(int i=1;i<=n;i++)
	{
		p=0;
		for(int j=0;j<i&&p==0;j++)
			if(a[i]%(i-j+1)!=0) p=1;
		if(!p) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("%s\n",check()?"YES":"NO");
	}
}