#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

string S; int t = 0, maxn = 0;

int main() {
	cin >> S; t = 1; maxn = 1;
	for (int i = 1; i < S.size() * 3; i++) {
		char c1 = S[i % S.size()];
		char c2 = S[(i - 1) % S.size()];

		if (c1 != c2) { t++; }
		else t = 1;
		maxn = max(maxn, t);
	}
	cout << min(maxn, (int)S.size()) << endl;
	return 0;
}