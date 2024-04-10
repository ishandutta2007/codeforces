#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,a[100];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int cnt=0;
		for(int i=1;i<=n;++i)cnt+=a[i]!=i;
		if(cnt==0)printf("0\n");
		else if(a[1]==1||a[n]==n)printf("1\n");
		else if(a[1]==n&&a[n]==1)printf("3\n");
		else printf("2\n");
	}
	return 0;
}