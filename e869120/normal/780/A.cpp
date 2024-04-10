#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, a[120000], b, maxn, cnt;
int main() {
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		cin >> b; a[b]++;
		if (a[b] == 1)cnt++; else cnt--;
		maxn = max(maxn, cnt);
	}
	cout << maxn << endl;
	return 0;
}