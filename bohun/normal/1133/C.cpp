#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
map < int, int > m;
int t[200005],a[200005];
int pref[200005];
int n;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i];
		m[t[i]]++;
	}
	sort(t + 1, t + n + 1);
	int ile = 1;
	for(int i = 1; n >= i; ++i)
	{
		while(t[i] == t[i - 1])
			i++;
		if(i <= n)
		{
			a[ile] = t[i];
			ile++;
		}
	}
	ile--;
	for(int i = 1; ile >= i; ++i)
		pref[i] = pref[i - 1] + m[a[i]];
	int opt = 0;
	for(int i = 1; ile >= i; ++i)
	{
		for(int j = i - 1; j > i - 10; j--)
		{
			if(a[i] - a[j] <= 5)
				opt = max(opt, pref[i] - pref[j-1]);
		}
		opt = max(opt, m[a[i]]);
	}
	cout << opt;
	return 0;
}