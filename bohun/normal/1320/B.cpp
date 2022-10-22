#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

const int nax = 2e5 + 111;

int n, m;
int a, b;
vector <int> v[nax], vv[nax];

int k;
int e[nax];

int dis[nax];

queue <int> q;

int d[nax];

int main() {
	scanf ("%d%d", &n, &m);
	rep(i, 1, m) {
		scanf ("%d%d", &a, &b);
		v[a].pb(b);
		vv[b].pb(a);
	}
	scanf ("%d", &k);
	rep(i, 1, k)
		scanf ("%d",e + i);

	rep(i, 1, n) dis[i] = n + 10;
	dis[e[k]] = 0;
	q.push(e[k]);

	while (ss(q)) {
		int ja = q.front();
		q.pop();

		for (auto it : vv[ja])
			if (dis[it] > dis[ja] + 1) {
				dis[it] = dis[ja] + 1;
				q.push(it);
			}
	}

	rep(i, 1, n) {
		for (auto it : v[i])
			d[i] += (dis[it] + 1 == dis[i]);
	}

	int Min = 0, Max = 0;

	rep(i, 1, k - 1) {
		int ja = e[i];
		int on = e[i + 1];

		if (dis[ja] != dis[on] + 1)
			Min++;
		if (d[ja] > 1) Max++;
		if (d[ja] == 1 && (dis[on] + 1 != dis[ja])) Max++;
	}

	printf ("%d %d\n", Min, Max);

	return 0;
}