#include<iostream>
#include<string>
using namespace std;
int n, m; string S;
string update(string I) {
	int O = I.size() - 1;
	if (I[O] != ':')return I;
	while (O >= 1 && I[O] == ':') {
		I[O] = '0'; if (I[O - 1] == '.')O--;
		I[O - 1]++; O--;
	}
	if (O == 0 && I[O] == ':') { I[O] = '0'; I = '1' + I; }
	bool OK = true;
	for (int i = 0; i < I.size(); i++) {
		if (I[i] == '.')OK = false;
	}
	if (OK == true)return I;
	O = I.size() - 1; while (O >= 0 && I[O] == '0')O--;
	I = I.substr(0, O);
	return I;
}
int main() {
	cin >> n >> m >> S; int d = -2;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '.')d = -1;
		if (d == -2)continue;
		if (S[i] >= '5' && S[i] <= '9') { d = i; break; }
	}
	if (d <= -1) { cout << S << endl; return 0; }
	S = S.substr(0, d); m--;

	for (int i = 0; i <= m; i++) {
		int P = S.size() - 1 - i;
		if (S[P] != '4' || i == m) {
			S = S.substr(0, P + 1);
			if (S[P] == '.') { S = S.substr(0, S.size() - 1); P--; }
			S[P]++;
			S = update(S);
			cout << S << endl; break;
		}
	}
	return 0;
}