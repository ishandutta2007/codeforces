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
//cin
int need(int a,int b)
{
	if(a>b) a^=b^=a^=b;
	int ans=0;
	while(a*2<b)
	{
		a*=2;
		ans++;
	}
	return ans;
}
int n,a[55];
void solve()
{
	int ans=0;
	cin>>n;
	rep(i,n) cin>>a[i];
	rep(i,n-1) ans+=need(a[i],a[i+1]);
	cout<<ans<<endl;
}
int t;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--) solve();
	return 0;
}