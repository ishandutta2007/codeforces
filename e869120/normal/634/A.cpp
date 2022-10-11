#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, a[2000005], b[200005], minx1 = 1e9, minid1, minx2 = 1e9, minid2; vector<int>c1, c2;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a[i]; if (a[i] != 0 && a[i] < minx1) { minx1 = a[i]; minid1 = i; } }
	for (int i = 0; i < n; i++) { cin >> b[i]; if (b[i] != 0 && b[i] < minx2) { minx2 = b[i]; minid2 = i; } }
	for (int i = minid1; i < n + minid1; i++) { if (a[i%n] >= 1) { c1.push_back(a[i%n]); } }
	for (int i = minid2; i < n + minid2; i++) { if (b[i%n] >= 1) { c2.push_back(b[i%n]); } }
	if (c1 != c2) { cout << "NO" << endl; }
	else { cout << "YES" << endl; }
	return 0;
}