#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;

const int N = 2e5 + 500;

int T, n, k;
char s[N];
vector <int> gaps;

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &n, &k);
		scanf ("%s", s + 1);
		gaps.clear();
		int sum = 0;
		rep(i, 1, n)
			sum += s[i] == 'L';
		if (k >= sum) {
			printf ("%d\n", 2 * n - 1);
			continue;
		}
		if (sum == n) {
			printf ("%d\n", max(0, 2 * k - 1));
			continue;
		}
		//~ cat(sum);
		int last = 0, comp = 0;
		rep(i, 1, n) {
			if (s[i] == 'W' && (i == 1 || s[i - 1] == 'L')) comp++;
			if (s[i] == 'W' && last > 0) 
				gaps.pb(i - last - 1);
			if (s[i] == 'W') last = i;
		}
		int K = k;
		//~ cat(comp);
		sort(all(gaps));
		for (auto x : gaps) {
			if (k >= x && x > 0) {
				//~ cat(x);
				comp--;
				k -= x;
			}
		}
		printf ("%d\n", 2 * (n - sum + K) - comp);
	}
	
	return 0;
}