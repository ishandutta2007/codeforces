#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m; vector<int>A, B;
int main() {
	cin >> n >> m;
	for (int i = 1; i < 5000000; i++) {
		if (i % 2 == 0 && i % 6 != 0)A.push_back(i);
		if (i % 3 == 0 && i % 6 != 0)B.push_back(i);
	}
	for (int i = 0; i < 5000000; i++) {
		int pos1 = upper_bound(A.begin(), A.end(), i) - A.begin(); pos1 = min(pos1, n);
		int pos2 = upper_bound(B.begin(), B.end(), i) - B.begin(); pos2 = min(pos2, m);
		int F = i / 6;
		if (pos1 + pos2 + F >= n + m) { cout << i << endl; break; }
	}
	return 0;
}