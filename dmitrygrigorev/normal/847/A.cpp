#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;

int l[MAXN];
int r[MAXN];

signed main() {
	int n;
	cin >> n;
	vector <int> lefts, rights;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		if (l[i] == 0) {
			lefts.push_back(i);
		} 
		if (r[i] == 0) {
			rights.push_back(i);
		}
	}
	vector <int> elems;
	vector <int> color(n, 0);
	for (int i = 0; i < n; i++) {
		if (color[i] == 0) {
			int j = i;
			for (j = i; l[j] != 0; j = l[j] - 1) {color[j] = 1;}
			elems.push_back(j + 1);
			// cout << j + 1 << endl;
			color[j] = 1;
			j = i;
			for (j = i; r[j] != 0; j = r[j] - 1) {color[j] = 1;}
			elems.push_back(j + 1);
			// cout << j + 1 << endl;
			color[j] = 1;
		}
	}
	for (int x = 1; x + 1 < (int)elems.size(); x += 2) {
		int a = elems[x];
		int b = elems[x + 1];
		r[a - 1] = b;
		l[b - 1] = a;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << l[i] << " " << r[i] << endl;
	}
}