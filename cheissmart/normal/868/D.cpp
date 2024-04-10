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

struct T {
	set<string> tt;
	string prefix, suffix;
	bool all;
	T(string s = "") {
		int n = s.size();
		for(int i = 0; i < n; i++)
			for(int j = i; j < n && j - i + 1 <= 9; j++)
				tt.insert(s.substr(i, j - i + 1));
		if(n <= 9) {
			prefix = suffix = s;
			all = true;
		} else {
			prefix = s.substr(0, 9);
			suffix = s.substr(n - 9);
			all = false;
		}
	}
	int get() {
		int ans = 0;
		for(int len = 1; len <= 9; len++) {
			bool ok = true;
			for(int i = 0; i < (1 << len); i++) {
				string s;
				for(int j = 0; j < len; j++) {
					if(i >> j & 1) s += '1';
					else s += '0';
				}
				if(tt.count(s) == 0) {
					ok = false;
					break;
				}
			}
			if(!ok) break;
			else ans = len;
		}
		return ans;
	}
} a[202];

T add(T a, T b) {
	if(a.all && b.all) return T(a.prefix + b.prefix);
	T d; 
	d.all = false;
	T c = T(a.suffix + b.prefix);
	for(string s:a.tt) d.tt.insert(s);
	for(string s:b.tt) d.tt.insert(s);
	for(string s:c.tt) d.tt.insert(s);
	if(a.all) d.prefix = (a.prefix + b.prefix).substr(0, 9);
	else d.prefix = a.prefix;
	if(b.all) {
		string r = (a.suffix + b.suffix);
		d.suffix = r.substr(r.size() - 9);
	} else d.suffix = b.suffix;
	return d;
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		a[i] = T(s);
	}
	int m;
	cin >> m;
	for(int i = n + 1; i <= n + m; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = add(a[x], a[y]);
		cout << a[i].get() << endl;
	}

}