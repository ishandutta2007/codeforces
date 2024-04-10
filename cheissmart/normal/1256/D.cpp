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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int n, k;
string s;

pair<bool, int> ok(int m) {
	int r = 0, ct = 0;
	for(int i=0;i<m;i++) {
		if(s[i] == '0') r += ct;
		else ct++;
	}
	return {r <= k, k - r};
}

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {;
		cin >> n >> k >> s;
		int l = 0, r = n;
		while(l <= r) {
			int m = (l + r) / 2;
			if(ok(m).F) l = m + 1;
			else r = m - 1;
		}
		k = ok(r).S;
		sort(s.begin(), s.begin()+r);
		for(int i=r;i<n;i++) {
			if(s[i] == '0') {
				while(k && i > 0 && s[i-1] == '1') {
					swap(s[i], s[i-1]);
					i--;
					k--;
				}
				break;
			}
		}
		cout << s << endl;
	}	
	
}