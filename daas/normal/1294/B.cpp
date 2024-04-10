#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n;
struct sb
{
	int x,y;
}a[1001];
inline int cmp(sb x,sb y)
{
	return x.x<y.x || (x.x==y.x && x.y<y.y);
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(register int i=1;i<=n;++i)
			a[i].x=read(),a[i].y=read();
		sort(a+1,a+n+1,cmp);
		int F=0;
		for(register int i=2;i<=n;++i)
			if(a[i].y<a[i-1].y)
			{
				F=1;
				break;
			}
		if(F)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		int x=0,y=0;
		for(register int i=1;i<=n;++i)
		{
			while(x<a[i].x)
				++x,putchar('R');
			while(y<a[i].y)
				++y,putchar('U');
		}
		putchar('\n');
	}
	return 0;
}