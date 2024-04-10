// Author: Little09
// Problem: C. Wish I Knew How to Sort
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforces.com/contest/1753/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define endl "\n"
#define printYes cout << "Yes\n"
#define printYES cout << "YES\n"
#define printNo cout << "No\n"
#define printNO cout << "NO\n"
#define lowbit(x) ((x)&(-(x)))
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
ll n,m; 
int a[N];
ll dp[N];

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
	for (int i=1;i<=n;i++) cin >> a[i];
	int sum=0;
	for (int i=1;i<=n;i++) sum+=(a[i]==0);
	int res=0;
	for (int i=1;i<=sum;i++) res+=a[i];
	dp[0]=0;
	ll s=n*(n-1)/2%mod;
	for (int i=1;i<=res;i++)
	{
		ll tmp=1ll*i*i%mod*ksm(s,mod-2)%mod;
		dp[i]=(dp[i-1]+ksm(tmp,mod-2))%mod;
	}
	cout << dp[res] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}