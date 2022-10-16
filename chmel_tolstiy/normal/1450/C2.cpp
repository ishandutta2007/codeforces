#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	vi cntX(3);
	vi cntO(3);
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (s[i][j] == 'X') {
			++cntX[(i + j) % 3];
		}
		if (s[i][j] == 'O') {
			++cntO[(i + j) % 3];
		}
	}
	int k = 0;
	for (int i = 0; i < 3; ++i) k += cntX[i] + cntO[i];
	int dgX = -1, dgO = -1;
	for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
		if (i == j) continue;
		if ((cntX[i] + cntO[j]) * 3 <= k) {
			dgX = i;
			dgO = j;
		}
	}
	cerr << dgX << ' ' << dgO << endl;
	assert(dgX >= 0 && dgO >= 0);
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (s[i][j] == 'X' && (i + j) % 3 == dgX) {
			s[i][j] = 'O';
		}
		if (s[i][j] == 'O' && (i + j) % 3 == dgO) {
			s[i][j] = 'X';
		}
	}
	for (int i = 0; i < n; ++i)
		cout << s[i] << endl;
	return true;
}

int main() {
	int t; cin >> t;
	while (solve())
		;
	return 0;
}