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
//ios_base::sync_with_stdio(false);cin
int ans;
long long n;
void solve()
{
	cin>>n;ans=0;
	while((n&1)==0)
	{
		++ans;n>>=1;
	}
	while(n%3==0)
	{
		ans+=2;n/=3;
	}
	while(n%5==0)
	{
		ans+=3;n/=5;
	}
	if(n>1)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}
}
int q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>q;
	while(q--)
	solve();
	return 0;
}