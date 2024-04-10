#include <iostream>
#include <string>
#include <vector>
using namespace std;

string S[5009]; int N, M;
string id[5009], L[5009]; int ty[5009], u[5009], v[5009];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		S[i] = "";
		while (S[i] == "") getline(cin, S[i]);

		vector<string>vec; string str = "";
		for (int j = 0; j <= S[i].size(); j++) {
			if (j == S[i].size() || S[i][j] == ' ') {
				vec.push_back(str); str = "";
			}
			else str += S[i][j];
		}

		id[i] = vec[0];

		if (vec.size() == 3) {
			L[i] = vec[2]; ty[i] = 0;
		}
		if (vec.size() == 5) {
			if (vec[3] == "AND") ty[i] = 1;
			if (vec[3] == "OR") ty[i] = 2;
			if (vec[3] == "XOR") ty[i] = 3;

			string v1 = vec[2], v2 = vec[4];
			u[i] = -1; v[i] = -1;
			for (int j = 0; j < i; j++) {
				if (v1 == id[j]) u[i] = j;
				if (v2 == id[j]) v[i] = j;
			}
		}
	}

	string L1 = "", L2 = "";
	for (int i = 0; i < M; i++) {
		vector<int>W0(N, 0), W1(N, 0);
		for (int j = 0; j < N; j++) {
			if (ty[j] == 0) { W0[j] = (L[j][i] - '0'); W1[j] = W0[j]; }
			if (ty[j] == 1) {
				int b0 = 0, b1 = 0, c0 = 1, c1 = 1;
				if (u[j] != -1) { b0 = W0[u[j]]; c0 = W1[u[j]]; }
				if (v[j] != -1) { b1 = W0[v[j]]; c1 = W1[v[j]]; }
				W0[j] = (b0 & b1); W1[j] = (c0 & c1);
			}
			if (ty[j] == 2) {
				int b0 = 0, b1 = 0, c0 = 1, c1 = 1;
				if (u[j] != -1) { b0 = W0[u[j]]; c0 = W1[u[j]]; }
				if (v[j] != -1) { b1 = W0[v[j]]; c1 = W1[v[j]]; }
				W0[j] = (b0 | b1); W1[j] = (c0 | c1);
			}
			if (ty[j] == 3) {
				int b0 = 0, b1 = 0, c0 = 1, c1 = 1;
				if (u[j] != -1) { b0 = W0[u[j]]; c0 = W1[u[j]]; }
				if (v[j] != -1) { b1 = W0[v[j]]; c1 = W1[v[j]]; }
				W0[j] = (b0 ^ b1); W1[j] = (c0 ^ c1);
			}
		}
		
		int F1 = 0, F2 = 0;
		for (int j = 0; j < N; j++) { F1 += W0[j]; F2 += W1[j]; }

		if (F1 > F2) { L1 += "1"; L2 += "0"; }
		if (F1 < F2) { L1 += "0"; L2 += "1"; }
		if (F1 == F2) { L1 += "0"; L2 += "0"; }
	}
	cout << L1 << endl;
	cout << L2 << endl;
	return 0;
}