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
		vi a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		int cnt = 0;
		auto get = [&] (int i) {
			if(i <= 0 || i >= n - 1) return 0;
			if(a[i] > a[i - 1] && a[i] > a[i + 1])
				return 1;
			if(a[i] < a[i - 1] && a[i] < a[i + 1])
				return 1;
			return 0;
		};
		for(int i = 1; i < n - 1; i++)
			cnt += get(i);
		int ans = cnt;
		for(int i = 0; i < n; i++) {
			int tmp = a[i];
			int cans = cnt;
			cans -= get(i);
			cans -= get(i - 1);
			cans -= get(i + 1);
			if(i - 1 >= 0) {
				a[i] = a[i - 1];
				ans = min(ans, cans + get(i - 1) + get(i) + get(i + 1));
			}
			if(i + 1 < n) {
				a[i] = a[i + 1];
				ans = min(ans, cans + get(i - 1) + get(i) + get(i + 1));
			}
			a[i] = tmp;
		}
		cout << ans << endl;
	}


}