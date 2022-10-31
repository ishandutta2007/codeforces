#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

const int N = 1e5+5;
int n, m;
int b[N], g[N];

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;

	ll bsum = 0;
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
		bsum += b[i];
	}
	for(int i = 0; i < m; ++i)
		cin >> g[i];
	sort(b, b+n);
	sort(g, g+m);

	for(int i = 0; i < m; ++i) {
		if(g[i] < b[n-1]) {
			cout << "-1\n";
			return 0;
		}
	}

	ll ans = bsum * m;
	for(int i = 1; i < m; ++i) {
		ans += g[i] - b[n-1];
	}
	if(g[0] != b[n-1])
		ans += g[0] - b[n-2];

	cout << ans << '\n';

}