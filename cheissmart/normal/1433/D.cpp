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

const int INF = 1e9 + 7, N = 5005;

int a[N];

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		set<int> s;
		for(int i = 1; i <= n; i++) cin >> a[i], s.insert(a[i]);
		if(s.size() == 1) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		int j = -1;
		for(int i = 2; i <= n; i++) {
			if(a[i] != a[1]) {
				j = i;
				cout << 1 << " " << i << endl;
			}
		}
		assert(j != -1);
		for(int i = 2; i <= n; i++) {
			if(a[i] == a[1]) {
				cout << j << " " << i << endl;
			}
		}
	}

}