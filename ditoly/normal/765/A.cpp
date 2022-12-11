#include<cstdio>
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x;
}
int main()
{
	int n=read(),x,a=0;char s[10];
	scanf("%s",s);x=(s[0]*1000+s[1])*1000+s[2];
	while(n--)
	{
		scanf("%s",s);
		if((s[0]*1000+s[1])*1000+s[2]==x)++a;
		if((s[5]*1000+s[6])*1000+s[7]==x)--a;
	}
	puts(a?"contest":"home");
}