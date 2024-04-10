#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
ll n,a,b,k;
ll c[200005],d[200005];
ll solve()
{
	ll res=k*(k-1)/2;
	rep(i,a) res-=c[i+1]*(c[i+1]-1)/2;
	rep(i,b) res-=d[i+1]*(d[i+1]-1)/2;
	return res;	
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	while(n--)
	{
		cin>>a>>b>>k;
		fill(c+1,c+a+1,0);
		fill(d+1,d+b+1,0);
		rep(i,k)
		{
			int e;
			cin>>e;
			c[e]++;
		}
		rep(i,k)
		{
			int f;
			cin>>f;
			d[f]++;
		}
		prt(solve());
	}
	return 0;
}