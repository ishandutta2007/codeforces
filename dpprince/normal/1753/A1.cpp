// Author: Little09
// Problem: A1. Make Nonzero Sum (easy version)
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforces.com/contest/1753/problem/0
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
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];
int b[N];


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	if (n%2==1)
	{
		cout << -1 << endl;
		return;
	}
	int cnt=0;
	for (int i=1;i<=n;i+=2)
	{
		if (a[i]==a[i+1]) b[++cnt]=i+1;
		else b[++cnt]=i,b[++cnt]=i+1;
	}
	b[0]=0;
	cout << cnt << endl;
	for (int i=1;i<=cnt;i++)
	{
		cout << b[i-1]+1 << " " << b[i] << endl;
	}
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