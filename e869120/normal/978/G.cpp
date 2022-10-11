#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

int N, M, L[100009], R[100009], X[100009], A[100009]; bool used[100009], OK = true;
vector<int>G[100009];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> L[i] >> R[i] >> X[i];
		used[R[i]] = true; G[L[i]].push_back(i);
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>Q;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < G[i].size(); j++) {
			for (int k = 0; k < X[G[i][j]]; k++) Q.push(make_pair(R[G[i][j]], G[i][j]));
		}
		if (used[i] == true) A[i] = (M + 1);
		else {
			if (!Q.empty()) {
				pair<int, int>F = Q.top(); Q.pop();
				if (F.first <= i) OK = false;
				A[i] = F.second;
			}
		}
	}
	if (!Q.empty()) OK = false;
	if (OK == false) cout << "-1" << endl;
	else {
		for (int i = 1; i <= N; i++) { if (i >= 2)cout << " "; cout << A[i]; } cout << endl;
	}
	return 0;
}