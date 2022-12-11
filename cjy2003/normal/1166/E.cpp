#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
int m,n,cnt;
bitset<10001>b[51];
int main()
{
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;++i)
	{
		int x;
		scanf("%d",&cnt);
		for(int j=1;j<=cnt;++j)
		{
			scanf("%d",&x);
			b[i].set(x);
		}
	}
	for(int i=1;i<=m;++i)
		for(int j=i+1;j<=m;++j)
			if(!(b[i]&b[j]).count())
			{
				printf("impossible");
				return 0;
			}
	printf("possible");
	return 0;
}