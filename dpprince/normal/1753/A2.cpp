// Author: Little09
// Problem: A2. Make Nonzero Sum (hard version)
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforces.com/contest/1753/problem/A2
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
int cnt;
int a[N],L[N],R[N];
void work(int l,int r)
{
	if (l==r&&a[l]==0)
	{
		L[++cnt]=l,R[cnt]=r;
		return;
	}
	if (a[l]!=a[r])
	{
		L[++cnt]=l,R[cnt]=r-1;
		L[++cnt]=r,R[cnt]=r;
		return;
	}
	else
	{
		if (l+1==r)
		{
			L[++cnt]=l,R[cnt]=r;
		}
		else
		{
			L[++cnt]=l,R[cnt]=r-2;
			L[++cnt]=r-1,R[cnt]=r;
		}
	}
	
}

void work()
{
	cin >> n;
	int sum=0;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) sum+=a[i];
	if (sum%2!=0)
	{
		cout << -1 << endl;
		return;
	}
	cnt=0;
	int las=-1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==0)
		{
			if (las==-1) work(i,i);
			else continue;
		}
		else
		{
			if (las==-1) las=i;
			else 
			{
				work(las,i);
				las=-1;
			}
		}
	}
	cout << cnt << endl;
	for (int i=1;i<=cnt;i++) cout << L[i] << " " << R[i] << endl;
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