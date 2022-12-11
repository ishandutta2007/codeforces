#include <cstdio>
#include <cstring>
#include <algorithm>
#define MS 105
#define mod 9875321
using namespace std;
char c[MS],nc[MS];
int n,m,tp,h,ans;
bool mp[mod];

inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}

int main()
{
	register int i;
	n=read();
	while (n--)
	{
		scanf("%s",c+1);
		m=strlen(c+1); tp=h=0;
		for (i=1;i<=m;++i)
		{
			if (c[i]=='h') while (nc[tp]=='k') nc[tp--]='\0';
			nc[++tp]=c[i];
			if (c[i]=='u') nc[tp]='o',nc[++tp]='o';
		}
		for (i=1;i<=tp;++i) h=(h*31+nc[i]-'a'+1)%mod;
		if (!mp[h]) mp[h]=true,++ans;
	}
	printf("%d",ans);
}