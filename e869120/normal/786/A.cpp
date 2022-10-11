#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dp1[10000], dp2[10000], col1[10000], col2[10000], n, c1, c2, a1[10000], a2[10000];
void solve(vector<int>P, vector<int>Q) {
	for (int i = 0; i < n; i++) { dp1[i] = 0; dp2[i] = 0; col1[i] = P.size(); col2[i] = Q.size(); }
	dp1[0] = -1; dp2[0] = -1; queue<pair<int, int>>Q1; Q1.push(make_pair(0, 0)); Q1.push(make_pair(0, 1));
	while (!Q1.empty()) {
		int r1 = Q1.front().first, r2 = Q1.front().second; Q1.pop();
		if (r2 == 0) {
			if (dp1[r1] == -1) {
				for (int i = 0; i < Q.size(); i++) { if (dp2[(n + r1 - Q[i]) % n] == 0) { dp2[(n + r1 - Q[i]) % n] = 1; Q1.push(make_pair((n + r1 - Q[i]) % n, 1)); } }
			}
			else {
				for (int i = 0; i < Q.size(); i++) { col2[(n + r1 - Q[i]) % n]--; if (col2[(n + r1 - Q[i]) % n] == 0) { dp2[(n + r1 - Q[i]) % n] = -1; Q1.push(make_pair((n + r1 - Q[i]) % n, 1)); } }
			}
		}
		else {
			if (dp2[r1] == -1) {
				for (int i = 0; i < P.size(); i++) { if (dp1[(n + r1 - P[i]) % n] == 0) { dp1[(n + r1 - P[i]) % n] = 1; Q1.push(make_pair((n + r1 - P[i]) % n, 0)); } }
			}
			else {
				for (int i = 0; i < P.size(); i++) { col1[(n + r1 - P[i]) % n]--; if (col1[(n + r1 - P[i]) % n] == 0) { dp1[(n + r1 - P[i]) % n] = -1; Q1.push(make_pair((n + r1 - P[i]) % n, 0)); } }
			}
		}
	}
}
int main() {
	cin >> n; vector<int>v1, v2;
	cin >> c1; for (int i = 0; i < c1; i++) { cin >> a1[i]; v1.push_back(a1[i]); }
	cin >> c2; for (int i = 0; i < c2; i++) { cin >> a2[i]; v2.push_back(a2[i]); }
	solve(v1, v2); for (int i = 1; i < n; i++) { if (i >= 2)cout << ' '; if (dp1[i] == 1)cout << "Win"; if (dp1[i] == 0)cout << "Loop"; if (dp1[i] == -1)cout << "Lose"; }cout << endl;
	solve(v2, v1); for (int i = 1; i < n; i++) { if (i >= 2)cout << ' '; if (dp1[i] == 1)cout << "Win"; if (dp1[i] == 0)cout << "Loop"; if (dp1[i] == -1)cout << "Lose"; }cout << endl;
	return 0;
}