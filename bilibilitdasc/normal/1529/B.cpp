#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
using namespace std;
typedef long long ll;
int n,cnt0,lst;
int a[100005],ans;
void solve()
{
	scanf("%d",&n);
	cnt0=0;ans=1;
	rep(i,n)
	{
		scanf("%d",a+i);
		if(a[i]>0) ++cnt0;
	}
	sort(a,a+n);
	if(cnt0==0)
	{
		printf("%d\n",n);
		return ;
	}
	if(cnt0==n)
	{
		printf("%d\n",1);
		return ;
	}
	lst=a[n-cnt0];
	for(int i=n-cnt0-1;i>=0;i--)
	{
		if(lst-a[i]>=a[n-cnt0])
		{
			++ans;
			lst=a[i];
		}
	}
	ans=max(ans,n-cnt0);
	printf("%d\n",ans);
}
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	solve();
	return 0;
}