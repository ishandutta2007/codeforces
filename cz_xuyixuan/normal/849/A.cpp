#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int a[MAXN];
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	if (n % 2 == 0) {
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (a[1] % 2 == 1 && a[n] % 2 == 1) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}