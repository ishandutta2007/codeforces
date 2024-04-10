#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int N = 200005;

int n, X, a[N];
unordered_map<LL, int> buc;
int main() {
	ios::sync_with_stdio(0);
	int T; cin >> T;
	while (T--) {
		cin >> n >> X; buc.clear();
		for (int i = 1; i <= n; i++) cin >> a[i], buc[a[i]]++;
		sort(a + 1, a + n + 1);
		int r = n;
		for (int i = 1; i <= n; i++) {
			if (!buc[a[i]]) continue;
			LL tmp = 1LL * a[i] * X;
			if (a[i] % X == 0 && buc[a[i] / X] > 0) {
				buc[a[i] / X]--; buc[a[i]]--; r -= 2;
			} else if (tmp <= 1e9 && buc[tmp] > 0) {
				buc[tmp]--; buc[a[i]]--; r -= 2;
			}
		}
		cout << r << '\n';
	}	
	return 0;
}