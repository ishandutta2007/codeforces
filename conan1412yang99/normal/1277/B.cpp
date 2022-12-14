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
		int n;
		cin >> n;
		map<int, int> cnt;
		for(int i=0;i<n;i++) {
			int tt;
			cin >> tt;
			int ttt = 0;
			while(tt % 2 == 0) {
				tt /= 2;
				ttt++;
			}
			cnt[tt] = max(cnt[tt], ttt);
		}
		int ans = 0;
		for(pi p:cnt) ans += p.S;
		cout << ans  << '\n';
	}	
	
}