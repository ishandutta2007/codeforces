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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		multiset<int> a, b;
		for(int i = 0; i < n; i++) {
			int tt;
			cin >> tt ;
			a.insert(tt);
		}
		for(int i = 0; i < n; i++) {
			int tt;
			cin >> tt ;
			b.insert(tt);
		}
		for(int i = 0; i < k; i++) {
			if(*a.begin() < *b.rbegin()) {
				int x = *a.begin(), y =  *b.rbegin();
				a.erase(a.lower_bound(x));
				b.erase(b.lower_bound(y));
				a.insert(y);
				b.insert(x);
			}
		}
		int ans = 0;
		for(int i:a) ans += i;
		cout << ans << endl;
	}	
	
}