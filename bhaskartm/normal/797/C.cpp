#include<cstdio>
char c,a[100003],s[100003];
int i=1,j,n,t;
int main()
{
	for(scanf("%s",a+1);a[++n];);
	for(--n,c=97;c<123;++c)
	{
		for(;t&&s[t]<=c;putchar(s[t--]));
		for(j=n;j&&a[j]!=c;--j);
		for(;i<=j;++i)
			if((s[++t]=a[i])==c)putchar(s[t--]);
	}
	for(;t;putchar(s[t--]));
}