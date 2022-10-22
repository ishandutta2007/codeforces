#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 4e5 + 10;

int n, m, q;
set<pair<pair<int, int>, pair<int, int>>>	vis;
map<pair<pair<int, int>, pair<int, int>>, ll>	d;

ll get(int x, int y){
	ll ret = 3e18;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (abs(i) + abs(j) == 2){
				int dy = i, dx = j;
				int aa, bb;
				if (dy < 0)	aa = y;
				else aa = n - y;

				if (dx < 0)	bb = x;
				else bb = m - x;

				int ty = y, tx = x;
				aa = min(aa, bb);
				y += dy * aa, x += dx * aa;
				if (y == n || y == 0)	dy *= -1;
				if (x == m || x == 0)	dx *= -1;

				if (y != n && y != 0 || x != 0 && x != m){
					if (y == n || y == 0)	dx *= -1;
					if (x == m || x == 0)	dy *= -1;
				}
				if (vis.count({{x, y}, {dx, dy}}))
					ret = min(ret, d[{{x, y}, {dx, dy}}] + aa);

				y = ty, x = tx;
			}
	if (ret > 2e18)	ret = -1;
	return ret;
}

int main(){
	scanf("%d %d %d", &n, &m, &q);swap(n, m);
	{
		ll cur = 0;
		int x = 0, y = 0;
		int dx = 1, dy = 1;
		while (vis.count({{x, y}, {dx, dy}}) == 0){
			vis.insert({{x, y}, {dx, dy}});
			d[{{x, y}, {dx, dy}}] = cur;

			int aa, bb;
			if (dy < 0)	aa = y;
			else aa = n - y;

			if (dx < 0)	bb = x;
			else bb = m - x;

			aa = min(aa, bb);
			y += dy * aa, x += dx * aa;
			if (y == n || y == 0)	dy *= -1;
			if (x == m || x == 0)	dx *= -1;
			cur += aa;
		}
	}

	while (q--){
		int x, y;	scanf("%d %d", &x, &y);
		printf("%lld\n", get(x, y));
	}
	return 0;
}