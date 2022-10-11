#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
vector<pair<char, char>>x; string S1, S2; vector<char>D[256]; bool used[256];
int main() {
	cin >> S1 >> S2;
	for (int i = 0; i < S1.size(); i++) {
		D[S1[i]].push_back(S2[i]);
		D[S2[i]].push_back(S1[i]);
	}
	for (int i = 'a'; i <= 'z'; i++) {
		sort(D[i].begin(), D[i].end());
		if (D[i].size() >= 1) {
			vector<char>E; E.push_back(D[i][0]);
			for (int j = 1; j < D[i].size(); j++) {
				if (D[i][j] != D[i][j - 1])E.push_back(D[i][j]);
			}
			D[i] = E;
		}
	}
	bool flag = true;
	for (char i = 'a'; i <= 'z'; i++) {
		if (D[i].size() >= 2)flag = false;
		if (D[i].size() == 0 || used[i] == true)continue;
		char S = D[i][0];
		if (D[S].size() >= 1) {
			if (D[S].size() >= 2 || D[S][0] != i)flag = false;
		}
		if (flag == true && i != S) {
			used[i] = true; used[S] = true;
			x.push_back(make_pair(i, S));
		}
	}
	if (flag == false)cout << "-1" << endl;
	else {
		cout << x.size() << endl;
		for (int i = 0; i < x.size(); i++) {
			cout << x[i].first << ' ' << x[i].second << endl;
		}
	}
	return 0;
}