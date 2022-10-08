/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	int tn;
	cin >> tn;
	while (tn--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		forn(i, n) cin >> a[i];
		int i = 0;
		while (k--) {
			while (!a[i] && i < n - 1) i++;
			a[i]--, a[n-1]++;
		}
		for (int x : a) cout << x << " ";
		cout << "\n";
	}
}