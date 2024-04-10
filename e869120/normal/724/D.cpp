#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int D, cc[26];
string S; vector<int>V[26];
vector<int>V2[100009];

int solve2(int len, vector<int>B) {
	int cx = 0, cntv = 0; B.push_back(len);
	for (int i = 0; i < (int)B.size() - 1; i++) {
		if (B[i + 1] - cx > D) { cx = B[i]; cntv++; }
	}
	return cntv;
}

string solve(int pos) {
	vector<int>V1; V1.push_back(-1);
	for (int i = 0; i < S.size(); i++) {
		if (S[i] < ('a' + pos)) V1.push_back(i);
	}
	V1.push_back(S.size());

	for (int i = 0; i < S.size(); i++) {
		if (S[i] != ('a' + pos)) continue;
		int pos1 = lower_bound(V1.begin(), V1.end(), i) - V1.begin(); pos1--;
		V2[pos1].push_back(i - V1[pos1]);
	}

	for (int i = 0; i < (int)V1.size() - 1; i++) {
		int Z = solve2(V1[i + 1] - V1[i], V2[i]);
		cc[pos] += Z;
	}
	for (int i = 0; i < S.size(); i++) {
		if (S[i] < ('a' + pos)) cc[S[i] - 'a']++;
	}

	string str = "";
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < cc[i]; j++) str += (char)('a' + i);
	}
	return str;
}

int main() {
	cin >> D >> S;
	for (int i = 0; i < S.size(); i++) V[S[i] - 'a'].push_back(i);

	for (int i = 0; i < 26; i++) {
		vector<int>vec; vec.push_back(-1);
		for (int j = 0; j < S.size(); j++) {
			if (S[j] <= ('a' + i)) vec.push_back(j);
		}
		vec.push_back(S.size());

		bool flag = false;
		for (int j = 0; j < (int)vec.size() - 1; j++) {
			if (vec[j + 1] - vec[j] > D) flag = true;
		}
		
		if (flag == false) {
			cout << solve(i) << endl;
			break;
		}
	}
	return 0;
}