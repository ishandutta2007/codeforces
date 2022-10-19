#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
int t,x,y;
void solve()
{
	cin>>x>>y;
	ll ans=0;
	for(int k=1;k*k<x;k++)
	{
		int cnt=min(y,x/k-1)-k;
		if(cnt>0) ans+=cnt;
	}
	cout<<ans<<endl;
}
int main()
{
	cin>>t;
	while(t--) solve();
	return 0;
}