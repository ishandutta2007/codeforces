#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<queue>
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
int map[101][101],n,m,h,ha[101],li[101];
int main()
{
	n=read(),m=read(),h=read();
	for(register int i=1;i<=m;++i)
		li[i]=read();
	for(register int i=1;i<=n;++i)
		ha[i]=read();
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=m;++j)
		{
			int pd=read();
			if(pd)
				map[i][j]=min(li[j],ha[i]);
		}
	for(register int i=1;i<=n;++i)
	{
		for(register int j=1;j<=m;++j)
			printf("%d ",map[i][j]);
		putchar('\n');
	}
    return 0;
}