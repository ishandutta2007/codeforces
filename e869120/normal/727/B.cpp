#include<iostream>
#include<string>
#include<vector>
using namespace std;
string S, T; vector<string>B; long long A;
int solve(string U) {
	if (U.size() <= 2)return stoi(U) * 100;
	if (U[U.size() - 3] == '.') {
		int F = stoi(U.substr(U.size() - 2, 2)); U = U.substr(0, U.size() - 3);
		string V = "";
		for (int i = 0; i < U.size(); i++) { if (U[i] >= '0' && U[i] <= '9')V += U[i]; }
		return stoi(V) * 100 + F;
	}
	string V = "";
	for (int i = 0; i < U.size(); i++) { if (U[i] >= '0' && U[i] <= '9')V += U[i]; }
	return stoi(V) * 100;
}
int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		T += S[i];
		if (i == S.size() - 1 || (S[i] < 'a' && S[i + 1] >= 'a')) {
			int pos = 0;
			for (int j = 0; j < (int)T.size() - 1; j++) { if (T[j] >= 'a' && T[j + 1] < 'a')pos = j + 1; }
			B.push_back(T.substr(pos, T.size() - pos)); T = "";
		}
	}
	for (int i = 0; i < B.size(); i++)A += solve(B[i]);
	string TT = to_string(A % 100); while (TT.size() <= 1)TT = "0" + TT;
	bool J = false;
	if (A % 100 == 0) { A /= 100; J = true; }
	else A *= 10;
	string UU = to_string(A);
	if (A < 1000) {
		if (J == true)cout << A << endl;
		else {
			while (UU.size() < 3)UU = "0" + UU;
			cout << "0." << UU.substr(0, 2) << endl;
		}
	}
	else {
		if (UU.size() % 3 >= 1) { cout << UU.substr(0, UU.size() % 3) << "."; }
		int c = 0;
		for (int i = UU.size() % 3; i < UU.size(); i += 3) {
			int C = 3; if (i == UU.size() - 3 && J == false)C = 2;
			if (c)cout << "."; cout << UU.substr(i, C); c++;
		}
		cout << endl;
	}
	return 0;
}