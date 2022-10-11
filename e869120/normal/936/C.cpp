#include <iostream>
#include <vector>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

pair<int, int> renketsu(int pos, vector<int>R) {
	int t1 = pos, t2 = pos;

	// 
	if (pos >= 1 && (R[pos] - R[pos - 1] + (int)R.size()) % (int)R.size() == 1) {
		int cx = R[pos];
		for (int i = pos; i >= 0; i--) {
			if (R[i] == cx) { t1 = i; }
			else break;
			cx--; cx += R.size(); cx %= R.size();
		}
	}
	if (pos >= 1 && (R[pos] - R[pos - 1] + (int)R.size()) % (int)R.size() == (int)R.size() - 1) {
		int cx = R[pos];
		for (int i = pos; i >= 0; i--) {
			if (R[i] == cx) { t1 = i; }
			else break;
			cx++; cx %= R.size();
		}
	}

	// 
	if (pos < (int)R.size() - 1 && (R[pos] - R[pos + 1] + (int)R.size()) % (int)R.size() == 1) {
		int cx = R[pos];
		for (int i = pos; i < R.size(); i++) {
			if (R[i] == cx) { t2 = i; }
			else break;
			cx--; cx += R.size(); cx %= R.size();
		}
	}
	if (pos < (int)R.size() - 1 && (R[pos] - R[pos + 1] + (int)R.size()) % (int)R.size() == (int)R.size() - 1) {
		int cx = R[pos];
		for (int i = pos; i < R.size(); i++) {
			if (R[i] == cx) { t2 = i; }
			else break;
			cx++; cx %= R.size();
		}
	}
	return make_pair(t1, t2);
}

vector<int> sousa(int pos, vector<int>R) {
	vector<int>RR;
	for (int i = R.size() - 1; i >= pos; i--) RR.push_back(R[i]);
	for (int i = 0; i < pos; i++) RR.push_back(R[i]);
	//for (int i = 0; i < RR.size(); i++) cout << RR[i] << " "; cout << endl;
	return RR;
}

vector<int> solve(vector<int>R) {
	if (R.size() == 1) return vector<int>{};

	vector<int>ans;

	while (true) {
		int Z = (R[0] + 1) % R.size();
		if ((R[0] - R[1] + (int)R.size()) % (int)R.size() == 1) Z = (R[0] + 1) % R.size();
		if ((R[1] - R[0] + (int)R.size()) % (int)R.size() == 1) Z = (R[0] + R.size() - 1) % R.size();

		int ind = -1; for (int i = 0; i < R.size(); i++) { if (R[i] == Z) ind = i; }
		pair<int, int> Z1 = renketsu(0, R);
		pair<int, int> Z2 = renketsu(ind, R);

		if (Z1.first == 0 && Z1.second == R.size() - 1) break;

		if (Z2.first == ind) {
			ans.push_back(ind); R = sousa(ind, R);
		}
		else {
			ans.push_back(0); R = sousa(0, R);
			ans.push_back((int)R.size() - Z1.second - 1); R = sousa((int)R.size() - Z1.second - 1, R);

			int pos1 = -1; for (int i = 0; i < R.size(); i++) { if (R[i] == Z) pos1 = i; }
			ans.push_back(pos1); R = sousa(pos1, R);
		}
	}

	if ((R[1] - R[0] + (int)R.size()) % (int)R.size() == (int)R.size() - 1) {
		ans.push_back(0); R = sousa(0, R);
	}
	if ((R[1] - R[0] + (int)R.size()) % (int)R.size() == 1) {
		int S = R.size() - R[0];
		ans.push_back(S); R = sousa(S, R);
		ans.push_back(R.size() - S); R = sousa(R.size() - S, R);
		ans.push_back(0); R = sousa(0, R);
	}
	return ans;
}

int main() {
	string S, T; int N; cin >> N >> S >> T;

	vector<int> id(S.size(), -1);
	for (int i = 0; i < T.size(); i++) {
		bool flag = false;
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == T[i] && id[j] == -1) { id[j] = i; flag = true; break; }
		}
		if (flag == false) {
			cout << "-1" << endl;
			return 0;
		}
	}

	vector<int>ans = solve(id);
	
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) { if (i) cout << " "; cout << N - ans[i]; } cout << endl;
	return 0;
}