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

const int N = 1e6 + 5, djq = 1e9 + 7;
const ll INF = 2e6;

int n, p, k[N], m, val[N], len[N];
ll pc[N];

int qpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % djq;
		a = 1ll * a * a % djq;
		b >>= 1;
	}
	return res;
}

void work()
{
	read(n); read(p);
	for (int i = 1; i <= n; i++) read(k[i]);
	if (p == 1) return (void) printf("%d\n", n & 1);
	pc[0] = 1;
	for (int i = 1; i <= 100; i++)
	{
		pc[i] = pc[i - 1] * p;
		if (pc[i] > INF) pc[i] = INF;
	}
	std::sort(k + 1, k + n + 1);
	m = 0;
	for (int i = 1, j = 0; i <= n; i++)
	{
		j++;
		if (i == n || k[i] < k[i + 1]) val[++m] = k[i], len[m] = j, j = 0;
	}
	int ans = 0; bool vis = 0; ll cur = 0;
	for (int i = m; i >= 1; i--, cur = std::min(cur * pc[val[i + 1] - val[i]], INF))
		if (!vis)
		{
			if (len[i] & 1) ans = qpow(p, val[i]), cur = 1, vis = 1;
		}
		else
		{
			if ((len[i] & 1) == (cur & 1))
			{
				if (len[i] >= cur) ans = 0, vis = 0, cur = 0;
				else ans = (ans - 1ll * len[i] * qpow(p, val[i]) % djq + djq) % djq,
					cur -= len[i];
			}
			else
			{
				if (len[i] >= cur) ans = qpow(p, val[i]), cur = 1;
				else ans = (ans - 1ll * len[i] * qpow(p, val[i]) % djq + djq) % djq,
					cur -= len[i];
			}
		}
	printf("%d\n", ans);
}

int main()
{
	for (int i = 101; i < N; i++) pc[i] = INF;
	int T; read(T);
	while (T--) work(); 
	return 0;
}