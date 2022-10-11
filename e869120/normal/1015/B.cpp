#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string S, T, ZS, ZT; int n, cnt[26], R[55]; vector<int>vec[26], G;

int main() {
	cin >> n >> S >> T; ZS = S; ZT = T;
	sort(ZS.begin(), ZS.end());
	sort(ZT.begin(), ZT.end());
	if (ZS != ZT) {
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 0; i < S.size(); i++) vec[S[i] - 'a'].push_back(i);
	for (int i = 0; i < T.size(); i++) {
		R[i] = vec[T[i] - 'a'][cnt[T[i] - 'a']];
		cnt[T[i] - 'a']++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (R[j] > R[j + 1]) { G.push_back(j + 1); swap(R[j], R[j + 1]); }
		}
	}
	reverse(G.begin(), G.end());
	cout << G.size() << endl;
	for (int i = 0; i < G.size(); i++) {
		if (i) cout << " ";
		cout << G[i];
	}
	cout << endl;
	return 0;
}