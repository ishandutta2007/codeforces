#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m,k;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&m,&k);
		if(n&1)
		{
			if(k<m/2||(k-m/2)&1)printf("NO\n");
			else
			{
				printf("YES\n");

			}
		}
		else if(m&1)
		{
			if(n*m/2-k<n/2||k&1)printf("NO\n");
			else
			{
				printf("YES\n");
			}
		}
		else
		{
			if(k&1)printf("NO\n");
			else
			{
				printf("YES\n");
			}
		}
	}
	return 0;
}