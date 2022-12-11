#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[510][510],b[510][510];
bool ans;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&b[i][j]);
	for(int i=1;i<n;++i)
	{
		int sum=0;
		for(int j=1;j<=m;++j)
			if(a[i][j]!=b[i][j])
			{
				++sum;
				a[i+1][j]^=1;
			}
		if(sum&1)
		{
			printf("No");
			return 0;
		}
	}
	for(int j=1;j<=m;++j)
		if(a[n][j]!=b[n][j])
		{
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}