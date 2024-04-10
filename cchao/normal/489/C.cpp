#include <bits/stdc++.h>
using namespace std;

void pi(vector<int> a) {
	for(auto v: a) cout << v;
}

void mi(int m, int s) {
	vector<int> a(m);
	a[0] = 1; s -= 1;
	for(int i = m - 1; i >= 0; --i) {
		int t =  min(9 - a[i], s);
		s -= t; a[i] += t;
	}
	if(s != 0) {
		cout << "-1";
	}
	else pi(a);
}

void ma(int m, int s) {
	vector<int> a(m);
	a[0] = 1; s -= 1;
	for(int i = 0; i < m; ++i) {
		int t =  min(9 - a[i], s);
		s -= t; a[i] += t;
	}
	if(s != 0) {
		cout << "-1";
	}
	else pi(a);
}

int main() {
	int m, s; cin >> m >> s;

	if(s == 0) {
		if(m == 1) puts("0 0");
		else puts("-1 -1");
		return 0;
	}

	mi(m, s); cout << ' ';
	ma(m, s); cout << endl;

	return 0;
}