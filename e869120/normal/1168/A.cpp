#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, M, A[300009];

bool solve(int pos) {
	if (pos >= (M - 1)) return true;
	
	int cx = 0;
	for (int i = 0; i < N; i++) {
		int cl = A[i], cr = A[i] + pos;
		if (cr < M) {
			if (cx > cr) return false;
			cx = max(cx, cl);
		}
		else {
			cr %= M;
			if (cx <= cr) cx += 0;
			else if (cx < cl) cx = cl;
			else cx += 0;
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	int cl = 0, cr = M + 1, cm, minx = (1 << 30);
	for (int i = 0; i < 22; i++) {
		cm = (cl + cr) / 2;
		bool I = solve(cm);
		if (I == true) { minx = min(minx, cm); cr = cm; }
		else { cl = cm; }
	}
	cout << minx << endl;
	return 0;
}