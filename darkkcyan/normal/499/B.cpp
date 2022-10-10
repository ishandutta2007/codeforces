#include <bits/stdc++.h>
using namespace std;

map<string, string> ms;
string a, b;
int main() {
	int m, n; cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		if (a.size() > b.size()) ms[a] = ms[b] = b;
		else if (a.size() < b.size()) ms[a] = ms[b] = a;
		else {
			ms[a] = a;
			ms[b] = b;
		}
	}
	for (int i = 0; i < m; ++i) {
		cin >> a;
		cout << ms[a] << ' ';
	}
	return 0;
}