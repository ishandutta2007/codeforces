#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
priority_queue<PII,vector<PII>,greater<PII> > q;
vector<int> all;
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,temp;i<=n;i++)
	{
		scanf("%d",&temp);
		q.push(make_pair(temp,i));
		if(q.size()>m*k) q.pop();
	}
	long long ans=0;
	while(!q.empty())
	{
		ans+=q.top().first;
		all.push_back(q.top().second);
		q.pop();
	}
	printf("%lld\n",ans);
	sort(all.begin(),all.end());
	int cnt=0;
	for(int i=m-1;i<all.size();i+=m)
	{
		cnt++;
		if(cnt>=k) break;
		printf("%d ",all[i]);
	}
	puts("");

	
}