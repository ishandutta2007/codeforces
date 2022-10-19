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
int n,m,ans;
int a[105];
void solve()
{
	scanf("%d",&n);
	m=0x3f3f3f3f;
	ans=0;
	rep(i,n)
	{
		scanf("%d",a+i);
		m=min(m,a[i]);
	}
	rep(i,n)
	{
		if(a[i]!=m) ans++;
	}
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