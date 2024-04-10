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
		string s;
		cin >> s;
		vector<int> count(3);
		for (char c : s)
			count[c - 'A']++;
		if (count[0] + count[2] == count[1])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}