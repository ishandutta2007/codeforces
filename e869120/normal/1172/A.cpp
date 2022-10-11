#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 20], B[1 << 20], C[1 << 20], ty[1 << 20];
int maxn = 0;

bool check(int pos) {
	for (int i = 0; i <= N; i++) ty[i] = -1;
	for (int i = 0; i < N; i++) { ty[B[i]] = i; }
	for (int i = 1; i <= N; i++) {
		if (ty[i] >= 0 && ty[i] == pos + (i - 1)) continue;
		if (ty[i] >= 0 && ty[i] > (pos + (i - 1)) - (N + 1)) return false;
	}
	return true;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) scanf("%d", &B[i]);

	int root = N;
	for (int i = 0; i < N; i++) { if (B[i] == 1) root = i; }
	bool flag = true; for (int i = root; i < N; i++) { if (B[i] != (i - root + 1)) flag = false; }

	if (flag == true && check(root) == true) {
		cout << root << endl;
		return 0;
	}

	maxn = (N + 1);
	for (int i = 1; i <= N; i++) { if (B[i] != 0) maxn = max(maxn, i - B[i] + N + 2); }
	cout << maxn << endl;
	return 0;
}