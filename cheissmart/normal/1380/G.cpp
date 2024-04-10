#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, M = 998244353;

int inv(int i) {
	if(i == 1) return 1;
	return M - (ll) M / i * inv(M % i) % M; 
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	vi v(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	sort(v.begin() + 1, v.end(), greater<int>());
	for(int i = 1; i <= n; i++)
		v[i] = (v[i] + v[i - 1]) % M;
	int in = inv(n);
	for(int k = 1; k <= n; k++) {
		int ans = 0, cur = 0;
		for(int i = 1; i <= n; i += k) {
			int r = min(n, i + k - 1);
			ans = (ans + ((ll) v[r] - v[i - 1] + M) % M * cur++ % M) % M;
		}
		ans = (ll) ans * in % M;
		cout << ans << " ";
	}
	
}