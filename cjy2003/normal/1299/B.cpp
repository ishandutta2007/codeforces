#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x[100010],y[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d %d",&x[i],&y[i]);
	if(n%2)return printf("NO"),0;
	int sx=x[1]+x[n/2+1],sy=y[1]+y[n/2+1];
	for(int i=2;i<=n/2;++i)
		if(x[i]+x[i+n/2]!=sx||y[i]+y[i+n/2]!=sy)return printf("NO"),0;
	printf("YES");
	return 0;
}