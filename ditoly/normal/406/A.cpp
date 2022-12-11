#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
int main()
{
	int n=read(),i,j,s=0;
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)s^=read()&&i==j;
	for(n=read();n--;)
		if(read()<3)read(),s^=1;
		else putchar(s?'1':'0');
}