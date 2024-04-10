#include<bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

typedef pair<int, int> pt;
typedef long double ld;
typedef long long li;

#define x first
#define y second

int n, m, r, k;

bool good(int x, int y)
{
	return x < n && x >= 0 && y < m && y >= 0;
}

li get(int x, int y)
{
	int lf1 = max(0, x - r + 1);
	int rg1 = min(x, n - r);
	int cnt1 = rg1 - lf1 + 1;
	int lf2 = max(0, y - r + 1);
	int rg2 = min(y, m - r);
	int cnt2 = rg2 - lf2 + 1;
	return cnt1 * 1ll * cnt2;
}

int main()
{
	cin >> n >> m >> r >> k;
	ld ans = 0.0;
	set<pair<li, pt> > q;
	set<pt> used;
	used.insert(make_pair(n / 2, m / 2));
	q.insert(make_pair(get(n / 2, m / 2), make_pair(n / 2, m / 2)));
	while(k)
	{
		--k;
		auto z = *q.rbegin();
		q.erase(z);
		ans += ld(z.x) / ((n - r + 1) * 1ll * (m - r + 1));
		for(int i = 0; i < 4; i++)
		{
			int nx = z.y.x + dx[i];
			int ny = z.y.y + dy[i];
			if (good(nx, ny) && !used.count(make_pair(nx, ny)))
			{
				used.insert(make_pair(nx, ny));
				q.insert(make_pair(get(nx, ny), make_pair(nx, ny)));
			}
		}
	}
	cout << setprecision(15) << fixed;
	cout << ans << endl;
	return 0;
}