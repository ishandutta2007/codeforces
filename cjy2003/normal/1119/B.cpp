#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,h,a[1010],b[1010];
bool ok(int p)
{
	for(int i=1;i<=p;++i)
		b[i]=a[i];
	sort(b+1,b+1+p);
	int s=0;
	for(int i=p;i>=1;i-=2)
		s+=b[i];
	return s<=h;
}
int main()
{
	scanf("%d %d",&n,&h);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		if(!ok(i))
		{
			printf("%d",i-1);
			return 0;
		}
	printf("%d",n);
	return 0;
}