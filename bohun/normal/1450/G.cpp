#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()

using ll = long long;
using namespace std;

const int N = 1 << 20;

int n, m, a, b, S[N], l[N], r[N], f[N];
char s[5005], t[30];
map<char, int> mp;

int id(char c) {
	if (!mp.count(c)) {
		t[m] = c;
		mp[c] = m++;
	}
	return mp[c];
}		

int main() {
	scanf("%d%d%d%s", &n, &a, &b, s + 1);
	rep(i, 0, N - 1) l[i] = n + 1;
	rep(i, 1, n) {
		int x = id(s[i]);
		S[1 << x]++;
		l[1 << x] = min(l[1 << x], i);
		r[1 << x] = i;
	}
	rep(j, 1, (1 << m) - 1)
		rep(i, 0, m - 1) if (j >> i & 1) {
			S[j] = S[j ^ (1 << i)] + S[1 << i];
			l[j] = min(l[j ^ (1 << i)], l[1 << i]);
			r[j] = max(r[j ^ (1 << i)], r[1 << i]);
		}
	f[0] = 1;
	rep(j, 1, (1 << m) - 1) {
		int M = 0;
		rep(i, 0, m - 1) if (j >> i & 1) {
			M += 1 << i;
			f[j] |= f[j ^ (1 << i)] && a * (r[j] - l[j] + 1) <= b * S[j];
			f[j] |= f[j ^ M] && f[M];
		}
	}
	set<char> T;
	rep(i, 0, m - 1) if (f[(1 << m) - 1 - (1 << i)]) T.insert(t[i]);
	printf("%d", sz(T));
	for (auto i : T) printf(" %c", i);
	return 0;
}