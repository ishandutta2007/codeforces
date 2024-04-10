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

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N], c[N];
int n, k;

bool ok(int m) {
	int aa = 0, bb = 1, x = m, y = 0;
	for(int i = k; i >= 1; i--) {
		aa += a[i] / m;
		bb += a[i] / m;
		int more = a[i] % m;
		int del = min(more, x);
		x -= del;
		y += del;
		more -= del;
		if(x == 0) {
			x = y;
			y = 0;
			aa = bb;
			bb = bb + 1;
			y += more;
			x -= more;
		}
		if(y) {
			if(bb > c[i]) return false;
		} else {
			if(aa > c[i]) return false;
		}
	}
	return true;
}

vi G[N];

signed main()
{
	IO_OP;
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a[t]++;
	}
	for(int i = 1; i <= k; i++) cin >> c[i];	
	int l = 1, r = n;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m)) r = m - 1;
		else l = m + 1;
	}
	cout << l << endl;
	int cnt = 0;
	for(int i = k; i >= 1; i--) {
		int have = a[i];
		while(have--) {
			G[(cnt++)%l].PB(i);
		}
	}
	for(int i = 0; i < l; i++) {
		cout << G[i].size() << " ";
		sort(ALL(G[i]));
		for(int e:G[i]) cout << e << " ";
		cout << endl;
	}
}