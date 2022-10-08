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
		int n, neg = 0;
		cin >> n;
		vector<int> v(n);
		vector<int> was(101);
		forn(i, n) 
			cin >> v[i], neg |= v[i] < 0;
		if (neg) {
			cout << "NO\n";
			continue;
		}
		for (int x : v)
			was[x] = 1;

		for (int r = 0; r < (int)v.size(); r++)
			for (int x, l = 0; l < r; l++)
				if (!was[x = abs(v[r] - v[l])]) {
					was[x] = 1;
					v.push_back(x);
				}
		cout << "YES\n" << v.size() << "\n";
		for (int x : v) cout << x << " ";
		cout << endl;
	}
}

	// printf("%d,%d %d,%d | %c\n", '(', ')', '[', ']', 92);