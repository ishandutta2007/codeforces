#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << (x) << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 3e5 + 7;

int a[N];

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		if(*max_element(a, a+n) == *min_element(a, a+n)) cout << -1 << endl;
		else {
			int mx = *max_element(a, a+n);
			int ans = -1;
			for(int i = 0; i < n; i++) {
				if(i + 1 < n && a[i] == mx && a[i + 1] < mx) {
					ans = i + 1;
					break;
				}
				if(i - 1 >= 0 && a[i] == mx && a[i - 1] < mx) {
					ans = i + 1;
					break;
				}
			}
			cout << ans << endl;
		}
	}

}