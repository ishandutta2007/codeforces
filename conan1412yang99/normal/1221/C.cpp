#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define P pair
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int32_t main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int c, m, x;
		cin >> c >> m >> x;
		if(c > m) swap(c, m);
		if(x >= c) {
			cout << c << endl;
			continue;
		}
		c -= x, m -= x;
		if(c <= m/2) {
			cout << c + x << endl;
			continue;
		}
		int l = m - c;
		int r = (c - l);
		l += r / 3 * 2;
		if(r % 3 == 2) l++;
		cout << l + x << endl;
	}	
	
}