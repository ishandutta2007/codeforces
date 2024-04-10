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

int ask(int l, int r) {
	cout << "? " << l << " " << r << endl;
	int res;
	cin >> res;
	return res;
}

void ans(int x) {
	cout << "! " << x << endl;
	exit(0);
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	int mx2 = ask(1, n);
	if(mx2 == n || (mx2 != 1 && ask(1, mx2) == mx2)) { // mx < mx2
		int l = mx2;
		for(int j = 19; j >= 0; j--) {
			if(l - (1 << j) >= 1 && ask(l - (1 << j), mx2) != mx2)
				l -= 1 << j;
		}
		assert(l >= 2);
		ans(l - 1);
	} else { // mx > mx2
		int r = mx2;
		for(int j = 19; j >= 0; j--)
			if(r + (1 << j) <= n && ask(mx2, r + (1 << j)) != mx2)
				r += 1 << j;
		assert(r < n);
		ans(r + 1);
	}

}