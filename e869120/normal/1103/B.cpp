#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int Debug = 1;
int A;

char ask(int x, int y) {
	if (Debug == 1) {
		cout << "? " << x << " " << y << endl;
		char c; cin >> c;
		return c;
	}
	if (Debug == 2) {
		if ((x%A) >= (y%A)) return 'x';
		return 'y';
	}
}

int solve() {
	int cl = -1, cr = -1, cm;
	for (int i = 1; i <= 30; i++) {
		char d = ask((1 << (i - 1)), (1 << i));
		if (d == 'x') { cl = (1 << (i - 1)) + 1; cr = (1 << i) + 1; break; }
	}

	if (cl == 2 && cr == 3) {
		char d = ask(0, 1);
		if (d == 'x') return 1;
		return 2;
	}

	int E = cl - 1, minx = (1 << 30);
	for (int i = 0; i < 30; i++) {
		cm = (cl + cr) / 2;
		char d = ask(E, cm);
		if (d == 'y') { cl = cm; }
		else { minx = min(minx, cm); cr = cm; }
	}
	return minx;
}

int main() {
	while (true) {
		string str; cin >> str;
		if (str == "end") break;
		if (Debug == 2) cin >> A;

		int J = solve();
		cout << "! " << J << endl;
	}
	return 0;
}