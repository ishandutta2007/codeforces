#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[110],b[110],ans;
char s[110];
int cnt[10010];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)scanf("%d %d",&a[i],&b[i]);
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='1')
		{
			for(int j=1;j<=b[i];++j)++cnt[j];
			for(int j=b[i]+a[i];j<=1000;j+=2*a[i])
				for(int k=1;k<=a[i];++k)++cnt[j+k];
		}
		else
		{
			for(int j=b[i];j<=1000;j+=2*a[i])
				for(int k=1;k<=a[i];++k)++cnt[j+k];
		}
	}
	for(int i=1;i<=1000;++i)ans=max(ans,cnt[i]);
	printf("%d",ans);
	return 0;
}