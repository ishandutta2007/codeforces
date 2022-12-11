#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,cnt,m;
int p[100010],s[1000010];
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int mi=100000000,mx=0,len,x,flag=0;
		scanf("%d",&len);
		for(int j=1;j<=len;++j)
		{
			scanf("%d",&x);
			if(x>mi)flag=1;
			mi=min(mi,x),mx=max(mx,x);
		}
		if(flag)++cnt,ans+=2*(n-cnt)+1;
		else p[++m]=mx,++s[mi];
	}
	for(int i=1;i<=1000000;++i)s[i]+=s[i-1];
	for(int i=1;i<=m;++i)ans+=s[p[i]-1];
	printf("%lld\n",ans);
	return 0;
}