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
		string s;
		cin >> n >> s;
		vi v;
		for(int i = 0; i < n; ) {
			int j = i;
			while(i < n && s[j] == s[i]) i++;
			v.PB(i - j);
		}
		if(v.size()%2 == 1 && v.size() > 1) {
			v[0] += v.back();
			v.pop_back();
		}
		if(v.size() == 1) {
			int i = v[0];
			if(i < 3) cout << 0 << endl;
			else {
				cout << (i+2)/3 << endl;
			}
			continue;
		}
		int ans = 0;
		for(int i:v) {
			if(i < 3) continue;
			ans += (i - 2 + 2) / 3;
		}
		cout << ans << endl;
	}	

	
}