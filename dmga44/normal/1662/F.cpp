#include <bits/stdc++.h>

using namespace std;

#ifdef NeverBeRed
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second

const int inf = -1e9;

struct segment_tree
{
	int n;
	vector<pair<int, int>> a;

	segment_tree(int n) : n(n), a(2 * n) {}

	void update(int p, int v)
	{
		for (a[p += n] = { v, p }; p /= 2;)
			a[p] = max(a[2 * p], a[2 * p + 1]);
	}

	pair<int, int> query(int l, int r)
	{
		pair<int, int> g = { inf, inf };

		for (l += n, r += n; l < r; l /= 2, r /= 2)
		{
			if (l & 1) g = max(g, a[l++]);
			if (r & 1) g = max(g, a[--r]);
		}

		return g;
	}
};

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		vector<int> p(n);
		for (auto &i : p) cin >> i;

		segment_tree s1(n), s2(n);
		for (int i = 0; i < n; ++i)
		{
			s1.update(i, p[i] - i);
			s2.update(i, p[i] + i);
		}

		queue<int> q;
		q.push(a - 1);
		vector<int> d(n, -1);
		d[a - 1] = 0;
		s1.update(a - 1, inf);
		s2.update(a - 1, inf);
		while (!q.empty())
		{
			int i = q.front();
			q.pop();

			int j = min(i + p[i], n - 1);
			while (true)
			{
				auto r = s1.query(i, j + 1);
				if (r.first == inf || r.second - p[r.second] > i) break;
				d[r.second] = d[i] + 1;
				q.push(r.second);
				s1.update(r.second, inf);
				s2.update(r.second, inf);
			}

			j = max(0, i - p[i]);
			while (true)
			{
				auto r = s2.query(j, i + 1);
				if (r.first == inf || p[r.second] + r.second < i) break;
				d[r.second] = d[i] + 1;
				q.push(r.second);
				s1.update(r.second, inf);
				s2.update(r.second, inf);
			}
		}
		debug(d);
		cout << d[b - 1] << "\n";
	}

	return 0;
}