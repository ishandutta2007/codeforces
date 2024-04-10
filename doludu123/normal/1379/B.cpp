#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, K = 350;

void solve() {
	int l, r;
	lli m;
	cin >> l >> r >> m;
	/*
	n * a = m - x
	l - r <= x <= r - l
	n = (m - x) / a
	(m - x) % a == 0
	(m - x) % (l ~ r) == 0
	m % i == x % i
	*/
	fop (i,l,r + 1) {
		lli a = m % i;
		if (l - r <= a && a <= r - l) {
			lli x, y;
			if (a < 0) {
				x = l, y = l - a;
			} else {
				x = r, y = r - a;
			}
			if ((m - x + y) != 0) {
				cout << i << ' ' << x << ' ' << y << endl; 
				break;
			}
		}
		a -= i;
		if (l - r <= a && a <= r - l) {
			lli x, y;
			if (a < 0) {
				x = l, y = l - a;
			} else {
				x = r, y = r - a;
			}
			if ((m - x + y) != 0) {
				cout << i << ' ' << x << ' ' << y << endl; 
				break;
			}
		}
	}
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ta;
    cin >> ta;
    while (ta--) {
    	solve();
	}
}