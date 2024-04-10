#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int n;
int a[20000];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 1, n + 1)
			cin >> a[i];
		int p = n;
		while (p > 0 && a[p] == 1)
			p--;
		rep(i, 1, p + 1)
			cout << i << " ";
		cout << n + 1 << " ";
		rep(i, p + 1, n + 1)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}