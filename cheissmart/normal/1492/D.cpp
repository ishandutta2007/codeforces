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

signed main()
{
	IO_OP;

	int a, b, k;
	cin >> a >> b >> k;
	if(b == 1 || a == 0 || k == 0) {
		if(k) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
			string s = string(b, '1') + string(a, '0');
			cout << s << '\n';
			cout << s << '\n';
		}
		return 0;
	}
	if(k <= b - 2 + a - 1 + 1) {
		cout << "Yes\n";
		b -= 2;
		a -= 1;
		k -= 1;
		int l = a + b - k;
		string s = string(b, '1') + string(a, '0');
		string sl = s.substr(0, l), sr = s.substr(l);
		cout << 1 << sl << 1 << sr << 0 << '\n';
		cout << 1 << sl << 0 << sr << 1 << '\n';
	} else {
		cout << "No\n";
	}

}