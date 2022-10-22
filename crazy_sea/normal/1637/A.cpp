#include<cstdio>
#include<algorithm>
#define N 100010
using namespace std;
int a[N],s1[N],s2[N],n,T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		s2[n+1]=0x3f3f3f3f;
		for(int i=1;i<=n;i++) s1[i]=max(s1[i-1],a[i]);
		for(int i=n;i;i--) s2[i]=min(s2[i+1],a[i]);
		int p=0;
		for(int i=2;p==0&&i<=n;i++) if(s1[i-1]>s2[i]) p=1;
		printf("%s\n",p?"YES":"NO");
	}
}