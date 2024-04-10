#include <iostream>
#include <vector>
using namespace std;
int n, k, p[100009];
void solve(vector<int>a, int l, int r) {
	if (r - l == 1) { p[l] = a[0]; return; }
	int mid = (l + r) / 2;
	vector<int>a1, a2;
	if (k >= 1) {
		int H = mid - l;
		for (int i = (r - l) - H; i < r - l; i++)a1.push_back(a[i]);
		for (int i = 0; i < (r - l) - H; i++)a2.push_back(a[i]);
		k -= 2;
		solve(a1, l, mid);
		solve(a2, mid, r);
	}
	else {
		for (int i = l; i < r; i++)p[i] = a[i - l];
	}
}
int main() {
	cin >> n >> k; k--; vector<int>Z; for (int i = 0; i < n; i++)Z.push_back(i + 1);
	solve(Z, 0, n);
	if (k != 0) { cout << "-1" << endl; }
	else { for (int i = 0; i < n; i++) { if (i)cout << " "; cout << p[i]; }cout << endl; }
	return 0;
}