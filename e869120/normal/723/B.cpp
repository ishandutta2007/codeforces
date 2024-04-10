#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n; string S;
vector<string>V1, V2; int cnt = 0, maxn = 0;
int main() {
	cin >> n >> S; string T; S = '_' + S + '_';
	for (int i = 0; i < S.size(); i++) {
		if (S[i] >= 'A' && S[i] <= 'Z')S[i] += 32;
	}
	for (int i = 0; i < S.size(); i++) {
		if ((S[i] < 'a' || S[i] > 'z') && T.size() >= 1) {
			if (cnt >= 1)V1.push_back(T); if (cnt == 0)V2.push_back(T); T = "";
		}
		if (S[i] >= 'a' && S[i] <= 'z') { T += S[i]; }
		if (S[i] == '(')cnt++;
		if (S[i] == ')')cnt--;
	}
	for (int i = 0; i < V2.size(); i++) {
		maxn = max(maxn, (int)V2[i].size());
	}
	cout << maxn << ' ' << V1.size() << endl;
	return 0;
}