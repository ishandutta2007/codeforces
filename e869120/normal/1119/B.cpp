#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, H, A[1009];

bool check(int pos) {
	vector<int>G;
	for (int i = 0; i < pos; i++) G.push_back(A[i]);
	sort(G.begin(), G.end());
	reverse(G.begin(), G.end());

	int sum = 0;
	for (int i = 0; i < G.size(); i += 2) {
		int t1 = G[i];
		sum += t1;
		if (sum > H) return false;
	}
	return true;
}

int main() {
	cin >> N >> H;
	for (int i = 0; i < N; i++) cin >> A[i];
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		if (check(i) == true) ret = i;
	}
	cout << ret << endl;
	return 0;
}