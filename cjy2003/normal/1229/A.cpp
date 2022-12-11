#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int>E[7070];
queue<int>q;
int n,b[7070],d[7070];
long long ans;
long long a[7070];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i!=j&&(a[i]&a[j])==a[i])E[j].push_back(i),++d[i];
	for(int i=1;i<=n;++i)if(!d[i])q.push(i);
	int x;
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(auto y:E[x])
		{
			--d[y];
			if(!d[y])q.push(y);
		}
	}
	for(int i=1;i<=n;++i)
		if(d[i])ans+=b[i];
	printf("%lld",ans);
	return 0;
}