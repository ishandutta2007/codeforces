#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

string S, T; bool used[200009]; int A[200009];

bool solve(int pos) {
	for (int i = 0; i < S.size(); i++) used[i] = false;
	for (int i = 0; i < pos; i++) used[A[i]] = true;

	int cx = 0;
	for (int i = 0; i < S.size(); i++) {
		if (used[i] == true) continue;
		if (S[i] == T[cx]) cx++;
		if (cx == T.size()) return true;
	}
	return false;
}

int main() {
	cin >> S >> T;
	for (int i = 0; i < S.size(); i++) { scanf("%d", &A[i]); A[i]--; }

	int cl = 0, cr = S.size() + 1, cm, maxn = 0;
	for (int i = 0; i < 30; i++) {
		cm = (cl + cr) >> 1;
		bool I = solve(cm);
		if (I == true) { maxn = max(maxn, cm); cl = cm; }
		else { cr = cm; }
	}
	cout << maxn << endl;
	return 0;
}