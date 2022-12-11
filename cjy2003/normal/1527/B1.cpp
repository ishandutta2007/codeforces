#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
char s[1010];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int cnt00=0,cnt01=0,cnt0=0;
		for(int i=1;2*i<=n;++i)
			if(s[i]=='0'&&s[n+1-i]=='0')++cnt00;
			else if(s[i]!=s[n+1-i])++cnt01;
		if(n&1&&s[n/2+1]=='0')cnt0=1;
		if(cnt0==1&&!cnt01&&!cnt00)printf("BOB\n");
		else if(cnt01==1&&cnt0==1&&!cnt00)printf("DRAW\n");
		else if(cnt01+cnt0)printf("ALICE\n");
		else if(cnt00)printf("BOB\n");
		else printf("DRAW\n");
	}

	return 0;
}