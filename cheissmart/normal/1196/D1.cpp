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
	
	int q;
	cin >> q;
	while(q--) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		int r = 0, g = 0, b = 0;
		for(int i = 0; i < k; i++) {
			int nwr = b, nwg = r, nwb = g;
			r = nwr, g = nwg, b = nwb;
			if(s[i] == 'R') r++;
			else if(s[i] == 'G') g++;
			else b++;
		}
		int ans = min({k-r, k-g, k-b});
		for(int i = k; i < n; i++) {
			int nwr = b, nwg = r, nwb = g;
			r = nwr, g = nwg, b = nwb;
			if(s[i] == 'R') r++;
			else if(s[i] == 'G') g++;
			else b++;
			if(s[i-k] == 'R') {
				if(k % 3 == 0) r--;
				if(k % 3 == 1) g--;
				if(k % 3 == 2) b--;
			} else if(s[i-k] == 'G') {
				if((k + 1) % 3 == 0) r--;
				if((k + 1) % 3 == 1) g--;
				if((k + 1) % 3 == 2) b--;
			} else {
				if((k + 2) % 3 == 0) r--;
				if((k + 2) % 3 == 1) g--;
				if((k + 2) % 3 == 2) b--;
			}
		    ans = min({ans, k-r, k-g, k-b});
		}
		cout << ans << endl;
	}	

	
}