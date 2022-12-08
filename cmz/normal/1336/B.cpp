#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 
using namespace std;
vector<int> u[3];
ll sqr(int a) {
	return 1ll * a * a;
}
ll cal(int a, int b, int c) {
	return sqr(a - b) + sqr(b - c) + sqr(c - a);
}
int main() {
//	freopen(".in ", "r", stdin);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 3; j++) {
			int s;
			scanf("%d", &s);
			u[j].resize(s);
		}
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < u[j].size(); k++)
				scanf("%d", &u[j][k]);
		for (int j = 0; j < 3; j++)
			sort(u[j].begin(), u[j].end());
		ll ans = 4e18;
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++) {
				if (k == j) continue;
				int l = 3 - j - k;
				for (int s = 0; s < u[j].size(); s++) {
					int na = u[j][s];
					int p1 = lower_bound(u[k].begin(), u[k].end(), na) - u[k].begin();
					int p2 = lower_bound(u[l].begin(), u[l].end(), na) - u[l].begin();
					for (int m1 = max(0, p1 - 1); m1 < min(p1 + 2, (int)u[k].size()); m1++)
						for (int m2 = max(0, p2 - 1); m2 < min(p2 + 2, (int)u[l].size()); m2++) {
							ans = min(ans, cal(na, u[k][m1], u[l][m2]));
						}
				}
				break;
			}
		cout << ans << endl;
	}
	return 0;
}