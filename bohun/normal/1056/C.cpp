//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int n, m, x[2001], vis[2001], p[2001];

bool end_game() {
	return accumulate(vis + 1, vis + n + 1, 0) == n;
}

void computer();

void human() {
	if (end_game())
		return;

	rep(i, 1, n + 1) 
		if (!vis[i] && x[i] && p[x[i]] <= p[i]) {
			cout << i << endl;
			int _;
			cin >> _;
			vis[i] = vis[_] = 1;
		}

	if (end_game())
		return;

	int id = 0;
	rep(i, 1, n + 1)
		if (!vis[i] && (id == 0 || p[id] < p[i]))
			id = i;

	cout << id << endl;
	vis[id] = 1;
	computer();
}

void computer() {
	if (end_game())
		return;

	int i;
	cin >> i;
	vis[i] = 1;

	if (x[i]) {
		cout << x[i] << endl;
		vis[x[i]] = 1;
		computer();
	}

	human();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	n *= 2;
	rep(i, 1, n + 1)
		cin >> p[i];

	while (m--) {
		int a, b;
		cin >> a >> b;
		x[a] = b;
		x[b] = a;
	}

	int who;
	cin >> who;

	if (who == 1)
		human();
	else
		computer();

	return 0;
}