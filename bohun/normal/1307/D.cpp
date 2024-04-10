#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD long double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int nax = 2e5 + 11;

int n, m, k;
int a, b, c;
vector <int> v[nax];

int dis[nax][2];

queue <int> q;

vector <pair<int, int>> s;
int ile[nax];

int main() {
	scanf ("%d%d%d", &n, &m, &k);

	vector <int> special;
	for (int i = 1; i <= k; ++i) {
		scanf ("%d", &a);
		special.pb(a);
	}

	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 2; ++j)
			dis[i][j] = n + 10;

	q.push(1);
	dis[1][0] = 0;
	while (!q.empty()) {
		int ja = q.front();
		q.pop();
		for (auto it : v[ja]) {
			if (dis[it][0] == n + 10) {
				dis[it][0] = dis[ja][0] + 1;
				q.push(it);
			}
		}
	}

	q.push(n);
	dis[n][1] = 0;
	while (!q.empty()) {
		int ja = q.front();
		q.pop();
		for (auto it : v[ja]) {
			if (dis[it][1] == n + 10) {
				dis[it][1] = dis[ja][1] + 1;
				q.push(it);
			}
		}
	}

	int best = -1;

	for (auto it : special) {
		s.pb({dis[it][0], it});
	}

	sort(s.begin(), s.end());
	for (int i = 0; i + 1 < ss(s); ++i) {
		best = max(best, min(dis[n][0], min(dis[s[i].se][0] + 1 + dis[s[i + 1].se][1], dis[s[i].se][1] + 1 + dis[s[i + 1].se][0])));
	}
	printf ("%d", best);

	return 0;
}