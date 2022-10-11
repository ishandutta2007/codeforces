#include<iostream>
#include<string>
using namespace std;

int bit[100019][11][10][4];

void add(int p, int q, int r, int s, int w) {
	p++;
	while (p <= 100017) { bit[p][q][r][s] += w; p += (p&-p); }
}
int sum(int p, int q, int r, int s) {
	int ret = 0; p++;
	while (p >= 1) { ret += bit[p][q][r][s]; p -= (p&-p); }
	return ret;
}
int sums(int L, int R, int q, int r, int s) {
	return sum(R, q, r, s) - sum(L - 1, q, r, s);
}
int chars(char p) {
	if (p == 'A')return 0;
	if (p == 'T')return 1;
	if (p == 'C')return 2;
	return 3;
}
string S; int F[100009], q;
int main() {
	cin >> S; for (int i = 1; i <= S.size(); i++)F[i] = chars(S[i - 1]);
	for (int i = 1; i <= S.size(); i++) {
		for (int j = 1; j <= 10; j++) { add(i, j, i%j, F[i], 1); }
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int ty; cin >> ty;
		if (ty == 1) {
			int Y1; string Y2; cin >> Y1 >> Y2;
			int Y3 = chars(Y2[0]);
			for (int j = 1; j <= 10; j++) { add(Y1, j, Y1%j, F[Y1], -1); }F[Y1] = Y3;
			for (int j = 1; j <= 10; j++) { add(Y1, j, Y1%j, Y3, 1); }
		}
		if (ty == 2) {
			int Y1, Y2; string Y3;
			cin >> Y1 >> Y2 >> Y3; int ret = 0;
			for (int j = 0; j < Y3.size(); j++) {
				ret += sums(Y1, Y2, Y3.size(), (j + Y1) % Y3.size(), chars(Y3[j]));
			}
			cout << ret << endl;
		}
	}
	return 0;
}