#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (a[1] != a[n]) {
        cout << n - 1 << endl;
        return 0;
    }
    int l = 1, r = n;
    while (l <= n && a[l] == a[1]) l++;
    while (r > 0 && a[r] == a[n]) r--;
    cout << max(r - 1, n - l) << endl;
    return 0;
}