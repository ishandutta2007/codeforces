/**
10101
+ + +
()(( (
((() (
b
**/

/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn, n;
	cin >> tn;
	while (tn--) {
		string s, a1, a2;
		cin >> n >> s; 
		int b1 = 0, b2 = 0, bad = 0; 
		for (char c : s)
			if (c == '1') {
				a1 += '(', a2 += '(';
				b1++, b2++;
			} else {
				if (b1 > b2)
					a1 += ')', a2 += '(', b1--, b2++;
				else
					a1 += '(', a2 += ')', b1++, b2--;
				bad |= (b1 < 0 || b2 < 0);
			}
		bad |= (b1 != b2);
		int x = b1 / 2;
		for (int i = n - 1; i >= 0; i--)
			if (s[i] == '1' && x > 0)
				x--, a1[i] = ')', a2[i] = ')';
		bad |= (x > 0);
		b1 = 0, b2 = 0;
		forn(i, n) {
			b1 += (a1[i] == '(' ? 1 : -1);
			b2 += (a2[i] == '(' ? 1 : -1);
			bad |= (b1 < 0 || b2 < 0);
		}
		if (bad)
			cout << "NO\n";
		else
			cout << "YES\n" << a1 << "\n" << a2 << "\n";
		// b1 == b2 == b
		// b/2
	}
	// ++++
	// ++-|-
	// +--|+
	// sum[i]
}