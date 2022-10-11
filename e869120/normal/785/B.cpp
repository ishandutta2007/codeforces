#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, m, a, b, cx = 1e9, cy = 1e9, dx = -1e9, dy = -1e9;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a >> b; cx = min(cx, b); dx = max(dx, a); }
	cin >> m;
	for (int i = 0; i < m; i++) { cin >> a >> b; cy = min(cy, b); dy = max(dy, a); }
	cout << max(0, max(dy - cx, dx - cy)) << endl;
	return 0;
}