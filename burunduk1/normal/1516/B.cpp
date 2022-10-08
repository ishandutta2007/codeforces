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
		int n, x = 0;
		cin >> n;
		vector<int> a(n);
		forn(i, n)
			cin >> a[i], x ^= a[i];
		bool f = !x; 
		int t = 0, s;
		forn(i, n) {
			t ^= a[i], s = 0;
			for (int j = i + 1; j < n; j++)	
				s ^= a[j], f |= (t == s && t == x);
		}
		puts(f ? "YES" : "NO");
	}
}