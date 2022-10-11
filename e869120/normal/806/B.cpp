#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[139][6], S1[6], power[6] = { 1, 6, 36, 216, 1296, 7776 }, v[7776][6];

bool solve(int pos) {
	for (int i = 0; i < power[5]; i++) {
		int bit[6]; for (int j = 0; j < 5; j++) bit[j] = v[i][j];
		
		bool flag = false; int a1 = 0, a2 = 0;
		for (int j = 0; j < 5; j++) {
			int cl = ((N + pos) >> (bit[j] + 1)) + 1; if (bit[j] == 5) cl = 0;
			int cr = ((N + pos) >> bit[j]);
			int dl = S1[j];
			int dr = S1[j] + pos; if (A[0][j] == -1) dr = dl;

			if (cr < dl || dr < cl || cl > cr) flag = true;
			else {
				int score = (bit[j] + 1) * 500;
				if (A[0][j] != -1) a1 += score * (250 - A[0][j]) / 250;
				if (A[1][j] != -1) a2 += score * (250 - A[1][j]) / 250;
			}
		}
		if (a1 > a2 && flag == false) {
			return true;
		}
	}
	return false;
}

int main() {
	for (int i = 0; i < 7776; i++) {
		for (int j = 0; j < 5; j++) v[i][j] = (i / power[j]) % 6;
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) { cin >> A[i][j]; if (A[i][j] != -1) S1[j]++; }
	}
	
	int minx = (1 << 30);
	for (int i = 0; i <= 3900; i++) {
		bool I = solve(i);
		if (I == true) { minx = i; break; }
	}
	if (minx == (1 << 30)) minx = -1;
	cout << minx << endl;
	return 0;
}