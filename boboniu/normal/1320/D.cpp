#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
mt19937 rnd(random_device{}());

const int maxN = 222222;
const i64 P1 = 998244353, P2 = 1000000007;
int n, q, ps[maxN];
string s;

i64 base1 = rnd() % P1, base2 = rnd() % P2;

struct RollingHash
{
	int len;
	i64 val1[maxN], val2[maxN];
	i64 pow1[maxN], pow2[maxN];
	void init()
	{
		pow1[0] = 1;
		pow2[0] = 1;
	}
	void add(int v)
	{
		len += 1;
		val1[len] = (val1[len - 1] * base1 + v) % P1;
		val2[len] = (val2[len - 1] * base2 + v) % P2;
		pow1[len] = pow1[len - 1] * base1 % P1;
		pow2[len] = pow2[len - 1] * base2 % P2;
	}

	pair<i64, i64> query(int l, int r)
	{
		i64 v1 = (val1[r] - val1[l] * pow1[r - l]) % P1;
		i64 v2 = (val2[r] - val2[l] * pow2[r - l]) % P2;
		if (v1 < 0)
			v1 += P1;
		if (v2 < 0)
			v2 += P2;
		//cout << v1 << " " << v2 << "\n";
		return {v1, v2};
	}
} val[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> s;
	val[0].init();
	val[1].init();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0')
		{
			ps[i + 1] = ps[i] + 1;
			val[0].add(i % 2);
			val[1].add(1 - i % 2);
		}
		else
		{
			ps[i + 1] = ps[i];
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int l, r, len;
		cin >> l >> r >> len;
		--l;
		--r;
		if (ps[r + len] - ps[r] != ps[l + len] - ps[l])
		{
			cout << "No\n";
		}
		else
		{
			if (val[l % 2].query(ps[l], ps[l + len]) != val[r % 2].query(ps[r], ps[r + len]))
			{
				cout << "No\n";
			}
			else
			{
				cout << "Yes\n";
			}
		}
	}
}