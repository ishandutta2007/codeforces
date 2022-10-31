#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);

	string s; cin >> s;
	int n = s.length();
	vector<int> dist(n);
	for (int i = 0; i < n; ++i)
		if (s[i] == '0') dist[i] = (i ? dist[i-1] : 0) + 1;

	vector<int> dp(n + 2), nxt(n+2, n);
	auto get = [&](int i) { return nxt[i] < n ? dp[nxt[i]] : 0; };

	for (int i = n-1; i >= 0; --i)
	{
		dp[i] = ((dist[i] <= dist.back()) + get(0) + get(dist[i] + 1)) % mod;
		nxt[dist[i]] = i;
	}

	int ans = n;
	if (nxt[0] < n)
		ans = ((long long)get(0) * (nxt[0] + 1)) % mod;
	cout << ans << "\n";

	return 0;
}