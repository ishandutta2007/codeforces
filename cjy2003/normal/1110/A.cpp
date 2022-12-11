#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int b,k,a[100010];
bool flag;
int main()
{
	scanf("%d %d",&b,&k);
	for(int i=1;i<=k;++i)
		scanf("%d",&a[i]);
	if(b&1)
	{
		for(int i=1;i<=k;++i)
			flag^=a[i]&1;
	}
	else flag=a[k]&1;
	if(flag)printf("odd");
	else printf("even");
	return 0;
}