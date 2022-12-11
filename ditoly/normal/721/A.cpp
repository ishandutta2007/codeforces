#include<cstdio>
#define MAXN 100
char s[MAXN+5];
int ans[MAXN+5],an;
int main()
{
	int n,i;
	scanf("%d%s",&n,&s);
	for(i=0;i<n;i++)if(s[i]=='B')
	{
		for(;s[i]=='B';i++)ans[an]++;
		an++;
	}
	printf("%d\n",an);
	for(i=0;i<an;i++)printf("%d ",ans[i]);
}