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

signed main()
{
	// IO_OP;
	
	int a[4];
	cin >> a[1] >> a[2] >> a[3];
	cout << "First" << endl;
	int mv = -1;
	while(mv) {
		vi v({a[1], a[2], a[3]});
		sort(ALL(v));
		if(v[2] - v[1] == v[1] - v[0] && mv != -1 && a[mv] == v[2]) {
			int val = v[2] - v[1];
			if(val == 0) val = 5979;
			cout << val << endl;
			cin >> mv;
		}
		else {
			int val = 2 * v[2] - v[0] - v[1];
			if(val == 0) val = 5979;
			cout << val << endl;
			cin >> mv;
			a[mv] += val;
		}
	}
	
}