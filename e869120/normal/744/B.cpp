#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, a[1000];
int main() {
	cin >> n; for (int i = 0; i < n; i++)a[i] = 1999999999;
	for (int i = 0; i < 10; i++) {
		vector<int>w, x;
		for (int j = 0; j < n; j++) {
			if ((j / (1 << i)) % 2 == 0)w.push_back(j);
			if ((j / (1 << i)) % 2 == 1)x.push_back(j);
		}
		if (w.size() >= 1) {
			cout << w.size() << endl; for (int j = 0; j < w.size(); j++) { if (j)cout << ' '; cout << w[j] + 1; }cout << endl;
			for (int j = 0; j < n; j++) { int g; cin >> g; if ((j / (1 << i)) % 2 == 1)a[j] = min(a[j], g); }
		}
		if (x.size() >= 1) {
			cout << x.size() << endl; for (int j = 0; j < x.size(); j++) { if (j)cout << ' '; cout << x[j] + 1; }cout << endl;
			for (int j = 0; j < n; j++) { int g; cin >> g; if ((j / (1 << i)) % 2 == 0)a[j] = min(a[j], g); }
		}
	}
	cout << "-1" << endl;
	for (int i = 0; i < n; i++) { if (i)cout << ' '; cout << a[i]; }cout << endl;
	return 0;
}