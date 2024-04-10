#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string S[70000]; int n; vector<int>V[10]; bool used[100000000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 9; k++) {
				if (k + j + 1 > 9)continue;
				int G = stoi(S[i].substr(k, j + 1));
				if (used[G] == true)continue;
				V[j].push_back(G); used[G] = true;
			}
			for (int k = 0; k < 9; k++) {
				if (k + j + 1 > 9)continue;
				int G = stoi(S[i].substr(k, j + 1));
				used[G] = false;
			}
		}
		V[8].push_back(stoi(S[i]));
	}
	for (int i = 0; i <= 8; i++)sort(V[i].begin(), V[i].end());
	for (int i = 0; i < n; i++) {
		int minx = 1e9, minid = 10;
		for (int j = 0; j < 9; j++) {
			for (int k = j; k < 9; k++) {
				int H = stoi(S[i].substr(j, k - j + 1));
				int pos1 = lower_bound(V[k - j].begin(), V[k - j].end(), H) - V[k - j].begin();
				int pos2 = lower_bound(V[k - j].begin(), V[k - j].end(), H + 1) - V[k - j].begin();
				if (pos2 - pos1 == 1 && (k - j) < minid) { minid = (k - j); minx = H; }
			}
		}
		string I = to_string(minx); while (I.size() <= minid)I = "0" + I;
		cout << I << endl;
	}
	return 0;
}