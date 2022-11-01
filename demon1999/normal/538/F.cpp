
#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const int ma = 1024 * 1024;

int n, ans[300000], pls[300000];
vector<int> a;

int main() {
	iostream::sync_with_stdio(0);
//	freopen("a.in", "r", stdin);
	cin >> n;
	a.resize(n);
	forn (i, n) {
		cin >> a[i];
	}
	int c = 300;
	for (int i = 0; i < n - 1; i++) {
		/*for (int j = 1; j <= 300; j++) {
			if (a[i + 1] < a[i / j]) {
				pls[j]++;
				pls[j + 1]--;
			}
		}*/
		int k, p;
		for (int j = 1; j <= n - 1; ) {
		//	cout << i << " " << j << "\n";
			p = i / j;
			k = 0;
			if (a[i + 1] < a[p]) {
				pls[j]++;
				k = -1;
			}
		//	cout << k << "\n";
			if (p == 0) {
				break;
			}
			if (p == 1) {
				j = i + 1;
				//continue;
			} else {
				j = max(j + 1, (i / p) + 1);

				while (i / (j - 1) < p) {
					j--;
				}
				while (i / j == p)
					j++;
			}
			pls[j] += k;
		}
		ll sum = 0;
	
	}
	for (int i = 1; i <= n - 1; i++) {
		pls[i] += pls[i - 1];
		cout << pls[i] << " ";
	}
}