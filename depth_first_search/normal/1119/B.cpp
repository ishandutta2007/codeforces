#include<cstdio>
#include<algorithm>
#define RI register int
#define CI const int&
using namespace std;
const int N=1005;
int n,h,a[N],b[N],ans;
int main()
{
	RI i,j; for (scanf("%d%d",&n,&h),i=1;i<=n;++i)
	scanf("%d",&a[i]); for (i=1;i<=n;++i)
	{
		for (j=1;j<=i;++j) b[j]=a[j]; sort(b+1,b+i+1);
		int cur=0; for (j=i;j>1;j-=2) cur+=b[j];
		if (i&1) cur+=b[1]; if (cur<=h) ans=i; else break;
	}
	return printf("%d",ans),0;
}