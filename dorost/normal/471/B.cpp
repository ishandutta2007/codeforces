/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012;
vector <int> c[N];
int a[N];

void print() {
	for (int i = 0; i < N; i++) {
		for (int x : c[i]) 
			cout << x << ' ';
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[a[i]].push_back(i + 1);
	}
	vector <int> c2;
	for (int i = 0; i < N; i++) {
		if (c[i].size() >= 3) {
			cout << "YES\n";
			print();
			swap(c[i][0], c[i][1]);
			print();
			swap(c[i][1], c[i][2]);
			print();
			return 0;
		} else if (c[i].size() == 2) 
			c2.push_back(i);
	}
	if (c2.size() <= 1) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	print();
	swap(c[c2[0]][0], c[c2[0]][1]);
	print();
	swap(c[c2[1]][0], c[c2[1]][1]);
	print();
}