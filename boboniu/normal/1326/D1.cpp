#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 998244353;
const int maxN = 222222;

int t;
string solve(string s)
{
	int n = s.size();
	vector<int> d1(n);
	for (int i = 0, l = 0, r = -1; i < n; i++)
	{
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
		{
			k++;
		}
		d1[i] = k--;
		if (i + k > r)
		{
			l = i - k;
			r = i + k;
		}
	}
	vector<int> d2(n);
	for (int i = 0, l = 0, r = -1; i < n; i++)
	{
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
		{
			k++;
		}
		d2[i] = k--;
		if (i + k > r)
		{
			l = i - k - 1;
			r = i + k;
		}
	}
	int t = 0;
	while (t < n - t - 1 && s[t] == s[n - t - 1])
		t++;
	t--;
	int ans = 1;
	vector<int> sol{0, 0, 0};
	if (t >= 0)
	{
		ans = 2 * t + 2;
		sol = {0, t, 1};
	}
	for (int i = 0; i < n; i++)
	{
		//cout << i << " " << d1[i] << " " << n << endl;
		if (i - d1[i] <= t && 2 * i + 1 <= n)
		{
			if (2 * i + 1 > ans)
			{
				ans = 2 * i + 1;
				sol = {0, i, 0};
			}
		}
		if (i > 0 && i - 1 - d2[i] <= t && 2 * i <= n)
		{
			if (2 * i > ans)
			{
				ans = 2 * i;
				sol = {0, i - 1, 1};
			}
		}
	}
	//cout << sol[1] << " " << sol[2] << " " << ans << endl;
	string t1, t2;
	for (int i = 0; i <= sol[1]; i++)
		t1.push_back(s[i]);
	t2 = t1;
	if (sol[2] == 0)
		t2.pop_back();
	reverse(t2.begin(), t2.end());
	t1 += t2;
	return t1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string s;
		cin >> s;
		string t1 = solve(s);
		reverse(s.begin(), s.end());
		string t2 = solve(s);
		if (t2.size() > t1.size())
			t1 = t2;
		cout << t1 << "\n";
	}
}