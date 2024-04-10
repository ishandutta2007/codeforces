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
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//cin
const int N=200005;
int cnt[N*2];
int a,n,t;
long long ans;
void Q()
{
	ans=0;
	memset(cnt,0,sizeof(cnt));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cnt[a-i+n]++;
	}
	n<<=1;
	for(int i=0;i<n;i++)
	{
		ans+=(1ll*cnt[i]*(cnt[i]-1))>>1;
	}
	cout<<ans<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--) Q();
	return 0;
}