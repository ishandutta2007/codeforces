#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 998244353;
const int maxN = 222222;

int k, n;
int a[maxN], pos[maxN];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}
	i64 sum = 0;
	vector<int> p;
	for (int i = n - k + 1; i <= n; i++)
	{
		sum += i;
		p.push_back(pos[i]);
	}
	sort(p.begin(), p.end());
	i64 ans = 1;
	for (int i = 0; i < k - 1; i++)
	{
		ans = ans * (p[i + 1] - p[i]) % mod;
	}
	//ans = ans * (p[0] + 1) % mod;
	//ans = ans * (n - p[k - 1]) % mod;
	cout << sum << " " << ans << endl;
}