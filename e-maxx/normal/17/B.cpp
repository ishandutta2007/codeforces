#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct edge {
	int a, b, c;
};

const int MAXN = 10000;

edge e[MAXN];
int q[MAXN], perm[MAXN];
bool in[MAXN];

bool cmp (int a, int b) {
	return q[a] > q[b];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n, m;
	cin >> n;
	int mv = 0;
	for (int i=0; i<n; ++i) {
		scanf ("%d", &q[i]);
		perm[i] = i;
	}
	sort (perm, perm+n, cmp);
	cin >> m;
	for (int i=0; i<m; ++i) {
		scanf ("%d%d%d", &e[i].a, &e[i].b, &e[i].c);
		--e[i].a, --e[i].b;
	}

	in[perm[0]] = true;
	int ans = 0;
	for (int i=1; i<n; ++i) {
		int v = perm[i];
		int sel = -1;
		for (int j=0; j<m; ++j)
			if (e[j].b == v && in[e[j].a])
				if (sel == -1 || e[j].c < sel)
					sel = e[j].c;
		if (sel == -1) {
			cout << -1;
			return 0;
		}
		in[v] = true;
		ans += sel;
	}

	cout << ans;

}