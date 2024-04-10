#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define lc ind<<1
#define rc ind<<1|1
const int MN = 5e5+3, MK = 1001, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) {
		int n;
		scanf ("%d",&n);
		vector<int> a(n), b(n);
		for (auto &au : a) scanf ("%d",&au);
		for (auto &au : b) scanf ("%d",&au);
		bool goup = 0, godown = 0;
		for (int i = 0; i < n; i++) {
			if ((a[i] < b[i] && !goup) || (a[i] > b[i] && !godown)) {
				printf ("NO\n");
				goto fin;
			}
			if (a[i] < 0) godown = 1;
			if (a[i] > 0) goup = 1;
		}
		printf ("YES\n");
		fin:;
	}
    return 0;
}