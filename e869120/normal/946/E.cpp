#include <iostream>
#include <string>
using namespace std;

int n;

string rep9(int p) {
	string G = "";
	for (int i = 0; i < p; i++) G += "9";
	return G;
}

int r[200009];

int ranges(int L, int R) {
	if (L == 0) return r[R];
	return r[R] - r[L - 1];
}

string solve_2(string U, string V, int leng) {
	// 
	int t[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < U.size(); i++) { if (i < V.size()) t[V[i] - '0'] ^= 1; if (U[i] >= '1') r[i] = 1; else r[i] = 0; }
	for (int i = 1; i < U.size(); i++) r[i] += r[i - 1];

	int semi = 0;

	while ((int)V.size() < leng) {
		int bo = (U[V.size()] - '0'); if (semi == 1) bo = 9;
		for (int i = bo; i >= 0; i--) {
			t[i] ^= 1;

			// 
			string I = ""; for (int j = 0; j < 10; j++) { if (t[j] == 1) I += ('0' + j); }
			bool OK = true;
			if ((leng - V.size()) < I.size()) OK = false;
			if (semi == 0 && i == bo && I > U.substr(leng - I.size(), I.size()) && ranges(V.size() + 1, leng - I.size() - 1) == 0) OK = false;

			if (OK == false) {
				t[i] ^= 1;
			}
			else {
				V += ('0' + i);
				if (i != bo) semi = 1;
				break;
			}
		}
	}
	return V;
}

string check(string V, int pos) {
	int v[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < pos; i++) v[V[i] - '0'] ^= 1;
	string I = "";
	for (int i = 0; i <= 9; i++) { if (v[i] == 1) I += ('0' + i); }

	string U = V.substr(0, pos) + I;
	if (U > V || V.size() < U.size()) {
		if (pos != 0) return "";
		if (pos == 0) return rep9(V.size() - 2);
	}
	return solve_2(V, V.substr(0, pos), V.size());
}

string solve(string S) {
	if (S.size() % 2 == 1) {
		return rep9(S.size() - 1);
	}
	string P = check(S, 0);
	if (P[0] == '0') {
		return rep9(P.size() - 2);
	}
	return P;
}

string decrement(string V) {
	for (int i = V.size() - 1; i >= 0; i--) {
		if (V[i] == '0' && i != 0) { V[i] = '9'; }
		else { V[i]--; break; }
	}
	return V;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string S; cin >> S;
		S = decrement(S);
		cout << solve(S) << endl;
	}
	return 0;
}