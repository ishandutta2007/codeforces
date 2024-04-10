#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	long long n, m, k;
	cin >> q;
	while(q--) {
		cin >> n >> m >> k;
		if(n > m)
			swap(n, m);
		if(n == m) {
			if(n == k) {
				cout << n << endl;
				continue;
			}
			else if(n > k) {
				cout << -1 << endl;
				continue;
			} else {
				if((k-n) % 2 == 0) {
					cout << k << endl;
				} else {
					cout << k-2 << endl;
				}
			}
		} else {
			if(k < m) {
				cout << -1 << endl;
				continue;
			}
			int nk = k - n - ((m - n) / 2) * 2;
			if((m - n) % 2 == 0) {
				if(nk % 2 == 0) {
					cout << k << endl;
				} else {
					cout << k - 2 << endl;
				}
			} else {
				cout << k - 1 << endl;
			}
		}
	}
}