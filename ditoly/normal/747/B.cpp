#include<cstdio>
#define MN 255
char s[MN+5];
int k[MN+5];
int main()
{
	int n,i;
	scanf("%d%s",&n,s);
	if(n%4)return 0*puts("===");
	for(i=0;i<n;++i)if(s[i]!='?'&&++k[s[i]]>n/4)return 0*puts("===");
	for(i=0;i<n;++i)
	{
		if(s[i]!='?')putchar(s[i]);
		else if(k['A']<n/4)putchar('A'),++k['A'];
		else if(k['C']<n/4)putchar('C'),++k['C'];
		else if(k['G']<n/4)putchar('G'),++k['G'];
		else putchar('T'),++k['T'];
	}
}