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

int n, k;

int qry(int l, int r) {
	cout << "? " << r - l + 1 << " ";
	for(int i = l; i<= r; i++) cout << i << " ";
	cout << endl;
	int ret;
	cin >> ret;
	return ret;
}

int qry(vi& v) {
	cout << "? " << n - v.size() << " ";
	for(int i = 1; i <= n; i++) {
		if(find(ALL(v), i) == v.end()) cout << i << " ";
	}
	int ret;
	cin >> ret;
	return ret;
}

void solve() {
	cin >> n >> k;
	vi by(n + 1, -1);
	V<vi> v;
	for(int i = 0; i < k; i++) {
		vi tt;
		int c;
		cin >> c;
		for(int j = 0; j < c; j++) {
			int ttt;
			cin >> ttt;
			tt.PB(ttt);
			by[ttt] = i;
		}
		v.PB(tt);
	}
	int mx = qry(1, n);
	int j = 0;
	for(int i = 9; i >= 0; i--) {
		if(j + (1 << i) <= n && qry(1, j + (1 << i)) < mx) {
			j += (1 << i);
		}
	}
	j++;
	vi ans(k, mx);
	if(by[j] != -1) {
		ans[by[j]] = qry(v[by[j]]);
	}
	cout << "! ";
	for(int i:ans) cout << i << " ";
	cout << endl; 
	string ok;
	cin >> ok;
}


signed main()
{
	
	int t;
	cin >> t;
	while(t--) solve();	
	
}