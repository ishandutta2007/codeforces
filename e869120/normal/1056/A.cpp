#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, cnt[109];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int R; cin >> R;
		for (int j = 1; j <= R; j++) { int S; cin >> S; cnt[S]++; }
	}
	vector<int>vec;
	for (int i = 0; i <= 100; i++) {
		if (cnt[i] == N) vec.push_back(i);
	}
	for (int i = 0; i < vec.size(); i++) {
		if (i) cout << " "; cout << vec[i];
	}
	cout << endl;
	return 0;
}