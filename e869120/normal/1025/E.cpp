#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, K, Before[59], After[59], C1[59][59], C2[59][59], DD[59][59], DE[59][59];
vector<tuple<int, int, int, int>> FinalAns;
vector<tuple<int, int, int>>tup1, tup2;
vector<pair<int, int>>A[59], B[59];

void swaps(int u1, int u2) {
	FinalAns.push_back(make_tuple(1, u1, 2, u1));
	FinalAns.push_back(make_tuple(1, u2, 2, u2));
	FinalAns.push_back(make_tuple(2, u2, 3, u2));
	for (int i = u1; i < u2; i++) FinalAns.push_back(make_tuple(2, i, 2, i + 1));
	for (int i = u1; i > u2; i--) FinalAns.push_back(make_tuple(2, i, 2, i - 1));
	for (int i = u2; i < u1; i++) FinalAns.push_back(make_tuple(3, i, 3, i + 1));
	for (int i = u2; i > u1; i--) FinalAns.push_back(make_tuple(3, i, 3, i - 1));
	FinalAns.push_back(make_tuple(2, u2, 1, u2));
	FinalAns.push_back(make_tuple(3, u1, 2, u1));
	FinalAns.push_back(make_tuple(2, u1, 1, u1));
}

bool check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (DD[i][j] != DE[i][j]) return false;
		}
	}
	return true;
}

int main() {
	cin >> N >> K;

	// Step 1 - A: 
	for (int i = 1; i <= K; i++) {
		int cx, cy; cin >> cx >> cy; DD[cx][cy] = i;
		tup1.push_back(make_tuple(cx, cy, i));
		A[cx].push_back(make_pair(cy, i));
	}
	sort(tup1.begin(), tup1.end());
	for (int i = 1; i <= N; i++) sort(A[i].begin(), A[i].end());

	// Step 1 - B: 
	for (int i = 1; i <= K; i++) {
		int cx, cy; cin >> cx >> cy; DE[cx][cy] = i;
		tup2.push_back(make_tuple(cx, cy, i));
		B[cx].push_back(make_pair(cy, i));
	}
	sort(tup2.begin(), tup2.end());
	for (int i = 1; i <= N; i++) sort(B[i].begin(), B[i].end());

	if (N == 2) {
		// ---------------------- N = 2  --------------
		for (int t = 0; t < 10800; t++) {
			bool I = check();
			if (I == true) break;

			while (true) {
				int cx = rand() % N + 1, cy = rand() % N + 1, dx = rand() % N + 1, dy = rand() % N + 1;
				if (abs(cx - dx) + abs(cy - dy) == 1 && DD[cx][cy] != 0 && DD[dx][dy] == 0) {
					swap(DD[cx][cy], DD[dx][dy]);
					FinalAns.push_back(make_tuple(cx, cy, dx, dy));
					break;
				}
			}
		}
	}
	if (N >= 3) {
		// ---------------------- N >= 3  --------------------

		// Step 1 - C: 
		for (int i = 0; i < tup1.size(); i++) { C1[get<0>(tup1[i])][get<1>(tup1[i])] = i + 1; Before[get<2>(tup1[i])] = i + 1; }
		for (int i = 0; i < tup2.size(); i++) { C2[get<0>(tup2[i])][get<1>(tup2[i])] = i + 1; After[get<2>(tup2[i])] = i + 1; }

		// Step 2 - A: 
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < A[i].size(); j++) {
				int start = A[i][j].first, goal = C1[i][A[i][j].first]; if (start < goal) continue;
				for (int j = start; j > goal; j--) FinalAns.push_back(make_tuple(i, j, i, j - 1));
				for (int j = i; j > 1; j--) FinalAns.push_back(make_tuple(j, goal, j - 1, goal));
			}
			for (int j = A[i].size() - 1; j >= 0; j--) {
				int start = A[i][j].first, goal = C1[i][A[i][j].first]; if (start >= goal) continue;
				for (int j = start; j < goal; j++) FinalAns.push_back(make_tuple(i, j, i, j + 1));
				for (int j = i; j > 1; j--) FinalAns.push_back(make_tuple(j, goal, j - 1, goal));
			}
		}

		for (int i = 0; i < FinalAns.size(); i++) { swap(DD[get<0>(FinalAns[i])][get<1>(FinalAns[i])], DD[get<2>(FinalAns[i])][get<3>(FinalAns[i])]); }
		int sz1 = FinalAns.size();

		// Step 2 - B: 
		for (int i = 1; i <= K; i++) {
			int v1 = -1, v2 = -1;
			for (int j = 0; j < tup1.size(); j++) {
				if (get<2>(tup1[j]) == i) v1 = j;
				if (get<2>(tup2[j]) == i) v2 = j;
			}
			if (v1 == v2) continue;
			swaps(v1 + 1, v2 + 1);
			swap(get<2>(tup1[v1]), get<2>(tup1[v2]));
		}

		for (int i = sz1; i < FinalAns.size(); i++) { swap(DD[get<0>(FinalAns[i])][get<1>(FinalAns[i])], DD[get<2>(FinalAns[i])][get<3>(FinalAns[i])]); }
		int sz2 = FinalAns.size();

		// Step 2 - C: 
		for (int i = N; i >= 1; i--) {
			for (int j = 0; j < B[i].size(); j++) {
				int start = C2[i][B[i][j].first], goal = B[i][j].first; if (start < goal) continue;
				for (int j = 1; j < i; j++) FinalAns.push_back(make_tuple(j, start, j + 1, start));
				for (int j = start; j > goal; j--) FinalAns.push_back(make_tuple(i, j, i, j - 1));
			}
			for (int j = B[i].size() - 1; j >= 0; j--) {
				int start = C2[i][B[i][j].first], goal = B[i][j].first; if (start >= goal) continue;
				for (int j = 1; j < i; j++) FinalAns.push_back(make_tuple(j, start, j + 1, start));
				for (int j = start; j < goal; j++) FinalAns.push_back(make_tuple(i, j, i, j + 1));
			}
		}

		for (int i = sz2; i < FinalAns.size(); i++) { swap(DD[get<0>(FinalAns[i])][get<1>(FinalAns[i])], DD[get<2>(FinalAns[i])][get<3>(FinalAns[i])]); }
	}

	// Step 3: 
	cout << FinalAns.size() << endl;
	for (int i = 0; i < FinalAns.size(); i++) {
		cout << get<0>(FinalAns[i]) << " " << get<1>(FinalAns[i]) << " " << get<2>(FinalAns[i]) << " " << get<3>(FinalAns[i]) << endl;
	}
	return 0;
}