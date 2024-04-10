// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

void fail()
{
	cout << "-1" << endl;
	exit(0);
}

int a[2][2010][2010], b[2010];
int used[4010], ans[4010];
vector<pair<int, int> > mas[4010];

void dfs(int v, int q)
{
	ans[v] = q;
	used[v] = 1;
	for (auto p: mas[v])
	{
		int u = p.first;
		if (ans[u] == (ans[v] ^ p.second ^ 1))
			fail();
		if (used[u] == 0)
			dfs(u, ans[v] ^ p.second);
	}
}

void solve() {
	int n;
	cin >> n;
	for (int q = 0; q < 2; q++)
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < n; j++)
				a[q][i][j] = s[j] - '0';
		}
	string s;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		b[i] = s[i] - '0';
	}
	fill(ans, ans + 2 * n, 2);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i] && b[j])
			{
				mas[i].push_back({n + j, a[0][i][j] != a[1][i][j]});
				mas[n + j].push_back({i, a[0][i][j] != a[1][i][j]});
			}
			else if (b[i])
			{
				if (ans[n + j] == (((int)(a[0][i][j] != a[1][i][j])) ^ 1))
					fail();
				ans[n + j] = (a[0][i][j] != a[1][i][j]);
			}
			else if (b[j])
			{
				if (ans[i] == (((int)(a[0][i][j] != a[1][i][j])) ^ 1))
					fail();
				ans[i] = (a[0][i][j] != a[1][i][j]);
			}
			else if (a[0][i][j] != a[1][i][j])
				fail();
		}
	}
	for (int i = 0; i < 2 * n; i++)
		if (used[i] == 0 && ans[i] != 2)
			dfs(i, ans[i]);
	for (int i = 0; i < 2 * n; i++)
		if (used[i] == 0)
			dfs(i, 1);
	vector<int> answer;
	for (int i = 0; i < 2 * n; i++)
		if (ans[i] == 1)
			answer.push_back(i);
	cout << answer.size() << "\n";
	for (int i: answer)
	{
		if (i < n)
			cout << "row " << i << "\n";
		else
			cout << "col " << i - n << "\n";
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}