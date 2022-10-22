#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 110
using namespace std;
int T,n,x,w[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		bool flag=1;
		scanf("%d %d",&n,&x);
		for(int i=1;i<=n;++i)
			scanf("%d",w+i);
		for(int i=1;i<=n;++i)
		{
			x-=w[i];
			if(!x)
			{
				if(i!=n) swap(w[i],w[i+1]);
				else flag=0;
				break;
			}
			if(x<0) break;
		}
		if(flag)
		{
			puts("YES");
			for(int i=1;i<=n;++i)
				printf("%d ",w[i]);
			putchar('\n');
		}
		else puts("NO");
	}
	return 0;
}