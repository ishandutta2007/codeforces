#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
int main()
{
	int n=read(),i,s=0,l,r;
	for(i=1;i<=n;++i)s+=read();
	for(i=read();i--;)
	{
		l=read();r=read();
		if(r>=s)return 0*printf("%d",max(l,s));
	}
	puts("-1");
}