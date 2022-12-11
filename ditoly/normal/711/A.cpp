#include<cstdio>
#define MAXN 1000
char s[MAXN+5][5+5];
int main()
{
	int n,i,o=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",&s[i]);
		if(o&&s[i][0]=='O'&&s[i][1]=='O'){s[i][0]=s[i][1]='+';o=0;}
		if(o&&s[i][3]=='O'&&s[i][4]=='O'){s[i][3]=s[i][4]='+';o=0;}
	}
	puts(o?"NO":"YES");
	if(!o)for(i=0;i<n;i++)puts(s[i]);
}