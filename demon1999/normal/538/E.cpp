#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const int ma = 1024 * 1024;

int n;
vector<int> e[300000];

int dfs(int nu, int k, int h) {
	int sum = 0;
	if (sz(e[nu]) == 0) {
		re 1;
	}
	if (h == 0) {
		sum = ma;
		for (int v : e[nu])
			sum = min(sum, dfs(v, k, 1 - h));
	} else {
		for (int v : e[nu])
			sum += dfs(v, k, 1 - h);
	}
	re sum;
}

int dfs1(int nu, int k, int h) {
	int sum = 0;
	if (sz(e[nu]) == 0) {
		re 1;
	}
	if (h == 0) {
		for (int v : e[nu])
			sum += dfs1(v, k, 1 - h);
	} else {
		sum = ma;
		for (int v : e[nu])
			sum = min(sum, dfs1(v, k, 1 - h));
	}
	re sum;
}
int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n;
	if (n == 1) {
		cout << 1 << " " << 1 << "\n";
		re 0;
	}
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		e[a].push_back(b);
	}
	int m = 0;
	forn (i, n) {
		if (sz(e[i]) == 0 && i)
			m++;
	}
	int lan = 1, ran = m + 1;
	while (ran - lan > 1) {
		int mid = (lan + ran) / 2;
		if (dfs(0, mid, 0) <= m - mid + 1)
			lan = mid;
		else
			ran = mid;
	}
	cout << lan << " ";
	lan = 0;
	ran = m + 1;
	while (ran - lan > 1) {
		int mid = (lan + ran) / 2;
		if (dfs1(0, mid, 0) <= mid)
			ran = mid;
		else
			lan = mid;
	}
	cout << ran << "\n";
}