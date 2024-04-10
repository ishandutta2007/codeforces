#include <iostream>
#include <vector>
using namespace std;

int s[100009], t[100009], n, a[100009], b[100009];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "? " << i << " " << i << endl; int c1; cin >> c1; s[i * 2] = c1;
		cout << "? " << (i + 1) % n << " " << i << endl; int c2; cin >> c2; s[i * 2 + 1] = c2;
	}
	vector<int>ret; int sum = 0;
	for (int i = 0; i < n; i++) {
		t[0] = i;
		for (int j = 1; j < n * 2; j++) t[j] = (t[j - 1] ^ s[j - 1]);
		for (int j = 0; j < n * 2; j++) {
			if (j % 2 == 0) a[j / 2] = t[j];
			if (j % 2 == 1) b[j / 2] = t[j];
		}
		bool OK = true;
		for (int j = 0; j < n; j++) {
			if (a[b[j]] != j) OK = false;
		}
		if (OK == true) {
			sum++;
			vector<int>J; for (int j = 0; j < n; j++) J.push_back(a[j]);
			ret = J;
		}
	}
	cout << "!" << endl;
	cout << sum << endl;
	for (int i = 0; i < ret.size(); i++) { if (i)cout << " "; cout << ret[i]; }
	cout << endl;
	return 0;
}