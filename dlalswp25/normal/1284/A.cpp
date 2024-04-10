#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
vector<string> A, B;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		string x; cin >> x;
		A.push_back(x);
	}
	for(int i = 1; i <= M; i++) {
		string x; cin >> x;
		B.push_back(x);
	}

	scanf("%d", &Q);
	while(Q--) {
		int y; scanf("%d", &y);
		cout << A[(y - 1) % N] + B[(y - 1) % M];
		puts("");
	}
	return 0;
}