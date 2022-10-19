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
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//cin
map<long double,int> s;
long double a;
int b;
int num[5005];
int dp[5005];
int n,m,cnt,ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,n)
	{
		cin>>b>>a;
		s[a]=b;
	}
	for(map<long double,int>::iterator i=s.begin();i!=s.end();++i)
	{
		num[cnt++]=i->second;
	}
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(num[j]<=num[i])
			{
				dp[i]=max(dp[i],dp[j]);
			}
		}
		++dp[i];
		if(dp[i]>ans) ans=dp[i];
	}
	cout<<n-ans<<endl;
	return 0;
}