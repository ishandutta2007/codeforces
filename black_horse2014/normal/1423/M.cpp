#include <bits/stdc++.h>
using namespace std;

int arr[1000010], len = 0;
int mpos[1000010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, mn = 2e9;
	cin >> n >> m;
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			cout << "? " << i << " 1" << endl;
			cin >> arr[i];
			mn = min(arr[i], mn);
		}
		cout << "! " << mn << endl;
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		cout << "? 1 " << i << endl;
		cin >> arr[i];
		mn = min(arr[i], mn);
	}
	for (int i = 1; i <= m; i++) {
		if (i == 1) mpos[i] = i;
		else if (arr[mpos[i - 1]] > arr[i]) mpos[i] = i;
		else mpos[i] = mpos[i - 1];
	}
	len = m;
	for (int j = 2; j <= m; j++)
		if (arr[j] >= arr[j + 1]) {
			len = j - 1;
			break;
		}
	int curpos = len, tot = 0;
	for (int i = 2; i <= n; i++) {
		int temp = len, prv = 2e9;
		while (len <= m) {
			cout << "? " << i << " " << len << endl;
			len++;
			int val;
			cin >> val;
			mn = min(mn, val);
			if (val >= prv) break;
			prv = val;
		}
		if (len == m + 1) len++;
		len -= 2;
		cout << "? " << i << " " << len - temp + mpos[m - (len - temp)] << endl;
		int val;
		cin >> val;
		mn = min(mn, val);
	}
	cout << "! " << mn << endl;
	return 0;
}