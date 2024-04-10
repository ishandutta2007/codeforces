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

const int INF = 1e9 + 7, M = 998244353;

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vi a(n), b(k), no(n);
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			x--;
			a[x] = i;
		}
		for(int i = 0; i < k; i++) {
			cin >> b[i];
			b[i]--;
			b[i] = a[b[i]];
			no[b[i]] = 1;
		}
		set<int> s;
		for(int i = 0; i < n; i++) s.insert(i);
		int ans = 1;
		for(int i = 0; i < k; i++) {
			int x = b[i];
			auto it = s.find(x);
			assert(it != s.end());
			bool l = 0, r = 0;
			if(it != s.begin() && !no[*prev(it)]) l = 1;
			if(next(it) != s.end() && !no[*next(it)]) r = 1;
			if(l && r) {
				ans = ans * 2 % M;
			}
			if(l == 0 && r == 0) {
				ans = 0;
				break;
			}
			if(l) s.erase(prev(it));
			else s.erase(next(it));
			no[x] = 0;
		}
		cout << ans << endl;
	}

}