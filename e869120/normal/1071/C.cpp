#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#pragma warning (disable: 4996)

// --------------- Solve with small cases --------------------

int dist[1 << 18], prevs[1 << 18]; vector<int>mask;

vector<tuple<int, int, int>> small_solve(vector<int> vec) {
	mask.clear();
	int M = vec.size();
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			for (int k = j + 1; k < M; k++) {
				if (k - j == j - i) mask.push_back((1 << i) + (1 << j) + (1 << k));
			}
		}
	}
	int start = 0; for (int i = 0; i < M; i++) start += vec[i] * (1 << i);

	queue<int>Q;
	for (int i = 0; i < (1 << M); i++) { dist[i] = (1 << 30); prevs[i] = -1; }
	dist[start] = 1; prevs[start] = -1; Q.push(start);

	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		for (int rem : mask) {
			if (dist[pos ^ rem] > dist[pos] + 1) {
				dist[pos ^ rem] = dist[pos] + 1;
				Q.push(pos ^ rem);
				prevs[pos ^ rem] = pos;
			}
		}
	}

	if (dist[0] == (1 << 30)) return vector<tuple<int, int, int>>{make_tuple(-1, -1, -1)};

	vector<tuple<int, int, int>>ans;
	int cx = 0;
	while (true) {
		if (cx == start) break;

		int cy = prevs[cx], r = (cx ^ cy);
		vector<int>V; for (int i = 0; i < M; i++) { if ((r / (1 << i)) % 2 == 1) V.push_back(i); }
		ans.push_back(make_tuple(V[0], V[1], V[2]));
		cx = prevs[cx];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

vector<tuple<int, int, int>> medium_solve(vector<int>vec) {
	// vec  6 
	vector<tuple<int, int, int, int>>R;
	for (int i = 0; i < 13; i++) {
		for (int j = i + 1; j < 13; j++) {
			for (int k = j + 1; k < 13; k++) {
				if (j - i == k - j && j <= 6) R.push_back(make_tuple((1 << i) + (1 << j) + (1 << k), i, j, k));
			}
		}
	}

	int start = 0; for (int i = 0; i < vec.size(); i++) start += vec[i] * (1 << i);
	if (start == 0) return vector<tuple<int, int, int>>{};
	
	for (int i = 0; i < R.size(); i++) {
		if (start != (get<0>(R[i]) & 63)) continue;
		return vector<tuple<int, int, int>>{make_tuple(get<1>(R[i]), get<2>(R[i]), get<3>(R[i]))};
	}

	for (int i = 0; i < R.size(); i++) {
		for (int j = i + 1; j < R.size(); j++) {
			if (start != ((get<0>(R[i]) & 63) ^ (get<0>(R[j]) & 63))) continue;
			return vector<tuple<int, int, int>>{make_tuple(get<1>(R[i]), get<2>(R[i]), get<3>(R[i])), make_tuple(get<1>(R[j]), get<2>(R[j]), get<3>(R[j]))};
		}
	}
	return vector<tuple<int, int, int>>{make_tuple(-1, -1, -1)};
}

vector<tuple<int, int, int>> large_solve(vector<int>vec) {
	if (vec.size() <= 18) return small_solve(vec);

	int S = 0; vector<tuple<int, int, int>>Z;
	for (int i = 0; i < (int)vec.size() - 18; i += 6) {
		vector<int> Y = { vec[i + 0], vec[i + 1],vec[i + 2],vec[i + 3],vec[i + 4],vec[i + 5] };
		vector<tuple<int, int, int>> A = medium_solve(Y);
		for (int j = 0; j < A.size(); j++) {
			Z.push_back(make_tuple(i + get<0>(A[j]), i + get<1>(A[j]), i + get<2>(A[j])));
			vec[i + get<0>(A[j])] ^= 1;
			vec[i + get<1>(A[j])] ^= 1;
			vec[i + get<2>(A[j])] ^= 1;
		}
		S += 6;
	}

	vector<int>YY; for (int i = S; i < vec.size(); i++) YY.push_back(vec[i]);
	vector<tuple<int, int, int>> AA = small_solve(YY);
	for (int i = 0; i < AA.size(); i++) {
		Z.push_back(make_tuple(S + get<0>(AA[i]), S + get<1>(AA[i]), S + get<2>(AA[i])));
		vec[S + get<0>(AA[i])] ^= 1;
		vec[S + get<1>(AA[i])] ^= 1;
		vec[S + get<2>(AA[i])] ^= 1;
	}
	if (AA == vector<tuple<int, int, int>>{make_tuple(-1, -1, -1)}) return vector<tuple<int, int, int>>{make_tuple(-1, -1, -1)};
	return Z;
}

int main() {
	int n, a; vector<int>VV;
	scanf("%d", &n); for (int i = 0; i < n; i++) { scanf("%d", &a); VV.push_back(a); }
	vector<tuple<int, int, int>> I = large_solve(VV);
	
	if (I == vector<tuple<int, int, int>> {make_tuple(-1, -1, -1)}) {
		cout << "NO" << endl;
		return 0;
	}

	printf("YES\n");
	printf("%d\n", (int)I.size());
	for (int i = 0; i < I.size(); i++) printf("%d %d %d\n", get<0>(I[i]) + 1, get<1>(I[i]) + 1, get<2>(I[i]) + 1);
	return 0;
}