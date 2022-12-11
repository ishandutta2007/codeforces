#include<cstdio>
inline int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-f;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int main()
{
	int n=read();
	puts("YES");
	while(n--)printf("%d\n",1+(read()&1)+((read()&1)<<1)),read(),read();
}