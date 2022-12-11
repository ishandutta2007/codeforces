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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 2e5 + 5;

int n, a[N], ans, cnt[N], ty[N], c[N], z[N], o[N], s[N], ToT, vis[N], fis[N],
S, b[N], id[N], tot;
std::vector<int> ot[N], occ[N];

void inc(int c, int i, int &cur1, int &cur2, int delta)
{
	if (cnt[c] == i) cur1--; if (cnt[c] > i) cur2--;
	cnt[c] += delta;
	if (cnt[c] == i) cur1++; if (cnt[c] > i) cur2++;
}

int main()
{
	int cur = 0, x;
	read(n); S = sqrt(n);
	for (int i = 1; i <= n; i++) read(a[i]), b[a[i]]++;
	for (int i = 1; i <= n; i++) if (b[i] > S) id[i] = ++tot;
	for (int i = 1; i <= n; i++)
	{
		if ((++cnt[a[i]]) > cur) cur = cnt[a[i]], x = a[i];
		else if (cnt[a[i]] == cur) x = -1;
		ty[i] = x; c[i] = cur; o[i] = cnt[a[i]];
		if (x == -1) ans = i;
		if (id[a[i]]) ot[id[a[i]]].push_back(-i);
		if (x > 0 && id[x]) ot[id[x]].push_back(i);
	}
	for (int i = 1; i <= n; i++) z[i] = n + 1;
	for (int T = 1; T <= tot; T++)
	{
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (id[a[i]] == T);
		for (int D = 1; D <= tot; D++) if (D != T)
		{
			ToT++;
			for (int i = 0; i < ot[D].size(); i++)
				if (ot[D][i] < 0)
				{
					int tmp = o[-ot[D][i]] - s[-ot[D][i]];
					if (tmp >= 0 && vis[tmp] < ToT)
						vis[tmp] = ToT, fis[tmp] = -ot[D][i];
				}
				else
				{
					int tmp = c[ot[D][i]] - s[ot[D][i]];
					if (vis[tmp] == ToT)
						z[ot[D][i]] = Min(z[ot[D][i]], fis[tmp]);
				}
		}
	}
	for (int i = 1; i <= n; i++) ans = Max(ans, i - z[i]);
	for (int T = 1; T <= S; T++)
	{
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1, j = 1, cur1 = 0, cur2 = 0; i <= n; i++)
		{
			inc(a[i], T, cur1, cur2, 1);
			while (cur2) inc(a[j], T, cur1, cur2, -1), j++;
			if (cur1 > 1) ans = Max(ans, i - j + 1);
		}
	}
	return std::cout << ans << std::endl, 0;
}