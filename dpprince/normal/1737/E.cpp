// Author: Little09
// Problem: E. Ela Goes Hiking
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/E
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
const ll mod=1000000007;

const int N=1000005;
int n,m; 
ll dp[N],s[N],inv;
ll ksm(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}

void work()
{
	cin >> n;
	if (n==1)
	{
		cout << "1\n";
		return;
	}
	for (int i=1;i<=n;i++) dp[i]=0,s[i]=0;
	ll sum=0;
	for (int i=n;i>=2;i--)
	{
		int u=(i+1)/2;
		if (i==n) dp[i]=ksm(2,n-u-1);
		else dp[i]=ksm(2,n-u-2);
		sum=(sum+s[i])%mod;
		//cout << sum*ksm(inv,i-u-1)%mod << endl;
		dp[i]=(dp[i]-sum*ksm(inv,u)%mod+mod)%mod;
		s[i-u]=(s[i-u]+dp[i])%mod;
	}
	// ll rr=0;
	// for (int i=1;i<=n;i++) rr=(rr+dp[i])%mod;
	// for (int i=1;i<=n;i++) cout << dp[i] << " ";
	// cout << endl;
	// rr=rr*ksm(inv,n-2)%mod;
	// cout << rr << endl;
	for (int i=1;i<=n;i++) cout << dp[i]*ksm(inv,n-2)%mod << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	inv=ksm(2,mod-2);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}