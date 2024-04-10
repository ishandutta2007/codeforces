#include<cstdio>
#include<queue>
#define N 100010
#define ll long long
using namespace std;
priority_queue<ll,vector<ll>,greater<ll> >q;
int n,a[N],t[N];
ll s[N],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		s[i]=s[i-1]+t[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=0;
		q.push(a[i]+s[i-1]);
		while(!q.empty()&&q.top()<s[i])
		{
			ans+=q.top()-s[i-1];
			q.pop();
		}
		ans+=1ll*q.size()*t[i];
		printf("%lld ",ans);
	}
	return 0;
}