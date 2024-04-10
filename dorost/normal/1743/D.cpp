/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define F first
#define S second
#define mk make_pair
const int N = 1000123;
bool a[N], b[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	vector <int> v, p;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		v.push_back(i);
		char c;
		cin >> c;
		a[i] = c - '0';
		b[i] = a[i];
		if (a[i])
			continue;
		p.push_back(n - i - 1);
	}
	for (int i = 0; i < (int)p.size(); i++) {
		vector <int> w = v;
		v.clear();
		for (int j : w) {
			if (j - p[i] < 0 || j - p[i] >= n)
				continue;
			if (a[j - p[i]])
				v.push_back(j);
		}
		if (v.empty()) 
			v = w;
		else
			b[n - p[i] - 1] = 1;
	}
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (f && !b[i])
			continue;
		else
			f = false;
		cout << b[i];
	}
	if (f)
		cout << '0';
	cout << '\n';
}