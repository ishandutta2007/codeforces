#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using namespace std;

int t[1000005], n;
bool used[100005];

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		int mx = -1;
		rep(i, 1, n) {
			scanf ("%d", t + i);
			used[i] = false;
			mx = max(mx, t[i]);
		}
		int s = 0;
		while (s < n) {
			int q = 0;
			rep(i, 1, n)
				if (!used[i]) 
					q = max(q, __gcd(mx, t[i]));
			rep(i, 1, n) 
				if (!used[i] && q == __gcd(mx, t[i])) {
					s++;
					used[i] = true;
					printf ("%d ", t[i]);
				}
			mx = q;
		}
		printf ("\n");
	}
		
	return 0;
}