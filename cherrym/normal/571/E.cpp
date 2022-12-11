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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 105, djq = 1e9 + 7, zyy = 1e9 + 9;

int n;
bool INFLEN = 1;
std::map<ll, int> is[N];

struct num
{
	int val, tot, p[N], q[N];
	std::map<int, int> cnt;
} a[N], b[N];

int qpow(int a, ll b)
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

num gen(int n)
{
	num res; res.tot = 0; res.cnt.clear(); res.val = n;
	int S = sqrt(n);
	for (int i = 2; i <= S; i++)
	{
		if (n % i) continue; res.p[++res.tot] = i; res.q[res.tot] = 0;
		while (n % i == 0) n /= i, res.q[res.tot]++;
	}
	if (n > 1) res.p[++res.tot] = n, res.q[res.tot] = 1;
	for (int i = 1; i <= res.tot; i++) res.cnt[res.p[i]] = res.q[i];
	return res;
}

bool same(num a, num b)
{
	if (a.tot != b.tot) return 0;
	for (int i = 1; i <= a.tot; i++)
		if (a.p[i] != b.p[i] || a.q[1] * b.q[i] - a.q[i] * b.q[1] != 0) return 0;
	return 1;
}

void exgcd(ll a, ll b, ll &x, ll &y)
{
	if (!b) return (void) (x = 1, y = 0);
	exgcd(b, a % b, y, x); y -= a / b * x;
}

ll inv(ll a, ll djq)
{
	ll x, y; exgcd(a, djq, x, y);
	return (x % djq + djq) % djq;
}

ll qmul(ll a, ll b, ll djq)
{
	a %= djq; b %= djq;
	ll res = a * b - (ll) ((long double) a / djq * b + 1e-8) * djq;
	return res < 0 ? res + djq : res;
}

int main()
{
	int x, y, pre = -1;
	read(n);
	for (int i = 1; i <= n; i++) read(x), read(y), a[i] = gen(x), b[i] = gen(y);
	for (int i = 1; i <= n; i++) if (!same(b[1], b[i])) INFLEN = 0;
	if (INFLEN)
	{
		ll fis, sec;
		for (int i = 1; i <= n; i++)
		{
			int tmp = a[i].val;
			for (int j = 1; j <= a[i].tot; j++)
				while (tmp % a[i].p[j] == 0) tmp /= a[i].p[j];
			if (pre != -1 && tmp != pre) return puts("-1"), 0;
			ll x = a[i].cnt[b[1].p[1]], y = b[i].q[1];
			if (pre == -1) fis = x, sec = y;
			else
			{
				ll g = std::__gcd(sec, y), t = fis % g;
				if (t != x % g) return puts("-1"), 0;
				sec /= g; y /= g; fis /= g; x /= g;
				ll m = (qmul(qmul(fis, y, sec * y), inv(y, sec), sec * y)
					+ qmul(qmul(x, sec, sec * y), inv(sec, y), sec * y)) % (sec * y);
				m = m * g + t; sec *= y * g;
				if (m < Max(x, fis)) m += (Max(x, fis) - m + sec - 1) / sec * sec;
				fis = m;
			}
			pre = tmp;
		}
		int ans;
		for (int i = 1; i <= n; i++)
		{
			ll c1 = (fis - a[1].cnt[b[1].p[1]]) / b[1].q[1],
				c2 = (fis - a[i].cnt[b[1].p[1]]) / b[i].q[1];
			if (i == 1) ans = 1ll * a[1].val * qpow(b[1].val, c1) % djq;
			for (int j = 2; j <= b[1].tot; j++)
				if (c1 * b[1].q[j] + a[1].cnt[b[1].p[j]]
					!= c2 * b[i].q[j] + a[i].cnt[b[1].p[j]])
						return puts("-1"), 0;
		}
		return std::cout << ans << std::endl, 0;
	}
	for (int i = 1; i <= n; i++)
		for (int T = 0, a1 = a[i].val, a2 = a[i].val; T <= 4000; T++)
			is[i][1ll * a1 * zyy + a2] = 1, a1 = 1ll * a1 * b[i].val % djq,
				a2 = 1ll * a2 * b[i].val % zyy;
	for (int T = 0, a1 = a[1].val, a2 = a[1].val; T <= 4000; T++)
	{
		bool orz = 1;
		for (int i = 1; i <= n; i++) if (!is[i].count(1ll * a1 * zyy + a2))
			{orz = 0; break;}
		if (orz) return std::cout << a1 << std::endl, 0;
		a1 = 1ll * a1 * b[1].val % djq; a2 = 1ll * a2 * b[1].val % zyy;
	}
	return puts("-1"), 0;
}