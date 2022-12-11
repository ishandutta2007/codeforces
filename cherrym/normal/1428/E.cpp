#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

typedef long long ll;

const int N = 1e5 + 5;

int n, k, a[N], b[N];
ll ans;

struct elem
{
	int x, cnt; ll nxt;

	friend inline bool operator < (elem a, elem b)
	{
		return a.nxt < b.nxt;
	}
};

ll calc(int x, int d)
{
	int tmp = x / d, z = x % d;
	return 1ll * (tmp + 1) * (tmp + 1) * z + 1ll * tmp * tmp * (d - z);
}

std::priority_queue<elem> pq;

int main()
{
	read(n); read(k); k -= n;
	for (int i = 1; i <= n; i++) read(a[i]), ans += calc(a[i], 1),
		pq.push((elem) {i, 1, a[i] == 1 ? -1 :
			calc(a[i], 1) - calc(a[i], 2)});
	while (k--)
	{
		elem t = pq.top(); pq.pop(); ans -= t.nxt;
		pq.push((elem) {t.x, t.cnt + 1, t.cnt + 1 == a[t.x] ? -1 :
			calc(a[t.x], t.cnt + 1) - calc(a[t.x], t.cnt + 2)});
	}
	return std::cout << ans << std::endl, 0;
}