#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N];
int main() {
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int dap = 0;
	for (int i = 1; i < n; i += 2) dap += (a[i + 1] - a[i]);
	cout << dap << endl; 
	return 0;
}