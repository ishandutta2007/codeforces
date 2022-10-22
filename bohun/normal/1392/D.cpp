#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using ll = long long;

using namespace std;

int n;
char s[200005];
vector <pair<int, int>> v;

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		v.clear();
		scanf ("%d%s", &n, s + 1);
		int co = -1, ile = 0;
		for (int i = 1; i <= n; ++i) {
			int c = (s[i] == 'L' ? 0 : 1);
			if (c != co) {
				if (ile) v.pb({co, ile});
				co = c; ile = 1;
			}
			else ile++;
		}
		v.pb({co, ile});
		if ((int) v.size() == 1) {
			printf ("%d\n", 1 + (n - 1) / 3);
			continue;
		}
			
		if (v[0].fi == v.back().fi) {
			v[0].se += v.back().se;
			v.pop_back();
		}
		int out = 0;
		for (auto it : v) 
			out += max(0, it.se / 3);
		printf ("%d\n", out);
	}																			
	return 0;
}