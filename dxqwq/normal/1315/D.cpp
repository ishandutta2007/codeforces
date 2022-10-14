#include <bits/stdc++.h>
#define pii pair<int,int>
#define s1 first
#define s2 second
using namespace std;
priority_queue<int> pq;int n;pii a[200101];
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",&a[i].s1);for(int i=1;i<=n;++i)scanf("%d",&a[i].s2);
	sort(a+1,a+1+n);int pt=1,cur=a[1].s1,lst=1;long long ans=0,sum=0;
	while(pt<=n)
	{
		for(int i=1;i<=a[pt].s1-a[pt-1].s1-1&&!pq.empty();++i){ans+=sum;int x=pq.top();sum-=x;pq.pop();}ans+=sum;
		while(a[pt].s1==cur&&pt<=n)++pt;--pt;
		for(int i=lst;i<pt;++i)pq.push(a[i].s2),sum+=a[i].s2;
		if(!pq.empty()&&a[pt].s2<pq.top())sum-=pq.top()-a[pt].s2,pq.pop(),pq.push(a[pt].s2);++pt;cur=a[pt].s1;lst=pt;
	}
	while(!pq.empty())ans+=sum,sum-=pq.top(),pq.pop();
	printf("%lld\n",ans);return 0;
}