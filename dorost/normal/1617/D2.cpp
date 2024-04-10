/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 10123;
int f[N];
bool l[N];
int an1, an0;

bool ask(int x, int y, int z) {
	if (x == y || x == z) {
		if (x == an0) 
			return 1;
		else
			return 0;
	}
	cout << "? " << x + 1 << ' ' << y + 1 << ' ' << z + 1 << endl;
	int x2;
	cin >> x2;
	return x2;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		f[i] = -1;
	}
	int in1, in2;
	for (int i = 0; i < n; i += 3) {
		bool o = ask(i, i + 1, i + 2);
		l[i] = o;
		if (o)
			in2 = i;
		else
			in1 = i;
	}
	bool x1 = ask(in1, in2, in2 + 1);
	bool x2 = ask(in1, in2 + 2, in2 + 1);
	bool x3 = ask(in1, in2, in2 + 2);
	if (!x1 || !x2 || !x3) {
		an1 = in1;
		if (!x1) 
			an0 = in2 + 2;
		if (!x2)
			an0 = in2;
		if (!x3)
			an0 = in2 + 1;
	} else {
		x1 = ask(in1 + 1, in1 + 2, in2);
		x2 = ask(in1 + 1, in1 + 2, in2 + 1);
		if (!x1 && !x2) {
			an1 = in1 + 1;
			if (ask(in1, in1 + 1, in2)) {
				an0 = in2;
			} else {
				an0 = in2 + 1;
			}
		} else {
			an1 = in1;
			an0 = in2;
		}
	}
	f[an1] = 1;
	f[an0] = 0;
	int t = 1;
	vector <int> v = {};
	for (int i = 0; i < n; i += 3) {
		if (!l[i]) {
			bool x1 = !ask(an0, i, i + 1);
			bool x2 = !ask(an0, i + 1, i + 2);
			if (x1 && x2) {
				f[i] = 1;
				f[i + 1] = 1;
				f[i + 2] = 1;
			} else if (x1) {
				f[i] = 1;
				f[i + 1] = 1;
				f[i + 2] = 0;
			} else if (x2) {
				f[i] = 0;
				f[i + 1] = 1;
				f[i + 2] = 1;
			} else {
				f[i] = 1;
				f[i + 1] = 0;
				f[i + 2] = 1;
			}
		} else {
			bool x1 = ask(an1, i, i + 1);
			bool x2 = ask(an1, i + 1, i + 2);
			if (x1 && x2) {
				f[i] = 0;
				f[i + 1] = 0;
				f[i + 2] = 0;
			} else if (x1) {
				f[i] = 0;
				f[i + 1] = 0;
				f[i + 2] = 1;
			} else if (x2) {
				f[i] = 1;
				f[i + 1] = 0;
				f[i + 2] = 0;
			} else {
				f[i] = 0;
				f[i + 1] = 1;
				f[i + 2] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (f[i] == 1)
			v.push_back(i);
	sort(v.begin(), v.end());
	cout << "! " << v.size() << ' ';
	for (auto x : v) {
		cout << x + 1 << ' ';
	}
	cout << endl;
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}