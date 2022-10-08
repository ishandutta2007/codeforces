/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int tn;
	cin >> tn;
	while (tn--) {
		int n, a, k = 0;
		vector<int> cnt(3);
		cin >> n;
		while (n--) 
			cin >> a, cnt[a % 3]++;
		for (int go = 1; go;) {
			go = 0;
			forn(i, 3)
				if (cnt[(i + 1) % 3] < cnt[i]) 
					cnt[(i + 1) % 3]++, cnt[i]--, go = 1, k++;
		}
		cout << k << endl;
	}
}