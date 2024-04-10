#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
#pragma warning (disable: 4996)

int n, a[1000009];

int Rand() {
	int t = 1, s = 0;
	for (int i = 0; i < 3; i++) { s += (rand() % 1024)*t; t *= 1024; }
	return s;
}

int swap_sort(int nn, int pos) {
	n = nn;
	for (int i = 0; i < n; i++) a[i] = i;
	for (int i = 0; i < pos; i++) {
		int u = -1, v = -1;
		while (u == v) { u = Rand() % n; v = Rand() % n; }
		swap(a[u], a[v]);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) { if (a[i] == i) cnt++; }
	return cnt;
}

int main() {
	/*srand((unsigned)time(NULL));
	for (int i = 1000; i <= 1000000; i *= 10) {
		cout << "Petr : "; for (int j = 0; j < 10; j++) { cout << swap_sort(i, i * 3) << " "; } cout << endl;
		cout << "Umnik: "; for (int j = 0; j < 10; j++) { cout << swap_sort(i, i * 7 + 1) << " "; } cout << endl;
	}*/
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == i) cnt++;
	}
	if (cnt >= n / 500) cout << "Petr" << endl;
	else cout << "Um_nik" << endl;
	return 0;
}