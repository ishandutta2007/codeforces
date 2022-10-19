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
//long long , 
//ios_base::sync_with_stdio(false);cin
int t;
int n,l,r;
long long ans;
int a[200005];
void solve()
{
	cin>>n>>l>>r;
	ans=0;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		if(l<=(a[i]<<1)&&(a[i]<<1)<=r) --ans;
	}
	sort(a,a+n);
	for(int i=0;i<n;++i)
	{
		ans+=upper_bound(a,a+n,r-a[i])-lower_bound(a,a+n,l-a[i]);
	}
	cout<<(ans>>1)<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--)
	solve();
	return 0;
}