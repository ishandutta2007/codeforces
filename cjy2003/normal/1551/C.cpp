#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
struct word
{
	int cnt[5],len;
}p[200020];
char s[400040];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s+1);
			int m=strlen(s+1);
			for(int j=1;j<=m;++j)++p[i].cnt[s[j]-'a'];
			p[i].len=m;
		}
		int ans=0;
		for(int i=0;i<5;++i)
		{
			sort(p+1,p+1+n,[&](word a,word b){return 2*a.cnt[i]-a.len>2*b.cnt[i]-b.len;});
			int sum=0,cur=0;
			for(int j=1;j<=n;++j)
				if(sum+2*p[j].cnt[i]-p[j].len>0)sum+=2*p[j].cnt[i]-p[j].len,++cur;
				else break;
			ans=max(ans,cur);
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;++i)memset(p[i].cnt,0,sizeof(p[i].cnt));
	}
	return 0;
}