#include<cstdio>
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 500
char s[MN+5];
int main()
{
	int i,x='a';
	scanf("%s",s);
	for(i=0;s[i];++i)
	{
		if(s[i]>x)return 0*puts("NO");
		if(s[i]==x)++x;
	}
	puts("YES");
}