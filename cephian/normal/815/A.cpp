#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
struct __test {} test;
using namespace std;
template <typename T>const __test &operator<<(const __test& d,
const T& v) {return cerr << "\033[31m" << v << "\033[0m",d;}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


int g[105][105],mn[105];
int n,m;

vector<string> a;
vector<int> b;

void do_rows() {
	for(int i = 0; i < n; ++i) {
		int mn = 1e9;
		for(int j = 0; j < m; ++j)
			mn = min(mn,g[i][j]);
		for(int j = 0; j < mn; ++j) {
			a.pb("row");
			b.pb(i+1);
		}
		for(int j = 0; j < m; ++j)
			g[i][j] -= mn;
	}
}

void do_cols() {
	for(int j = 0; j < m; ++j) {
		int mn = 1e9;
		for(int i = 0; i < n; ++i)
			mn = min(mn,g[i][j]);
		for(int i = 0; i < mn; ++i) {
			a.pb("col");
			b.pb(j+1);
		}
		for(int i = 0; i < n; ++i)
			g[i][j] -= mn;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> g[i][j];
		}
	}
	if(m > n) {
		do_rows();
		do_cols();
	} else {
		do_cols();
		do_rows();
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(g[i][j] != 0) {
				cout << "-1\n";
				return 0;
			}
		}
	}
	test << "whats up\n";
	cout << a.size() << "\n";
	for(int i = 0; i < a.size(); ++i) {
		cout << a[i] << " " << b[i] << "\n";
	}

	return 0;
}