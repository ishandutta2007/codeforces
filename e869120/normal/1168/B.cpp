#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const long long mod = 1000000009;
string S;
long long N, c[1 << 19], d[1 << 19];

int main() {
	cin >> S; N = S.size();
	for (int i = 1; i <= S.size(); i++) {
		if (S[i - 1] == '1') { c[i] = 1; }
		if (S[i - 1] == '0') { c[i] = 0; }
	}

	for (int i = 1; i <= S.size() + 1; i++) d[i] = (S.size() + 1);
	for (int i = 1; i <= S.size(); i++) {
		int cl = i, cr = i;
		while (true) {
			cl--; cr++; if (cl <= 0 || cr > N) break;
			if (c[cl] == c[i] && c[i] == c[cr]) { d[cl] = min(d[cl], 1LL * cr); break; }
		}
	}
	for (int i = S.size(); i >= 1; i--) d[i] = min(d[i], d[i + 1]);

	long long sum = 0;
	for (int i = 1; i <= S.size(); i++) sum += (1LL * (S.size() + 1)) - d[i];
	cout << sum << endl;
	return 0;
}