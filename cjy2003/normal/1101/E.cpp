#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,y,mx,my;
char opt;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf(" %c %d %d",&opt,&x,&y);
		if(x>y)swap(x,y);
		if(opt=='+')
		{
			mx=max(mx,x);
			my=max(my,y);
		}
		else
		{
			if(x>=mx&&y>=my)printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}