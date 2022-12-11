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

const int N = 5e5 + 5;

int n, k, c[N];
ll ans;

std::priority_queue<ll> pq;

int main()
{
	read(n); read(k);
	for (int i = 1; i <= n; i++) read(c[i]);
	std::sort(c + 1, c + n + 1);
	for (int i = 1; i <= k + 1; i++) pq.push(0);
	for (int i = n; i >= 1; i--)
	{
		ll num = pq.top(); pq.pop();
		ans += num; pq.push(num + c[i]);
	}
	return std::cout << ans << std::endl, 0;
}