/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 505;
int w[N];
pair <int, int> p[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s;
		for (int j = 0; j < m; j++)
			s += '0';
		s[i] = '1';
		cout << "? " << s << endl;
		int y;
		cin >> y;
		w[i] = y;
		p[i].F = w[i];
		p[i].S = i;
	}
	sort(p, p + m);
	int sum = 0;
	string s;
	for (int j = 0; j < m; j++)
		s += '0';
	for (int i = 0; i < m; i++) {
		sum += w[p[i].S];
		s[p[i].S] = '1';
		cout << "? " << s << endl;
		int y;
		cin >> y;
		if (y == sum) {
			continue;
		}
		sum -= w[p[i].S];
		s[p[i].S] = '0';
	}
	cout << "! " << sum << endl;
}