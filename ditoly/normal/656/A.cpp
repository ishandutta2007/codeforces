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
	int x=read();
	printf("%I64d",x>12?8092LL<<x-13:1<<x);
}