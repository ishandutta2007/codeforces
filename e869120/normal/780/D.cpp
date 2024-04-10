#include<iostream>
#include<string>
#include<tuple>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;
int col[26]; string R[1000]; int n; string S[1000], T[1000];

bool solve(vector<tuple<int, int, int>>a) {
	for (int i = 0; i < 26; i++) {
		vector<int>Y;
		for (int j = 0; j < a.size(); j++) { if (get<0>(a[j]) == i)Y.push_back(j); }
		if (Y.size() >= 2) { for (int j = 0; j < Y.size(); j++)get<0>(a[Y[j]]) = -1; }
		Y.clear();
		for (int j = 0; j < a.size(); j++) { if (get<1>(a[j]) == i)Y.push_back(j); }
		if (Y.size() >= 2) { for (int j = 0; j < Y.size(); j++)get<1>(a[Y[j]]) = -1; }
	}
	for (int i = 0; i < a.size(); i++) { if (get<0>(a[i]) == -1 && get<1>(a[i]) == -1)return false; }
	for (int i = 0; i < 26; i++)col[i] = 0;
	while (true) {
		bool I = false;
		for (int i = 0; i < a.size(); i++) {
			if (get<0>(a[i]) == get<1>(a[i]) || get<0>(a[i]) == -1 || get<1>(a[i]) == -1) {
				int P = max(get<0>(a[i]), get<1>(a[i])); if (P == -1)continue;
				if (col[P] == true) { return false; }
				col[P] = 1; R[get<2>(a[i])] += ('A' + P); a[i] = make_tuple(-1, -1, -1); I = true;
				for (int j = 0; j < a.size(); j++) {
					if (get<0>(a[j]) == P) { get<0>(a[j]) = -1; if (get<1>(a[j]) == -1)return false; }
					if (get<1>(a[j]) == P) { get<1>(a[j]) = -1; if (get<0>(a[j]) == -1)return false; }
				}
			}
		}
		if (I == false)break;
	}
	vector<tuple<int, int, int>>U;
	for (int i = 0; i < a.size(); i++) { if (get<0>(a[i]) != -1)U.push_back(a[i]); }

	//SAT  
	if (U.size() >= 27)return false;
	for (int h = 0; h < U.size() * 4000 + 1; h++) {
		vector<int>G; bool OK = true;
		for (int i = 0; i < 26; i++)col[i] = 0;
		for (int i = 0; i < U.size(); i++) {
			if (col[get<0>(U[i])] == -1 && col[get<1>(U[i])] == -1) { OK = false; break; }
			else if (col[get<0>(U[i])] == -1) { G.push_back(1); col[get<1>(U[i])] = -1; }
			else if (col[get<1>(U[i])] == -1) { G.push_back(0); col[get<0>(U[i])] = -1; }
			else { int J = rand() % 2; if (J == 0) { G.push_back(0); col[get<0>(U[i])] = -1; } else { G.push_back(1); col[get<1>(U[i])] = -1; } }
		}
		if (OK == true) {
			for (int i = 0; i < U.size(); i++) {
				if (G[i] == 0)R[get<2>(U[i])] += ('A' + get<0>(U[i]));
				if (G[i] == 1)R[get<2>(U[i])] += ('A' + get<1>(U[i]));
			}
			return true;
		}
	}
	return false;
}
int main() {
	srand((unsigned)time(NULL));
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> S[i] >> T[i]; R[i] = S[i].substr(0, 2); }
	for (int i = 0; i < 676; i++) {
		string Y; Y += ('A' + (i / 26)); Y += ('A' + (i % 26));
		vector<tuple<int, int, int>>J;
		for (int j = 0; j < n; j++) { if (S[j].substr(0, 2) == Y)J.push_back(make_tuple(S[j][2] - 'A', T[j][0] - 'A', j)); }
		if (J.size() == 0)continue;
		bool I = solve(J);
		if (I == false) { cout << "NO" << endl; return 0; }
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++)cout << R[i] << endl;
	return 0;
}