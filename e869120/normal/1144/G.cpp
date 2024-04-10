#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

const int INF = (1 << 30);
int N, A[1 << 18], cl[1 << 18], cr[1 << 18], dl[1 << 18], dr[1 << 18]; // (cl, cr], (dl, dr]

bool increase(vector<int>V) {
	for (int i = 0; i < (int)V.size() - 1; i++) {
		if (V[i] >= V[i + 1]) return false;
	}
	return true;
}

bool decrease(vector<int>V) {
	for (int i = 0; i < (int)V.size() - 1; i++) {
		if (V[i] <= V[i + 1]) return false;
	}
	return true;
}

bool solve1(int pos) {
	vector<int>v1, v2;
	for (int i = 1; i <= pos; i++) {
		if (A[i] >= A[pos]) v1.push_back(A[i]);
		else v2.push_back(A[i]);
	}
	if (decrease(v1) == true && increase(v2) == true) return true;
	return false;
}

bool solve2(int pos) {
	vector<int> v1, v2;
	for (int i = pos; i <= N; i++) {
		if (A[i] >= A[pos]) v1.push_back(A[i]);
		else v2.push_back(A[i]);
	}
	if (decrease(v2) == true && increase(v1) == true) return true;
	return false;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

	for (int i = 1; i <= N; i++) { cl[i] = INF; cr[i] = -INF; dl[i] = INF; dr[i] = -INF; }
	cl[0] = -INF; cr[0] = INF; dl[N + 1] = -INF; dr[N + 1] = INF;

	// Set  /  (Use set)
	set<int>Set;
	Set.insert(-INF); Set.insert(INF);
	for (int i = 1; i <= N; i++) {
		auto itr = Set.lower_bound(A[i]);
		if (*itr == A[i]) break;

		cr[i] = *itr; itr--;
		cl[i] = *itr;
		Set.insert(A[i]);
	}

	Set.clear();
	Set.insert(-INF); Set.insert(INF);
	for (int i = N; i >= 1; i--) {
		auto itr = Set.lower_bound(A[i]);
		if (*itr == A[i]) break;

		dr[i] = *itr; itr--;
		dl[i] = *itr;
		Set.insert(A[i]);
	}

	//  (Binary Search)
	int L1 = 1, R1 = N + 1, M1, maxn = 0;
	for (int i = 0; i < 25; i++) {
		M1 = (L1 + R1) / 2;
		bool t1 = solve1(M1);
		if (t1 == true) { maxn = max(maxn, M1); L1 = M1; }
		else { R1 = M1; }
	}

	int L2 = 1, R2 = N + 1, M2, minx = N + 1;
	for (int i = 0; i < 25; i++) {
		M2 = (L2 + R2) / 2;
		bool t2 = solve2(M2);
		if (t2 == true) { minx = min(minx, M2); R2 = M2; }
		else { L2 = M2; }
	}

	//  (Final Choice)
	for (int i = 0; i <= N; i++) {
		if (maxn < i || i + 1 < minx) continue;
		int pl = max(cl[i], dl[i + 1]), pr = min(cr[i], dr[i + 1]);
		if (pl >= pr) continue;

		printf("YES\n");
		for (int j = 1; j <= N; j++) {
			if (j >= 2) printf(" ");
			if (j <= i) {
				if (A[j] >= pr) printf("1");
				else printf("0");
			}
			else {
				if (A[j] >= pr) printf("0");
				else printf("1");
			}
		}
		printf("\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}