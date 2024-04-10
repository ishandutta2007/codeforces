#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int ans[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,x,h;
		priority_queue<pair<int,int> > q;
		scanf("%d %d %d",&n,&m,&x);
		for(int i=1;i<=m;++i) q.push(make_pair(0,i));
		pair<int,int> now;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&h);
			now=q.top(),q.pop();
			ans[i]=now.second;
			now.first-=h,q.push(now);
		}
		if(n<m) puts("NO");
		else
		{
			puts("YES");
			for(int i=1;i<=n;++i)
				printf("%d ",ans[i]);
			putchar('\n');
		}
	}
	return 0;
}