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
		int n, k, ans = 0;
		string s;
		cin >> n >> k >> s;
		if(count(ALL(s), '1') == 0) {
			cout << (n + k) / (k + 1) << endl;
			continue;
		}
		int l = 0, r = 0, i, j;
		for(i = 0; i < n; i++){
			if(s[i] == '1') break;
			l++;
		}
		for(j = n - 1; j >= 0; j--){
			if(s[j] == '1') break;
			r++;
		}
		l = max(0, l - k);
		r = max(0, r - k);
		ans += (l + k) / (k + 1)  + (r + k) / (k + 1);
		int cnt = 0;
		for(int tt = i + 1; tt <= j; tt++) {
			if(s[tt] == '1') {
				cnt = max(0, cnt - k - k);
				ans += (cnt + k) / (k + 1);
				cnt = 0;
			}
			else {
				cnt++;
			}
		}
		cout << ans << endl;
	}	
	
}