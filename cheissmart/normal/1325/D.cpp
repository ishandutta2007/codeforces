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
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

void solve(int u, int v) {
	if(u > v) {
		cout << -1 << endl;
		return;
	}
	if((u & 1) != (v & 1)) {
		cout << -1 << endl;
		return;
	}
	if(u == 0 && v == 0) {
		cout << 0 << endl;
		return;
	}
	if(u == v) {
		cout << 1 << '\n' << u << endl;
		return;
	}
	int x = 0, cry = 0, cc = 0, okk = 1;
	for(int i=0;i<62;i++) {
		int sa = u >> i & 1, na = v >> i & 1;
		if(sa == 1) {
			if(na == 0) {
				if(!cry) {
					okk = 0;
					break;
				}
				if(cry == 1) x |= 1LL << cc;
				cry = 2;
			} else {
				if(cry == 2) {
					okk = 0;
					break;
				}
				cry = 0;
			}
		} else {
			if(na == 0) {
				if(cry == 2) {
					okk = 0;
					break;
				}
				cry = 1;
				cc = i;
			} else {
				if(!cry) {
					okk = 0;
					break;
				}
				if(cry == 1) x |= 1LL << cc;
				cry = 1;
				cc = i;
			}
		}
	}
	if(!okk) {
		cout << 3 << endl;
		cout << u << " " << (v - u) / 2 << " " << (v - u) / 2<< endl;
	} else {
		cout << 2 << endl;
		cout << x << " " << v - x << endl;
		assert((x ^ (v - x)) == u);
	}
}

signed main()
{
	IO_OP;
	
	int u, v;
	cin >> u >> v;
	// while(cin >> u >> v) {
		solve(u, v);
	// }

}