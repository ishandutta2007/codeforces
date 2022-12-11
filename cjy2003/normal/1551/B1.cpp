#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
char s[100];
int cnt[100];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=1;i<=n;++i)++cnt[s[i]-'a'];
		int tot=0;
		for(int i=0;i<26;++i)tot+=min(cnt[i],2);
		printf("%d\n",tot/2);
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}