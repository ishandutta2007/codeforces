#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
int a[N];

int main() {
	ios::sync_with_stdio(0);
	int n, k; cin >> n >> k;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % k) return cout << "No" << endl, 0;
	vector<int> vec;
	long long p = sum / k;
	long long cur = p;
	int cnt = 0;
	for (int i = 0; i < n; i++, ++cnt) {
		if (cur == 0) {
			vec.push_back(cnt);
			cur = p, cnt = 0;
		}
		if (cur < a[i]) return cout << "No" << endl, 0;
		cur -= a[i];
	}
	vec.push_back(cnt);
	cout << "Yes" << endl;
	for (int x : vec) cout << x << ' ';
	return 0;
}