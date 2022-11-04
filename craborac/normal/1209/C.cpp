#include <bits/stdc++.h>

using namespace std;

int cnt[300], used[(int)2e5 + 10];

void solve()
{
	int n;
	string s;
	cin >> n >> s;
	fill(cnt, cnt + 10, 0);
	fill(used, used + n, 0);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cnt[s[i] - '0']++;
	}
	for (int i = 0; i < n; i++)
	{
		int x = s[i] - '0';
		bool d = 1;
		for (int j = 0; j < x; j++)
			if (cnt[j] > 0)
				d = 0;
		if (d)
		{
			used[i] = 1;
			cnt[x]--;
			sum++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int x = s[i] - '0';
		bool d = 1;
		for (int j = 0; j < x; j++)
			if (cnt[j] > 0)
				d = 0;
		if (d && used[i] == 0)
		{
			used[i] = 2;
			cnt[x]--;
			sum++;
		}
	}
	if (sum == n)
	{
		for (int i = 0; i < n; i++)
			cout << used[i];
		cout << "\n";
	}
	else
		cout << "-\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    	solve();
    return 0;
}