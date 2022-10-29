#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


const int MAXN = 19;

int n;
bool g[MAXN][MAXN];

long long d[1<<MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int m;
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a][b] = g[b][a] = true;
	}

	long long ans = 0;
	for (int msk=0; msk<(1<<n); ++msk) {
		int fs = -1;
		for (int i=0; i<n; ++i)
			if (msk & (1<<i)) {
				fs = i;
				break;
			}

		for (int v=0; v<n; ++v) {
			if (msk == (1<<v))
				d[msk][v] = 1;
			long long my = d[msk][v];
			if (my) {
				if (g[v][fs] && v != fs && msk != (1<<v) + (1<<fs))
					ans += my;
				for (int to=fs+1; to<n; ++to)
					if (! (msk & (1<<to)) && g[v][to])
						d[msk+(1<<to)][to] += my;
			}
		}
	}

	cout << ans / 2;

}