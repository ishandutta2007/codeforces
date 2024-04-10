#include<iostream>
#include<string>
using namespace std;
string S, T; int a[10], b[10], c[10], d[10], n;
int main() {
	cin >> n >> S >> T;
	for (int i = 0; i < S.size(); i++) { a[S[i] - '0']++; c[S[i] - '0']++; }
	for (int i = 0; i < T.size(); i++) { b[T[i] - '0']++; d[T[i] - '0']++; }
	int cnt = 0;
	while (true) {
		int V = -1; for (int i = 0; i < 10; i++) { if (b[i] >= 1)V = i; }
		int W = -1; for (int i = 0; i <= V; i++) { if (a[i] >= 1)W = i; }
		if (V == -1 || W == -1) { cout << S.size() - cnt << endl; break; }
		b[V]--; a[W]--; cnt++;
	}
	int cnt2 = 0;
	while (true) {
		int V = -1; for (int i = 0; i < 10; i++) { if (d[i] >= 1)V = i; }
		int W = -1; for (int i = 0; i < V; i++) { if (c[i] >= 1)W = i; }
		if (V == -1 || W == -1) { cout << cnt2 << endl; break; }
		d[V]--; c[W]--; cnt2++;
	}
	return 0;
}