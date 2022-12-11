#include<stdio.h>
#include<string.h>
int n,t[30];
char s[100010];
int main()
{
	scanf("%d %s",&n,s+1);
	for(int i=1;i<=n;++i)
		++t[s[i]-'a'+1];
	for(int i=1;i<=26;++i)
		for(int j=1;j<=t[i];++j)
			printf("%c",i+'a'-1);
	return 0;
}