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
inline T Abs(T x) {return x < 0 ? -x : x;}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 5005;

int n, t[N], x[N], h[N];
bool a[N][N], f[N], g[N];

bool judge(int i, int ti, int j, int k, int m)
{
	if (Abs(x[i] - x[k]) > 1000000000) return 0; 
	int tk = Abs(x[i] - x[k]) + ti; if (tk < m) tk = m;
	return tk <= t[j] && t[j] - tk >= Abs(x[k] - x[j]);
}

int main()
{
	read(n); f[0] = 1;
	for (int i = 0; i <= n; i++) h[i] = 1061109567;
	for (int i = 1; i <= n; i++) read(t[i]), read(x[i]), a[i][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			a[i][j] = a[i][j - 1] && t[j] - t[j - 1] >= Abs(x[j] - x[j - 1]);
	for (int i = 0; i < n; i++)
	{
		if (f[i])
		{
			if (t[i + 1] - t[i] >= Abs(x[i + 1] - x[i])) f[i + 1] = 1,
				h[i + 1] = Min(h[i + 1], t[i] + Abs(x[i + 1] - x[i]));
			for (int j = i + 2; j <= n; j++)
				if (a[i + 1][j - 1] && judge(i, t[i], i + 1, j, t[i]))
					g[j] = 1;
		}
		if (g[i])
		{
			if (t[i + 1] - t[i - 1] >= Abs(x[i + 1] - x[i - 1]))
				f[i + 1] = 1, h[i + 1] = Min(h[i + 1], Max(t[i],
					t[i - 1] + Abs(x[i + 1] - x[i - 1])));
			for (int j = i + 2; j <= n; j++)
				if (a[i + 1][j - 1] && judge(i - 1, t[i - 1], i + 1, j, t[i]))
					g[j] = 1;
		}
		if (h[i] < 1061109567)
		{
			if (t[i + 1] - h[i] >= Abs(x[i + 1] - x[i])) f[i + 1] = 1,
				h[i + 1] = Min(h[i + 1], Max(t[i], h[i] + Abs(x[i + 1] - x[i])));
			for (int j = i + 2; j <= n; j++)
				if (a[i + 1][j - 1] && judge(i, h[i], i + 1, j, t[i]))
					g[j] = 1;
		}
	}
	return puts(f[n] || g[n] ? "YES" : "NO"), 0;
}