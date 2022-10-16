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

const int INF = 1e9 + 7;
int n;

string add(string s) {
	for(int i = n - 1; i >= 0; i--) {
		if(s[i] == '0') {
			s[i] = '1';
			break;
		} else {
			s[i] = '0';
		}
	}
	return s;
}

signed main()
{
	IO_OP;
	
	string l, r;
	cin >> n >> l >> r;
	if(l == r) {
		cout << r << '\n';
		return 0;
	}
	if(l[0] != r[0]) {
		cout << string(n, '1') << '\n';
		return 0;
	}
	// (r - l + 1) must be odd
	if(r.back() == '1') {
		cout << r << '\n';		
	} else {
		if(add(l) != r) cout << add(r) << '\n';
		else cout << r << '\n';
	}
}