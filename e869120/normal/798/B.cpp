#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n; string S[55];
int sets(string V) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string W = S[i];
		for (int j = 0; j < 300; j++) {
			if (j == 299)return 999999999;
			if (W == V)break; cnt++;
			W += W[0]; W = W.substr(1, W.size() - 1);
		}
	}
	return cnt;
}
int main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> S[i];
	vector<string>F; string T = S[0];
	for (int i = 0; i < S[0].size(); i++) {
		F.push_back(T);
		T += T[0]; T = T.substr(1, T.size() - 1);
	}
	int maxn = 999999999;
	for (int i = 0; i < F.size(); i++) {
		maxn = min(maxn, sets(F[i]));
	}
	if (maxn == 999999999)maxn = -1;
	cout << maxn << endl;
	return 0;
}