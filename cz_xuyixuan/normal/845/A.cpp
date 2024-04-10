#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int a[MAXN];
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= 2 * n; i++)
		cin >> a[i];
	sort(a + 1, a + 2 * n + 1);
	if (a[n + 1] > a[n]) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}