#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;

const int nax = 2e5 + 111;

int n;
int a[nax], t[nax];

multiset <int> s;

LL sum;

LL ans;

vector <int> v;

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) scanf ("%d", &a[i]);
	rep(i, 1, n) scanf ("%d", &t[i]);
	rep(i, 1, n) v.pb(i);
	
	sort(v.begin(), v.end(), [&](int x, int y) {
		return a[x] < a[y];
	});
	
	int last = 0;
	for (int i = 0; i < n;) {
		int j = i;
		int czas = a[v[i]] - last;
		while (czas > 0 && ss(s)) {
			sum -= *(--s.end());
			s.erase(--s.end());
			ans += sum;
			czas--;
		}
		while (j < n && a[v[i]] == a[v[j]]) {
			sum += t[v[j]];
			s.insert(t[v[j]]);
			j++;
		}
		last = a[v[i]];
		i = j;
	}
	while (ss(s)) {
		sum -= *(--s.end());
		s.erase(--s.end());
		ans += sum;
	}
	printf ("%lld", ans);
	
	return 0;
}