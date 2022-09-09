#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if (k == 0 || k == n) cout << 0 << ' ';
	else cout << 1 << ' ';
	if (k == 0) cout << 0 << endl;
	else cout << min(k * 2, n - k) << endl;
	return 0;
}