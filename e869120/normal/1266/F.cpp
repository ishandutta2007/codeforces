#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

class SushiLikeDataStructure {
public:
	set<pair<int, int>> Set;

	void update(int pos, int x) {
		auto itr = Set.lower_bound(make_pair(pos, -1));
		if (itr == Set.end()) Set.insert(make_pair(pos, x));
		else {
			int fx = (*itr).second;
			if (fx >= x) return;
			while (true) {
				auto itr = Set.lower_bound(make_pair(pos, 1 << 30));
				if (itr == Set.begin()) break;
				itr--;
				if ((*itr).second > x) break;
				Set.erase(itr);
			}
			Set.insert(make_pair(pos, x));
		}
	}
	vector<pair<int, int>> getans() {
		vector<pair<int, int>> Z;
		auto itr = Set.begin();
		while (itr != Set.end()) {
			Z.push_back(*itr);
			itr++;
		}
		return Z;
	}
};

// 
int N, A[1 << 19], B[1 << 19];

// 
vector<int> X[1 << 19], Y[1 << 19];
bool used[1 << 19];
int maxdist[1 << 19];
int uradist[1 << 19];

// 
int ans1[1 << 19], ans2[1 << 19], ans3[1 << 19];
int FinalAns[1 << 19];

void dfs1(int pos) {
	used[pos] = true;
	for (int i : X[pos]) {
		if (used[i] == true) continue;
		dfs1(i);
		Y[pos].push_back(i);
		maxdist[pos] = max(maxdist[pos], maxdist[i] + 1);
	}
}

void dfs2(int pos) {
	vector<pair<int, int>> R;
	for (int i : Y[pos]) {
		R.push_back(make_pair(maxdist[i] + 1, i));
	}
	sort(R.begin(), R.end());
	reverse(R.begin(), R.end());
	for (int i : Y[pos]) {
		int maxp = uradist[pos] + 1;
		for (int j = 0; j < R.size(); j++) {
			if (R[j].second == i) continue;
			maxp = max(maxp, R[j].first + 1);
			break;
		}
		uradist[i] = maxp;
	}
	for (int i : Y[pos]) dfs2(i);
}

int main() {
	//  1. 
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d%d", &A[i], &B[i]);
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}

	//  2. maxdist 
	dfs1(1);
	dfs2(1);

	//  3. ans1 
	SushiLikeDataStructure V1;
	for (int i = 1; i <= N; i++) {
		vector<int> I;
		for (int j : Y[i]) I.push_back(maxdist[j] + 1);
		if (i >= 2) I.push_back(uradist[i]);
		sort(I.begin(), I.end());
		reverse(I.begin(), I.end());
		for (int j = 0; j < I.size(); j++) V1.update(I[j], j + 1);
	}
	vector<pair<int, int>> W1 = V1.getans();
	for (int i = 0; i < W1.size(); i++) ans1[W1[i].first] = W1[i].second;
	for (int i = N; i >= 1; i--) ans1[i] = max(ans1[i], ans1[i + 1]);

	//  4. ans2 
	SushiLikeDataStructure V2;
	for (int i = 1; i <= N; i++) {
		vector<int> I;
		for (int j : Y[i]) I.push_back(maxdist[j] + 1);
		if (i >= 2) I.push_back(uradist[i]);
		sort(I.begin(), I.end());
		reverse(I.begin(), I.end());
		for (int j = 0; j < I.size(); j++) {
			V2.update(I[j], j + 1);
			if (j == 0 || I[j - 1] > I[j]) V2.update(I[j] + 1, j + 1);
		}
	}
	vector<pair<int, int>> W2 = V2.getans();
	for (int i = 0; i < W2.size(); i++) ans2[W2[i].first] = W2[i].second;
	for (int i = N; i >= 1; i--) ans2[i] = max(ans2[i], ans2[i + 1]);

	//  5. ans3 
	SushiLikeDataStructure V3;
	for (int i = 1; i <= N; i++) {
		SushiLikeDataStructure V4;
		for (int j : Y[i]) {
			vector<pair<int, int>> T;
			T.push_back(make_pair(maxdist[j] + 1, -1));
			for (int k : Y[j]) T.push_back(make_pair(maxdist[k] + 1, 1));
			sort(T.begin(), T.end());
			reverse(T.begin(), T.end());
			int sum = 0;
			for (int k = 0; k < T.size(); k++) {
				sum += T[k].second;
				if (k + 1 == T.size() || T[k + 1].first != T[k].first) V4.update(T[k].first, sum);
			}
		}
		vector<pair<int, int>> U = V4.getans();
		vector<pair<int, int>> U2;
		for (int j = 0; j < U.size(); j++) {
			int pres = 0; if (j + 1 < U.size()) pres = U[j + 1].second;
			U2.push_back(make_pair(U[j].first, U[j].second - pres));
		}
		for (int j : Y[i]) U2.push_back(make_pair(maxdist[j] + 1, 1));
		if (uradist[i] >= 1) U2.push_back(make_pair(uradist[i], 1));
		sort(U2.begin(), U2.end());
		reverse(U2.begin(), U2.end());
		int sum = 0;
		for (int j = 0; j < U2.size(); j++) {
			sum += U2[j].second;
			if (j + 1 == U2.size() || U2[j + 1].first != U2[j].first) V3.update(U2[j].first, sum);
		}
	}
	vector<pair<int, int>> W3 = V3.getans();
	for (int i = 0; i < W3.size(); i++) ans3[W3[i].first] = W3[i].second;
	for (int i = N; i >= 1; i--) ans3[i] = max(ans3[i], ans3[i + 1]);

	//  6. 
	for (int i = 1; i <= N; i++) FinalAns[i] = 1;
	for (int i = 1; i <= N / 2 + 1; i++) {
		FinalAns[i * 2 - 1] = max(FinalAns[i * 2 - 1], ans1[i]);
		FinalAns[i * 2 + 0] = max(FinalAns[i * 2 + 0], ans1[i]);
		FinalAns[i * 2 - 1] = max(FinalAns[i * 2 - 1], ans2[i]);
		FinalAns[i * 2 + 0] = max(FinalAns[i * 2 + 0], ans3[i]);
	}
	for (int i = 1; i <= N; i++) FinalAns[1] = max(FinalAns[1], (int)X[i].size() + 1);

	//  7. 
	for (int i = 1; i <= N; i++) {
		if (i >= 2) printf(" ");
		printf("%d", FinalAns[i]);
	}
	printf("\n");
	return 0;
}