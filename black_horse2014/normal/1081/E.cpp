#include <bits/stdc++.h>
using namespace std;

const int N = 220000;
vector<int> vec[N];
int a[N], b[N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i * i < N; i++) {
		for (int j = i * i; j < N; j += i) vec[j].push_back(i);
	}
	for (int i = 1; i < N; i++) reverse(vec[i].begin(), vec[i].end());
	int n; cin >> n;
	int prv = 0;
	for (int i = 2; i <= n; i+=2) {
		cin >> a[i];
		int flg = 0;
		for (int x : vec[a[i]]) {
			int y = a[i] / x;
			if ((x + y) & 1) continue;
			int c = (y - x) / 2, d = (y + x) / 2;
			if (prv < c) {
				flg = 1;
				b[i-1] = c, b[i] = d;
				prv = d;
				break;
			}
		}
		if (!flg) return cout << "No" << endl, 0;
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= n; i++) {
		long long d = 1LL * b[i] * b[i] - 1LL * b[i-1] * b[i-1];
		cout << d << ' '; 
	}
}