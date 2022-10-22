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

const int nax = 1e5 + 11;

char s[nax];

vector <int> v[26];

int main() {
	scanf ("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
		v[s[i] - 'a'].pb(i);
	LL best = 0;
	for (int i = 0; i < 26; ++i) {
		best = max(best, (LL) ss(v[i]));
		for (int j = 0; j < 26; ++j) {
			if (i == j) {
				int k = ss(v[i]);
				best = max(best, (LL) k * (k - 1) / 2);
				continue;
			}
			LL res = 0;
			int w1 = 0;
			int w2 = 0;
			int z = 0;
			while (w1 < ss(v[i]) || w2 < ss(v[j])) {
				if (w1 == ss(v[i])) {
					z++;
					w2++;
					continue;
				}
				if (w2 == ss(v[j])) {
					res += z;
					w1++;
					continue;
				}
				if (v[i][w1] < v[j][w2]) {
					res += z;
					w1++;
					continue;
				}
				if (v[i][w1] > v[j][w2]) {
					z++;
					w2++;
					continue;
				}
			}
			best = max(best, res);
		}
	}
	printf ("%lld\n", best);



	return 0;
}