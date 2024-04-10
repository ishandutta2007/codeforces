#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[30][20],b[30][20];
int n,m,q;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i)scanf("%s",a[i]);
	for(int i=0;i<m;++i)scanf("%s",b[i]);
	scanf("%d",&q);
	int x;
	while(q--)
	{
		scanf("%d",&x);--x;
		printf("%s%s\n",a[x%n],b[x%m]);
	}
	return 0;
}