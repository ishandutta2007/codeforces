#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 3003;

ll a[N], p[N];
int cnt[N];

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
		cnt[i] = cnt[i - 1] + (a[i] == 0);
	}
	if(1LL * cnt[n] * k < abs(p[n])) {
		cout << -1 << '\n';
		return 0;
	}
	ll sum = -p[n];
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			int in = cnt[j] - cnt[i - 1];
			int out = cnt[n] - in;
			ll lb = max(-1LL * in * k, sum - 1LL * out * k);
			ll rb = min(1LL * in * k, sum + 1LL * out * k);
			if(lb <= rb) {
				ans = max(ans, abs(p[j] - p[i - 1] + lb));
				ans = max(ans, abs(p[j] - p[i - 1] + rb));
			}
		}
	}
	cout << ans + 1 << '\n';

}