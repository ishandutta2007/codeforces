#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
string S;
struct State { char p[2][13]; };
int dx[5] = { 1,0,-1,0,1 }, dy[8] = { 0,1,0,-1,1 }; bool OK = false;
int solve(State &E, int r1, int r2, int depth) {
	if (OK == true)return 1;
	if (depth == 27) {
		for (int i = 0; i < 26; i++) {
			cout << E.p[i / 13][i % 13];
			if (i % 13 == 12)cout << endl;
		}
		OK = true; return 1;
	}

	for (int i = 0; i < 5; i++) {
		int cx = r1 + dx[i], cy = r2 + dy[i];
		if (cx < 0 || cx >= 2 || cy < 0 || cy >= 13)continue;
		if (E.p[cx][cy] != '$' && E.p[cx][cy] != S[depth])continue;

		char F = E.p[cx][cy];
		E.p[cx][cy] = S[depth];
		solve(E, cx, cy, depth + 1);
		E.p[cx][cy] = F;
	}
	return 0;
}
int main() {
	cin >> S;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 13; j++) {
			State Y; for (int k = 0; k < 26; k++)Y.p[k / 13][k % 13] = '$';
			Y.p[i][j] = S[0];
			solve(Y, i, j, 1);
		}
	}
	if (OK == false)cout << "Impossible" << endl;
	return 0;
}