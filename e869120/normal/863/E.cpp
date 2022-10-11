#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#pragma warning(disable: 4996)
int n, l[200009], r[200009], c[500009]; vector<int>x;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) { scanf("%d%d", &l[i], &r[i]); r[i]++; x.push_back(l[i]); x.push_back(r[i]); }
	sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
	for (int i = 1; i <= n; i++) {
		int pos1 = lower_bound(x.begin(), x.end(), l[i]) - x.begin(); pos1++; l[i] = pos1;
		int pos2 = lower_bound(x.begin(), x.end(), r[i]) - x.begin(); pos2++; r[i] = pos2;
		c[pos1]++; c[pos2]--;
	}
	for (int i = 1; i <= x.size(); i++)c[i] += c[i - 1];
	for (int i = 1; i <= x.size(); i++) { if (c[i] >= 2)c[i] = 2; }
	for (int i = 1; i <= x.size(); i++)c[i] += c[i - 1];
	for (int i = 1; i <= n; i++) {
		if (c[r[i] - 1] - c[l[i] - 1] == 2 * (r[i] - l[i])) { cout << i << endl; return 0; }
	}
	cout << "-1" << endl;
	return 0;
}