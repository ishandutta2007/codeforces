// Author: Little09
// Problem: B. Ela's Fitness and the Luxury Number
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
//const ll mod=1000000007;

const int N=500005;
int n,m; 

ll calc(ll a)
{
	ll l=0,r=1e9,res=0;
	while (l<=r)
	{
		ll mid=(l+r)>>1;
		if (mid*mid<=a) l=mid+1;
		else r=mid-1;
	}
	res+=r;
	l=0,r=1e9;
	while (l<=r)
	{
		ll mid=(l+r)>>1;
		if (mid*(mid+1)<=a) l=mid+1;
		else r=mid-1;
	}
	res+=r;
	l=0,r=1e9;
	while (l<=r)
	{
		ll mid=(l+r)>>1;
		if (mid*(mid+2)<=a) l=mid+1;
		else r=mid-1;
	}
	res+=r;
	return res;
}

void work()
{
	ll l,r;
	cin >> l >> r;
	cout << calc(r)-calc(l-1) << endl;
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