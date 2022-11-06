#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <tuple>
#include <map>
template <typename T> constexpr T my_abs(const T &x) { return x < 0 ? -x : x; }
using ll = long long;
constexpr int MOD = 1e9 + 7;
inline int quick_pow(int a, int n)
{
	int res = 1;
	while (n)
	{
		if (n & 1)
			res = (ll)res * a % MOD;
		a = (ll)a * a % MOD;
		n >>= 1;
	}
	return res;
}
struct permutation
{
	int arr[5];
	permutation() { memset(arr, 0, sizeof(arr)); }
	inline int &operator [](int x) { return arr[x]; }
	inline const int &operator [](int x) const { return arr[x]; }
	inline int get_val() const
	{
		int res = 0;
		for (int i = 0; i < 5; i++)
			res = res * 5 + arr[i];
		return res;
	}
} perm[205];
struct mask : std::vector<bool> { mask() { resize(205); } };
constexpr int fact[] = {0, 1, 2, 6, 24, 120};
mask sub[205];
std::map<mask, int> idx_sub;
int idx[4005], mul[205][205], que[205], sz[205], arr[200005];
int sub_perm[205][205], merge[205][205], all[800005];
std::vector<std::pair<int, int> > left[800005], right[800005];
ll ans = 0;
inline void pure(std::vector<std::pair<int, int> > &res)
{
	auto vec = res;
	std::sort(vec.begin(), vec.end());
	res.clear();
	for (auto &it : vec)
	{
		if (res.empty() || res.back().first != it.first)
			res.push_back(it);
		else
			res.back().second += it.second;
	}
}
void work(int u, int l, int r)
{
	if (l == r)
	{
		left[u] = right[u] = {{arr[l], 1}};
		all[u] = arr[l];
		ans += sz[arr[l]];
		return;
	}
	int m = l + r >> 1;
	work(u << 1, l, m);
	work(u << 1 | 1, m + 1, r);
	for (auto &x : right[u << 1])
	{
		for (auto &y : left[u << 1 | 1])
			ans += (ll)sz[merge[x.first][y.first]] * x.second * y.second;
	}
	left[u] = left[u << 1];
	for (auto &it : left[u << 1 | 1])
		left[u].emplace_back(merge[it.first][all[u << 1]], it.second);
	right[u] = right[u << 1 | 1];
	for (auto &it : right[u << 1])
		right[u].emplace_back(merge[it.first][all[u << 1 | 1]], it.second);
	all[u] = merge[all[u << 1]][all[u << 1 | 1]];
	pure(left[u]);
	pure(right[u]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1229D.in", "r", stdin);
#endif
	int n, L, cnt = 0;
	scanf("%d%d", &n, &L);
	for (int i = 0; i < L; i++)
		perm[0][i] = i;
	for (int i = 0; i < fact[L]; i++)
	{
		perm[i] = perm[0];
		idx[perm[0].get_val()] = i;
		std::next_permutation(perm[0].arr, perm[0].arr + L);
	}
	for (int i = 0; i < fact[L]; i++)
	{
		for (int j = 0; j < fact[L]; j++)
		{
			permutation tmp;
			for (int k = 0; k < L; k++)
				tmp[k] = perm[i][perm[j][k]];
			mul[i][j] = idx[tmp.get_val()];
		}
	}
	sub[0][0] = true;
	idx_sub[sub[0]] = cnt++;
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < fact[L]; j++)
		{
			int he = 0, ta = 1;
			mask nxt = sub[i];
			que[0] = j;
			while (he < ta)
			{
				auto add = [&] (int u)
				{
					if (!nxt[u])
					{
						nxt[u] = true;
						que[ta++] = u;
					}
				};
				int u = que[he++];
				for (int k = 0; k < fact[L]; k++)
				{
					if (nxt[k])
					{
						add(mul[u][k]);
						add(mul[k][u]);
					}
				}
			}
			if (!idx_sub.count(nxt))
			{
				idx_sub[nxt] = cnt;
				sub[cnt++] = nxt;
			}
			sub_perm[i][j] = idx_sub[nxt];
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < fact[L]; j++)
			sz[i] += sub[i][j];
		for (int j = 0; j < cnt; j++)
		{
			int u = i;
			for (int k = 0; k < fact[L]; k++)
			{
				if (sub[j][k])
					u = sub_perm[u][k];
			}
			merge[i][j] = u;
		}
	}
	for (int i = 0; i < n; i++)
	{
		permutation tmp;
		for (int j = 0; j < L; j++)
		{
			scanf("%d", &tmp[j]);
			tmp[j]--;
		}
		arr[i] = sub_perm[0][idx[tmp.get_val()]];
	}
	work(1, 0, n - 1);
	printf("%lld\n", ans);
	return 0;
}