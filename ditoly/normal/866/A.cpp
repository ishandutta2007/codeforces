#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
int main()
{
	int n=read();
	if(n==1)puts("1 1\n1");
	else printf("%d 2\n1 2",n-1<<1);
}