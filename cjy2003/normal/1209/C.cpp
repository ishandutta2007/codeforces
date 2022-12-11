#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n;
char s[200020];
int ans[200020];
bool check(int x)
{
	memset(ans+1,0,n<<2);
	int last=0,p=0,cnt=0;
	for(int i=1;i<=n;++i)
		if(s[i]<x)
		{
			if(s[i]<last)return 0;
			last=s[i];p=i;
			ans[i]=1;++cnt;
		}
	for(int i=p+1;i<=n;++i)
		if(s[i]==x)ans[i]=1,++cnt;
	last=0,p=n+1;
	for(int i=1;i<=n;++i)
		if(s[i]>x)
		{
			if(s[i]<last)return 0;
			last=s[i];
			if(p==n+1)p=i;
			ans[i]=2;++cnt;
		}
	for(int i=1;i<p;++i)
		if(s[i]==x&&!ans[i])ans[i]=2,++cnt;
	if(cnt<n)return 0;
	for(int i=1;i<=n;++i)putchar(ans[i]^48);putchar('\n');
	return 1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;++i)s[i]-='0';
		bool flag=0;
		for(int i=0;i<=9;++i)
			if(check(i))
			{
				flag=1;
				break;
			}
		if(!flag)printf("-\n");
	}
	return 0;
}