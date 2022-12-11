#include<cstdio>
#define MAXN 200000
char s[MAXN+5];
int main()
{
	int n,i,ans=0;
	scanf("%d%s",&n,s);
	for(i=0;s[i]=='<';i++)ans++;
	for(n--;s[n]=='>';n--)ans++;
	printf("%d",ans);
}