/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 510;
set <int> st[N];
int ans[N], a[N][N], anss[N];

int32_t main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			st[i].insert(a[i][j]);
		}
	}
	int an = -1;
	for (int i = 0; i < n; i++) 
		if (st[i].size() >= 2)
			an = i;
	if (an == -1) {
		int xs = 0;
		for (int i = 0; i < n; i++) {
			int x = *st[i].begin();
			xs ^= x;
		}
		if (xs) {
			cout << "TAK\n";
			for (int i = 0; i < n; i++) 
				cout << "1 ";
		}else {
			cout << "NIE\n";
		}
		return 0;
	}
	cout << "TAK\n";
	int xo = 0;
	for (int i = 0; i < n; i++) {
		if (i == an)
			continue;
		xo ^= (*st[i].begin());
		ans[i] = (*st[i].begin());
	}
	if ((xo ^ (*st[an].begin())) != 0) {
		ans[an] = *st[an].begin();
	}else {
		ans[an] = *st[an].rbegin();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == ans[i]) {
				anss[i] = j + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) 
		cout << anss[i] << ' ';
}