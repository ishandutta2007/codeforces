#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, h; cin >> n >> h;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int lo = 1, hi = n + 1;
    while (hi - lo > 1) {
        int mid = lo + hi >> 1;
        vector<int> b;
        for (int i = 1; i <= mid; i++) b.push_back(a[i]);
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        long long sum = 0;
        for (int i = 0; i < b.size(); i += 2) sum += b[i];
        if (sum > h) hi = mid;
        else lo = mid;
    }
    cout << lo << endl;
    return 0;
}