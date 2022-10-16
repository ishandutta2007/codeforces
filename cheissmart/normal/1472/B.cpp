#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int cnt[3] = {0, 0, 0};
		int tot = 0;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			tot += x;
			cnt[x]++;
		}
		if(tot & 1) {
			cout << "NO" << endl;
			continue;
		}
		tot /= 2;
		bool yes = 0;
		for(int i = 0; i <= cnt[2]; i++) {
			int now = i * 2;
			if(now > tot) continue;
			int need = tot - now;
			if(need <= cnt[1]) {
				yes = 1;
				break;
			}
		}
		cout << (yes ? "YES" : "NO") << endl;
	}
	
}