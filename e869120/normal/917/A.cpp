#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

string S; int cl[5009][5009], cr[5009][5009];

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		int ret = 0;
		for (int j = i; j < S.size(); j++) {
			if (S[j] == '(' || S[j] == '?') ret++;
			if (S[j] == ')') ret--;
			if (ret < 0) break;
			cl[i][j] = true;
		}
	}
	for (int i = 0; i < S.size(); i++) {
		int ret = 0;
		for (int j = i; j >= 0; j--) {
			if (S[j] == ')' || S[j] == '?') ret++;
			if (S[j] == '(') ret--;
			if (ret < 0) break;
			cr[j][i] = true;
		}
	}
	for (int i = 1; i <= S.size(); i++) { cl[i][i - 1] = true; cr[i][i - 1] = true; }

	int ans = 0;
	for (int i = 0; i < S.size(); i++) {
		int ca = 0, cb = 0; vector<int>D;
		for (int j = i; j < S.size(); j++) {
			if (S[j] == '(') ca++;
			if (S[j] == ')') cb++;
			if (S[j] == '?') D.push_back(j);
			
			if ((j - i) % 2 == 1) {
				int len = (j - i + 1);
				if (ca > (len >> 1) || cb > (len >> 1)) continue;
				int E = (len >> 1) - ca, F = i;
				if (E >= 1) F = D[E - 1] + 1;

				if ((F == 0 || cl[i][F - 1] == true) && cr[F][j] == true) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}