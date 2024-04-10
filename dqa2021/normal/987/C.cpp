#include<cstdio>
#include<algorithm>
using namespace std;
int n,s[3010],c[3010];
int ans=0x7fffffff,subans;
int main()
{
	int tmp;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",s+i);
	for (int i=1;i<=n;i++) scanf("%d",c+i);
	for (int i=2;i<n;i++)
	{
		tmp=0x7fffffff;
		for (int j=1;j<i;j++)
			if (s[j]<s[i])
				tmp=min(tmp,c[j]);
		if (tmp==0x7fffffff) continue;
		subans=tmp+c[i];
		tmp=0x7fffffff;
		for (int j=i+1;j<=n;j++)
			if (s[j]>s[i])
				tmp=min(tmp,c[j]);
		if (tmp==0x7fffffff) continue;
		subans+=tmp;
		ans=min(ans,subans);
	}
	printf("%d\n",ans==0x7fffffff?-1:ans);
	return 0;
}