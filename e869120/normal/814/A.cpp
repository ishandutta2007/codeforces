#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<functional>
#include<queue>
using namespace std;
int n, k, a[200], b[200];
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < k; i++)cin >> b[i]; sort(b, b + k, greater<int>());
	int L = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) { a[i] = b[L]; L++; }
	}
	bool OK = true;
	for (int i = 0; i < n - 1; i++) { if (a[i] >= a[i + 1])OK = false; }
	if (OK == true)cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}