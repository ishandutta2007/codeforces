#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <random>
#include <tuple>
#include <map>
template <typename T> constexpr T my_abs(const T &x) { return x < 0 ? -x : x; }
using ll = long long;
constexpr int mod[] = {954898669, 913378723, 921125801, 933600881, 963913429,
					   905966419, 989209577, 967835371, 958702639
					  };
struct data
{
	int val[9];
	data(int x = 0) { for (int i = 0; i < 9; i++) val[i] = x; }
	inline void operator +=(const data &x)
	{
		for (int i = 0; i < 9; i++)
			(val[i] += x.val[i]) >= mod[i] ? (val[i] -= mod[i]) : 0;
	}
	inline data operator *(const data &x) const
	{
		data res;
		for (int i = 0; i < 9; i++)
			res.val[i] = (ll)val[i] * x.val[i] % mod[i];
		return res;
	}
	inline bool operator <(const data &x) const
	{
		for (int i = 0; i < 9; i++)
		{
			if (val[i] != x.val[i])
				return val[i] < x.val[i];
		}
		return false;
	}
} pw[1000005];
int seq[1000005], arr[100005];
std::map<int, bool> vis;
std::map<data, int> app;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1246B.in", "r", stdin);
#endif
	int n, k, cnt = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
		int val = arr[i];
		for (int j = 2; j * j <= val; j++)
		{
			if (val % j)
				continue;
			if (!vis[j])
				seq[cnt++] = j;
			while (!(val % j))
				val /= j;
		}
		if (val != 1 && !vis[val])
			seq[cnt++] = val;
	}
	std::sort(seq, seq + cnt);
	cnt = std::unique(seq, seq + cnt) - seq;
	int bs = std::mt19937(std::random_device{}())() % 100 + 100;
	pw[0] = 1;
	for (int i = 1; i <= cnt; i++)
		pw[i] = pw[i - 1] * (data)bs;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		int val = arr[i];
		data hsh, rem;
		for (int j = 2; j * j <= val; j++)
		{
			if (val % j)
				continue;
			int rk = std::lower_bound(seq, seq + cnt, j) - seq, e = 0;
			while (!(val % j))
			{
				val /= j;
				e++;
			}
			e %= k;
			if (!e)
				continue;
			hsh += pw[rk] * (data)e;
			rem += pw[rk] * (data)(k - e);
		}
		if (val != 1)
		{
			int rk = std::lower_bound(seq, seq + cnt, val) - seq, e = 1;
			hsh += pw[rk] * (data)e;
			rem += pw[rk] * (data)(k - e);
		}
		ans += app[rem];
		app[hsh]++;
	}
	printf("%lld\n", ans);
	return 0;
}