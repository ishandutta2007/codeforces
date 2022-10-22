#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ss(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;

const int N = 211111;

int n;
char s[N];
vector <int> g[10], f;

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%s", s + 1);
		n = strlen(s + 1);
		rep(i, 0, 9) g[i].clear();
		rep(i, 1, n) g[s[i] - '0'].pb(i);
		int out = 0;
		rep(i, 0, 9) out = max(out, ss(g[i]));
		rep(i, 0, 9)
			rep(j, 0, 9) {
				if (i == j) continue;
				f = {};
				merge(all(g[i]), all(g[j]), back_inserter(f));
				int g = -1, now = 0;
				for (auto u : f) {
					if (s[u] - '0' != g) now++;
					g = s[u] - '0';
				}
				if (now & 1) now--;
				out = max(out, now);
			}
		printf ("%d\n", n - out);	
	}
	return 0;
}