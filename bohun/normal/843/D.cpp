#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e5 + 100;
const LL INF = 1e18;
const int inf = 1e9;

int n, m, q, a, b, c;

int cost[N];
LL t[N];

vector <pair<int, int>> g[N];

set <pair<LL, int>> s;

void dij() {
	rep(i, 1, n) t[i] = INF;
	t[1] = 0;
	s.insert({0, 1});
	while (ss(s)) {
		int v = (*s.begin()).se;
		s.erase(s.begin());
		for (auto it : g[v]) {
			if (t[v] + cost[it.se] < t[it.fi]) {
				s.erase({t[it.fi], it.fi});
				s.insert({t[it.fi] = t[v] + cost[it.se], it.fi});
			}
		}
	}
}

queue <int> qq[N];
int del[N];
bool odw[N];

LL delta;

void dij2(int e) {
	rep(i, 1, n) {
		del[i] = inf;
		odw[i] = 0;
	}
	del[1] = 0;
	qq[0].push(1);
	int j = 0;
	while (j <= e) {
		while (j <= e && !ss(qq[j])) j++;
		if (j == e + 1) break;
		int v = qq[j].front();
		qq[j].pop();
		if (odw[v]) continue;
		odw[v] = 1;
		for (auto it : g[v]) {
			delta = t[v] + del[v] + cost[it.se] - t[it.fi];
			if (delta <= e && delta < del[it.fi]) {
				qq[delta].push(it.fi);
				del[it.fi] = delta;
			}
		}
	}
	rep(i, 1, n) t[i] += del[i];
} 
	
int main() {	
	scanf ("%d%d%d", &n, &m, &q);
	rep(i, 1, m) {
		scanf ("%d%d%d", &a, &b, &c);
		cost[i] = c;
		g[a].pb({b, i});
	}
	dij();
	while (q--) {
		scanf ("%d%d", &a, &b);
		if (a == 1) {
			if (t[b] < INF)
				printf ("%lld\n", t[b]);
			else 
				printf ("-1\n");
		}
		else {
			rep(i, 1, b) {
				scanf ("%d", &c);
				cost[c]++;
			}
			dij2(b);
		}		
	}
		
	
	return 0;
}