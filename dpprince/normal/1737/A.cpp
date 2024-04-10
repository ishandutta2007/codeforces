// Author: Little09
// Problem: A. Ela Sorting Books
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/A
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
char a[N];
int b[27];

void work()
{
	cin >> n >> m;
	mem(b);
	for (int i=1;i<=n;i++) 
	{
		char x;
		cin >> x;
		b[x-'a']++;
	}
	for (int i=1;i<=m;i++)
	{
		int uuu=n/m;
		for (int j=0;j<26;j++)
		{
			if (b[j]>0&&uuu>0)
			{
				b[j]--,uuu--;
			}
			else
			{
				char ans=j+'a';
				cout << ans;
				break;
			}
		}
	}
	cout << endl;
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