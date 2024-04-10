#include <bits/stdc++.h>
#define ll long long
#define ld long double
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

const int N = 2e5 + 101;

int n, m;
char s[N], t[N];
int cnt[26], b[N];
bool found[N];

void solve() {
	scanf ("%s", s + 1);
	n = strlen(s + 1);
	scanf ("%d", &m);
	rep(i, 1, m)
		scanf ("%d", b + i);
	rep(i, 1, m)
		found[i] = false;
	rep(i, 0, 25) cnt[i] = 0;
	rep(i, 1, n) cnt[s[i] - 'a']++;
	int R = 25;
	while (true) {
		bool all = true;
		rep(i, 1, m)
			all &= found[i] == true;
		if (all) {
			rep(i, 1, m)
				printf ("%c", t[i]);
			printf ("\n");
			return;
		}
		vector <int> now;
		rep(i, 1, m) {
			if (!found[i]) {
				int s = 0;
				rep(j, 1, m)
					if (found[j])
						s += abs(i - j);
				if (s == b[i]) {
					now.pb(i);
				}
			}
		}
		while (cnt[R] < ss(now)) R--;
		assert(R >= 0);
		for (auto it : now) {
			found[it] = true;
			t[it] = (char) ('a' + R);
		}
		R--;
	}
	assert(0);
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) solve();	
	return 0;
}