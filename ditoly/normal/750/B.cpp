#include<cstdio>
int main()
{
	int n,p=0,x;char s[10];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%s",&x,s);
		if(!p&&s[0]!='S')return 0*puts("NO");
		if(p==20000&&s[0]!='N')return 0*puts("NO");
		if(s[0]=='S')p+=x;
		if(s[0]=='N')p-=x;
		if(p<0||p>20000)return 0*puts("NO");
	}
	puts(p?"NO":"YES");
}