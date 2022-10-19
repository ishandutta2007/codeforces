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
set<ll> cubeset;
ll cubearr[10005];
ll n;
void solve()
{
	scanf("%lld",&n);
	for(ll i=1;i<=10000;i++)
	{
		ll dif=n-i*i*i;
		if(dif<=0)
		{
			break;
		}
		if(cubeset.count(dif))
		{
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}
int t;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=10000;i++)
	{
		cubearr[i]=i*i*i;
		cubeset.insert(i*i*i);
	}
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}