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

map<int, int> cnt;
signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	V<pi> v;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		int mn = INF;
		int p = 0;
		for(char c:s) {
			if(c == '(') p++;
			else p--;
			mn = min(mn, p);
		}
		if(mn == p) {
			cnt[p]++;
		}
		v.EB(p, mn);
	}
	ll ans = 0;
	for(int i=0;i<n;i++) {
		if(v[i].S < 0) continue;
		int p = -v[i].F;
		ans += cnt[p];
	}
	cout << ans << endl;
	
}