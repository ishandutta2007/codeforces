#include <bits/stdc++.h>
#define ll long long
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

const int N = 1011;

int n, a[N], cnt[N];

int mex() {
	int x = 0;
	while (cnt[x]) x++;
	return x;
}

void solve() {
	scanf ("%d", &n);
	rep(i, 0, n) cnt[i] = 0;
	rep(i, 0, n - 1) {
		scanf ("%d", a + i);
		cnt[a[i]]++;
	}
	vector <int> res;
	while (true) {
		int M = mex();
		if (M < n) {
			res.pb(M);
			cnt[a[M]]--;
			a[M] = M;
			cnt[M]++;
		}
		else {
			int q = -1;
			rep(i, 0, n - 1)
				if (a[i] != i)
					q = i;
			if (q == -1) break;
			res.pb(q);
			cnt[a[q]]--;
			a[q] = M;
			cnt[M]++;
		}
	}
	printf ("%d\n", ss(res));
	for (auto it : res)
		printf ("%d ", it + 1);
	printf ("\n");
}			
 
int main() {
	int T;
	scanf ("%d", &T);
	while (T--)
		solve();
	
	return 0;
}