/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 10123;
int f[N];

bool ask(int x, int y, int z) {
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
		if (o)
			in2 = i;
		else
			in1 = i;
	}
	bool x1 = ask(in1, in2, in2 + 1);
	bool x2 = ask(in1, in2 + 2, in2 + 1);
	bool x3 = ask(in1, in2, in2 + 2);
	int an1, an0;
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
	vector <int> v = {an1};
	for (int i = 0; i < n; i++) {
		if (i == an1 || i == an0)
			continue;
		if (ask(i, an1, an0)) {
			f[i] = 0;
		} else {
			f[i] = 1;
			t++;
			v.push_back(i);
		}
	}
	sort(v.begin(), v.end());
	cout << "! " << t << ' ';
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