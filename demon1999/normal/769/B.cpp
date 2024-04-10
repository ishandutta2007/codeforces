#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define zhfs main
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 1; i <= n; i++)
int can[107];
int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	set<pair<int, int> > have;
	for (int i = 1; i <= n; i++)
	{
		cin >> can[i];
		if (i != 1)
		{
			have.insert(make_pair(can[i], i));
		}
	}
	queue<int> q;
	vector<pair<int, int> > res;
	q.push(1);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 1; i <= can[v]; i++)
		{
			if (have.empty()) break;
			pair<int, int> tmp = *have.rbegin();
			have.erase(tmp);
			res.push_back(make_pair(v, tmp.se));
			q.push(tmp.se);
		}
	}
	if (!have.empty())
	{
		cout << -1 << endl;
	}
	else
	{
		cout << res.size() << endl;
		for (int i = 0; i < (int)res.size(); i++)
		{
			cout << res[i].fi << " " << res[i].se << endl;
		}
	}
}