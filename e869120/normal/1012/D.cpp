#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int LA[1 << 18], LB[1 << 18]; vector<pair<int, int>> rem;

void dfs(vector<pair<char, int>> A1, vector<pair<char, int>> A2, vector<pair<int, int>>S) {
	if (A1.size() == 1 && A2.size() == 1) {
		if (S.size() < rem.size()) rem = S;
		return;
	}
	if (S.size() >= 3) return;

	int sum1 = 0, sum2 = 0;
	for (int i = 0; i <= A1.size(); i++) {
		sum2 = 0;
		for (int j = 0; j <= A2.size(); j++) {
			vector<pair<char, int>> C1, C2;
			for (int k = 0; k < i; k++) C2.push_back(A1[k]);
			for (int k = 0; k < j; k++) C1.push_back(A2[k]);
			for (int k = i; k < A1.size(); k++) {
				if (C1.size() >= 1 && C1[C1.size() - 1].first == A1[k].first) C1[C1.size() - 1].second += A1[k].second;
				else C1.push_back(A1[k]);
			}
			for (int k = j; k < A2.size(); k++) {
				if (C2.size() >= 1 && C2[C2.size() - 1].first == A2[k].first) C2[C2.size() - 1].second += A2[k].second;
				else C2.push_back(A2[k]);
			}

			vector<pair<int, int>>C3 = S; C3.push_back(make_pair(sum1, sum2));

			dfs(C1, C2, C3);

			if (j < A2.size()) sum2 += A2[j].second;
		}
		if (i < A1.size()) sum1 += A1[i].second;
	}
}

vector<pair<int, int>> small_solve(vector<pair<char, int>>A1, vector<pair<char, int>>A2) {
	for (int i = 0; i < 9; i++) rem.push_back(make_pair(-1, -1));
	dfs(A1, A2, vector<pair<int, int>>{});
	return rem;
}

vector<pair<int, int>> solve_same(vector<int>A1, vector<int>A2) {
	vector<pair<int, int>>ans;

	for (int i = 0; i < A1.size(); i++) LA[i] = A1[i];
	for (int i = 0; i < A2.size(); i++) LB[i] = A2[i];

	int c1 = 0, c2 = 0;
	for (int i = 0; i < ((int)A1.size() - 2) / 2; i++) {
		ans.push_back(make_pair(LA[c1] + LA[c1 + 1], LB[c2]));
		int p1 = LA[c1 + 2] + LB[c2];
		int p2 = LA[c1];
		int p3 = LA[c1 + 1] + LB[c2 + 1];
		LA[c1] = 0;
		LA[c1 + 1] = 0;
		LA[c1 + 2] = p1;
		LB[c2] = p2;
		LB[c2 + 1] = p3;
		c1 += 2;
	}

	for (int i = 0; i < ((int)A2.size() - 2) / 2; i++) {
		ans.push_back(make_pair(LA[c1], LB[c2] + LB[c2 + 1]));
		int p1 = LB[c2 + 2] + LA[c1];
		int p2 = LB[c2];
		int p3 = LB[c2 + 1] + LA[c1 + 1];
		LB[c2] = 0;
		LB[c2 + 1] = 0;
		LB[c2 + 2] = p1;
		LA[c1] = p2;
		LA[c1 + 1] = p3;
		c2 += 2;
	}

	vector<pair<char, int>>V1, V2;
	for (int i = c1; i < A1.size(); i++) { V1.push_back(make_pair('a', LA[i])); }
	for (int i = c2; i < A2.size(); i++) { V2.push_back(make_pair('b', LB[i])); }
	for (int i = 0; i < V1.size(); i++) { if (i % 2 == 0) V1[i].first = 'a'; else V1[i].first = 'b'; }
	for (int i = 0; i < V2.size(); i++) { if (i % 2 == 0) V2[i].first = 'a'; else V2[i].first = 'b'; }

	vector<pair<int, int>> ret = small_solve(V1, V2);
	for (int i = 0; i < ret.size(); i++) ans.push_back(ret[i]);

	return ans;
}

vector<pair<int, int>> solve_diff(vector<int>A1, vector<int>A2) {
	vector<pair<int, int>>ans;

	if (abs((int)A1.size() - (int)A2.size()) >= 3) {
		int c1 = A1.size(), c2 = A2.size(), d1 = 1, d2 = 1;
		while (abs(c1 - c2) >= 3) {
			if (c1 - c2 >= 3) { c1 -= 2; c2 += 2; d1 += 2; }
			if (c2 - c1 >= 3) { c2 -= 2; c1 += 2; d2 += 2; }
		}

		vector<int>P1, P2; int s1 = 0, s2 = 0;
		for (int i = 0; i < d1; i++) { P2.push_back(A1[i]); s1 += A1[i]; }
		for (int i = 0; i < d2; i++) { P1.push_back(A2[i]); s2 += A2[i]; }
		ans.push_back(make_pair(s1, s2));
		if (d1 < A1.size()) P1[P1.size() - 1] += A1[d1]; for (int i = d1 + 1; i < A1.size(); i++) P1.push_back(A1[i]);
		if (d2 < A2.size()) P2[P2.size() - 1] += A2[d2]; for (int i = d2 + 1; i < A2.size(); i++) P2.push_back(A2[i]);

		A1 = P1; A2 = P2;
	}

	for (int i = 0; i < A1.size(); i++) LA[i] = A1[i];
	for (int i = 0; i < A2.size(); i++) LB[i] = A2[i];

	for (int i = 0; i < min((int)A1.size(), (int)A2.size()) - 1; i++) {
		ans.push_back(make_pair(LA[i], LB[i]));
		LB[i + 1] += LA[i]; LA[i] = 0;
		LA[i + 1] += LB[i]; LB[i] = 0;
	}

	vector<pair<char, int>>V1, V2;
	for (int i = min((int)A1.size(), (int)A2.size()) - 1; i < A1.size(); i++) { V1.push_back(make_pair('a', LA[i])); }
	for (int i = min((int)A1.size(), (int)A2.size()) - 1; i < A2.size(); i++) { V2.push_back(make_pair('b', LB[i])); }
	for (int i = 0; i < V1.size(); i++) { if (i % 2 == 0) V1[i].first = 'a'; else V1[i].first = 'b'; }
	for (int i = 0; i < V2.size(); i++) { if (i % 2 == 0) V2[i].first = 'b'; else V2[i].first = 'a'; }

	vector<pair<int, int>> ret = small_solve(V1, V2);
	for (int i = 0; i < ret.size(); i++) ans.push_back(ret[i]);

	return ans;
}

int main() {
	string S1, S2; cin >> S1 >> S2;

	vector<int> B1, B2; int cnt = 0;
	cnt = 0; for (int i = 0; i < S1.size(); i++) { cnt++; if (i == S1.size() - 1 || S1[i] != S1[i + 1]) { B1.push_back(cnt); cnt = 0; } }
	cnt = 0; for (int i = 0; i < S2.size(); i++) { cnt++; if (i == S2.size() - 1 || S2[i] != S2[i + 1]) { B2.push_back(cnt); cnt = 0; } }


	vector<pair<int, int>>ans;
	if (S1[0] != S2[0]) ans = solve_diff(B1, B2);
	else {
		if (B1.size() == 1 && B2.size() >= 3) {
			B1 = { 0, B1[0] };
			ans = solve_diff(B1, B2);
		}
		else if (B1.size() >= 3 && B2.size() == 1) {
			B2 = { 0, B2[0] };
			ans = solve_diff(B1, B2);
		}
		else {
			ans = solve_same(B1, B2);
		}
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}