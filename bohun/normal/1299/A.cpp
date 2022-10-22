#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int nax = 1e5 + 111;

int n;
int a[nax];
int bit[30];

int main() {
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", a + i);
		for (int k = 0; k < 30; ++k)
			if (((a[i] >> k) & 1)) bit[k]++;
	}

	pair <int, int> best = {-1, -1};
	for (int i = 1; i <= n; ++i) {
		int res = 0;
		for (int j = 0; j < 30; ++j)
			if (((a[i] >> j) & 1) == 1 && bit[j] == 1)
				res += 1 << j;
		best = max(best, {res, i});
	}

	swap(a[1], a[best.se]);
	for (int i = 1; i <= n; ++i)
		printf ("%d ", a[i]);



	return 0;
}