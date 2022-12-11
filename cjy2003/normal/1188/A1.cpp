#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,d[100010];
int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		++d[x],++d[y];
	}
	for(int i=1;i<=n;++i)
		if(d[i]==2)
		{
			printf("NO");
			return 0;
		}
	printf("YES");
	return 0;
}