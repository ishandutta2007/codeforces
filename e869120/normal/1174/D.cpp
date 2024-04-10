#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, X; bool used[1 << 19];
vector<long long>E;

int main() {
	cin >> N >> X;
	if (X >= (1LL << N)) {
		for (int i = 0; i < (1 << N); i++) E.push_back(i);
	}
	else {
		for (int i = 0; i < (1 << N); i++) {
			if (used[i] == true) continue;
			E.push_back(i);
			used[i] = true; used[i^X] = true;
		}
	}

	cout << (int)E.size() - 1 << endl;
	for (int i = 0; i < (int)E.size() - 1; i++) { if (i) printf(" "); printf("%d", (E[i + 1] ^ E[i])); } printf("\n");
	return 0;
}