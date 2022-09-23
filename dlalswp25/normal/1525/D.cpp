#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> L, R;

int D[5050][5050];

int main() {
	scanf("%d", &N);
	L.push_back(0); R.push_back(0);
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		if(!a) R.push_back(i);
		else L.push_back(i);
	}

	int X = (int)L.size() - 1, Y = (int)R.size() - 1;
	for(int i = 1; i <= X; i++) D[i][0] = 1010101010;

	for(int i = 1; i <= X; i++) {
		for(int j = 1; j <= Y; j++) {
			D[i][j] = min(D[i][j - 1], D[i - 1][j - 1] + abs(L[i] - R[j]));
		}
	}

	printf("%d\n", D[X][Y]);

	return 0;
}