#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 123;
const int P = 998244353;

int p[123], q[123];
int n;

vector<vector<int>> pat;

void genpattern(int d)
{
	if (d == n)
	{
		pat.push_back(vector<int>(p, p + n));
	}
	else
	{
		for (int x = 0; x <= n; x++)
		{
			p[d] = x;
			genpattern(d + 1);
		}
	}
}
pair<int, int> eval(vector<int> q)
{
	int s = 0, t = 0;
	for (int i = 0; i < n - 2; i++)
		s += q[i] * q[i + 1] * q[i + 2];
	for (int i = 0; i < n; i++)
	{
		t += q[i] * (q[i] - 1) * (q[i] - 2) / 6;
	}
	return {s, t};
}
/*void dfs(int d)
{
	if (d == n)
	{
		vector<int> a;
		for (int i = 0; i < n; i++)
			q[i] = p[i];
		auto eval = [&]() {
			a.push_back(s);
			a.push_back(t);
		};
		eval();
		for (int i = 0; i < n; i++)
		{
			q[i] += 1;
			eval();
		}

		if (s.count(a))
		{
			for (int i = 0; i < n; i++)
				printf("%d ", p[i]);
			puts("");
			for (auto x : s[a])
				printf("%d ", x);
			puts("");
			a.clear();
			for (int i = 0; i < n; i++)
				q[i] = p[i];

			printf("%d ", p[i]);
			puts("");
		}
		s[a] = vector<int>(p, p + n);
	}
	else
	{
		for (int x = 0; x <= 2; x++)
		{
			p[d] = x;
			dfs(d + 1);
		}
	}
}*/

int add[maxN];
vector<int> Tp;
void solvesmall()
{
	genpattern(0);
	for (int i = 0; i <= n; i++)
	{
		int s, t;
		scanf("%d%d", &t, &s);
		/*auto w = eval(Tp);
		s = w.first, t = w.second;*/
		vector<vector<int>> npat;
		for (auto q : pat)
		{
			auto ss = eval(q);
			if (eval(q) == make_pair(s, t))
			{
				npat.push_back(q);
			}
		}
		pat = npat;
		assert(!pat.empty());
		if (pat.size() == 1)
		{
			printf("!");
			for (int i = 0; i < n; i++)
				printf(" %d", pat[0][i] - add[i]);
			printf("\n");
			fflush(stdout);
			return;
		}
		int maxd = -1, maxw = 1 << 30;
		for (int d = 0; d < n; d++)
		{
			map<pair<int, int>, int> cnt;
			for (auto q : pat)
			{
				auto p = q;
				p[d] += 1;
				auto r = eval(p);
				cnt[r] += 1;
			}
			int maxcls = 0;
			for (auto q : cnt)
				maxcls = max(maxcls, q.second);
			if (maxcls <= maxw)
			{
				maxw = maxcls;
				maxd = d;
			}
		}
		add[maxd]++;
		printf("+ %d\n", maxd + 1);
		Tp[maxd] += 1;
		for (auto &p : pat)
			p[maxd]++;
		fflush(stdout);
	}
}
int fs[maxN], ft[maxN], c[maxN], d[maxN];

bool check(int *d)
{
	for (int i = 1; i <= n; i++)
	{
		if (d[i] < 0 || d[i] > n)
			return 0;
	}
	for (int i = 0; i <= n; i++)
	{
		auto w = eval(vector<int>(d + 1, d + n + 1));
		//printf("cc %d %d %d %d\n", w.first, w.second, fs[i], ft[i]);
		if (w != make_pair(fs[i], ft[i]))
			return 0;
		d[i + 1]++;
	}
	return 1;
}

void solvelarge()
{
	auto w = eval(Tp);
	/*fs[0] = w.first;
	ft[0] = w.second;*/
	scanf("%d%d", ft + 0, fs + 0);
	for (int i = 1; i <= n; i++)
	{
		printf("+ %d\n", i);
		Tp[i - 1]++;
		fflush(stdout);
		auto w = eval(Tp);
		scanf("%d%d", ft + i, fs + i);
		/*fs[i] = w.first;
		ft[i] = w.second;*/
	}
	for (int i = 1; i <= n; i++)
	{
		int pt = ft[i] - ft[i - 1];
		if (pt == 0)
		{
			c[i] = -1;
		}
		else
		{
			for (int x = 1; x <= n; x++)
				if (x * (x + 1) / 2 == pt)
					c[i] = x + 1;
		}
	}
	for (int p1 = (c[n] == -1) ? 0 : c[n]; p1 <= ((c[n] == -1) ? 1 : c[n]); p1++)
		for (int p2 = (c[n - 1] == -1) ? 0 : c[n - 1]; p2 <= ((c[n - 1] == -1) ? 1 : c[n - 1]); p2++)
			for (int p3 = ((c[n - 2] == -1) ? 0 : c[n - 2]); p3 <= ((c[n - 2] == -1) ? 1 : c[n - 2]); p3++)
			{
				d[n + 1] = 0;
				d[n] = p1;
				d[n - 1] = p2;
				d[n - 2] = p3;
				//printf("gg %d %d %d %d\n", p1, p2, p3, c[n - 2]);
				bool valid = 1;
				for (int i = n - 1; i >= 3; i--)
				{
					int ps = fs[i] - fs[i - 1];
					// (d[i - 2] + 1) * (d[i - 1] + 1) + (d[i - 1] + 1) * d[i + 1] + d[i + 1] * d[i + 2];
					int w = (d[i - 1] + 1) * d[i + 1] + d[i + 1] * d[i + 2];
					//printf("%d %d %d\n", ps, w, (d[i - 1] + 1));
					if (ps <= w || (ps - w) % (d[i - 1] + 1) != 0)
					{
						valid = 0;
						break;
					}
					d[i - 2] = (ps - w) / (d[i - 1] + 1) - 1;
					//printf("st %d %d\n", i - 2, d[i - 2]);
				}
				if (valid && check(d))
				{
					printf("!");
					for (int i = 1; i <= n; i++)
					{
						printf(" %d", d[i] - 1);
					}
					puts("");
					fflush(stdout);
				}
			}
}
int main()
{
	scanf("%d", &n);
	Tp = vector<int>(n, 0);
	if (n <= 5)
	{
		solvesmall();
	}
	else
	{
		solvelarge();
	}
}