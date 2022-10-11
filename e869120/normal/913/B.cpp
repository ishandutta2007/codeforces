#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, P[1 << 18], deg[1 << 18]; bool flag = false;
vector<int> X[1 << 18];

int main() {
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) { scanf("%d", &P[i]); X[P[i]].push_back(i); deg[P[i]]++; }
	for (int i = 1; i <= N; i++) {
		if (deg[i] == 0) continue;
		int cnt = 0;
		for (int j = 0; j < X[i].size(); j++) {
			if (deg[X[i][j]] == 0) cnt++;
		}
		if (cnt <= 2) flag = true;
	}
	if (flag == true) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}