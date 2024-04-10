#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;

vector<string> query(int l, int r) {
	cout << "? " << l << " " << r << endl;

	vector<string> vec;
	for (int i = l; i <= r; i++) {
		for (int j = i; j <= r; j++) {
			string c; cin >> c;
			sort(c.begin(), c.end());
			vec.push_back(c);
		}
	}
	sort(vec.begin(), vec.end());
	return vec;
}

vector<string> Minus(vector<string> B1, vector<string> B2) {
	vector<pair<int, string>> vec; int cx = -1;
	for (int i = 0; i < B1.size(); i++) {
		int pos1 = max(cx + 1, lower_bound(B2.begin(), B2.end(), B1[i]) - B2.begin());
		if (pos1 == B2.size() || B2[pos1] != B1[i]) vec.push_back(make_pair(B1[i].size(), B1[i]));
		else cx = pos1;
	}
	sort(vec.begin(), vec.end());

	vector<string> vec2;
	for (int i = 0; i < vec.size(); i++) vec2.push_back(vec[i].second);
	return vec2;
}

char Minus(string V1, string V2) {
	int c1[26], c2[26];
	for (int i = 0; i < 26; i++) { c1[i] = 0; c2[i] = 0; }
	for (int i = 0; i < V1.size(); i++) c1[V1[i] - 'a']++;
	for (int i = 0; i < V2.size(); i++) c2[V2[i] - 'a']++;
	for (int i = 0; i < 26; i++) {
		if (c1[i] != c2[i]) return ('a' + i);
	}
	return '-';
}

int main() {
	cin >> N;
	if (N == 1) {
		cout << "? 1 1" << endl;
		string U; cin >> U;
		cout << "! " << U << endl;
		return 0;
	}

	vector<string> V1 = query(1, N);
	vector<string> V2 = query(2, N);
	vector<string> D = Minus(V1, V2);
	string E = D[0];
	for (int i = 0; i < N - 1; i++) E += Minus(D[i], D[i + 1]);

	cout << "! " << E << endl;
	return 0;
}