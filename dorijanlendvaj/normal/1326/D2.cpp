/*input
5
a
abcdfdcecba
abbaxyzyx
codeforces
acbba

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(0);
bool dp[5000][5000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n = s.size();
		int kiek = 0;
		while ((kiek + 1) * 2 <= n)
		{
			if (s[kiek] == s[n - kiek - 1])
			{
				kiek++;
			}
			else
				break;
		}
		string t = s;
		reverse(t.begin(), t.end());
		ll S[n + 1];
		ll T[n + 1];
		S[0] = 0;
		T[0] = 0;
		const ll w = 123;
		ll PO[n + 1];
		PO[0] = 1;
		const ll mod = 1000000007;
		for (int i = 1; i <= n; i++)
		{
			PO[i] = (PO[i - 1] * w) % mod;
			S[i] = (S[i - 1] + PO[i] * ll(s[i - 1] - 'a' + 1)) % mod;
			T[i] = (T[i - 1] + PO[i] * ll(t[i - 1] - 'a' + 1)) % mod;
		}
		int p[n];
		iota(p, p + n, 0);
		shuffle(p, p + n, rng);
		auto same = [&](int sl, int tl, int sz)
		{
			for (int i : p)
			{
				i %= sz;
				if (s[sl + i] != t[tl + i])
					return false;
			}
			return true;
		};
		function<bool(int, int)>pal = [&](int l, int r)->bool
		{
			ll sh = S[r + 1] - S[l];
			ll th = T[n - l] - T[n - r - 1];
			int po = r + 1 - (n - l);
			if (po > 0)
			{
				th *= PO[po];
			}
			else
			{
				sh *= PO[-po];
			}
			th -= sh;
			if ((th % mod) == 0)
			{
				return same(l, n - r - 1, r - l + 1);
			}
			else
				return false;
		};
		string ans;
		ans.push_back(s[0]);
		if (kiek != 0)
		{
			ans = s.substr(0, kiek) + s.substr(n - kiek, kiek);
		}
		int mx = ans.size();
		int maxi = -1;
		for (int r = n - kiek - 1; r >= kiek; r--)
		{
			int l = kiek;
			int sz = r - l + 1 + 2 * (l);
			if (pal(l, r))
			{
				maxi = r;
				break;
			}
		}
		if (maxi != -1)
		{
			int l = kiek;
			int r = maxi;
			ans = s.substr(0, r + 1) + s.substr(n - l, l);
		}
		maxi = -1;
		for (int l = kiek; l <= n - kiek - 1; l++)
		{
			int r = n - kiek - 1;
			int sz = r - l + 1 + 2 * (n - r - 1);
			if (sz > (int)ans.size() && pal(l, r))
			{
				maxi = l;
				break;
				//ans = s.substr(0, n - r - 1) + s.substr(l, n - l);
			}
		}
		if (maxi != -1)
		{
			int l = maxi;
			int r = n - kiek - 1;
			ans = s.substr(0, n - r - 1) + s.substr(l, n - l);
		}
		cout << ans << "\n";
	}
	return 0;
}