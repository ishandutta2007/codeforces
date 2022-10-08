/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	int even = n / 2, odd = n - even, even_x = 2, odd_x = 1;
	int ma = (a * b + 1) / 2, mi = a * b - ma;
	if (mi < even || ma < odd) {
		puts("-1");
		return 0;
	}
	forn(i, a) {
		forn(j, b) {
			int res = 0;
			if ((i + j) & 1) {
				if (even_x <= n)
					res = even_x, even_x += 2; 
			} else {
				if (odd_x <= n)
					res = odd_x, odd_x += 2; 
			}
			cout << res << " ";
		}
		cout << "\n";
	}	
}