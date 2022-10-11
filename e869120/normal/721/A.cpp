#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string S, T; vector<int>vec;
int main() {
	int n; cin >> n >> S; S = "W" + S + "W";
	for (int i = 1; i < S.size(); i++) {
		if (S[i - 1] == 'B' && S[i] == 'W') { vec.push_back(T.size()); T = ""; }
		if (S[i] == 'B') { T += "B"; }
	}
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) { if (i)cout << ' '; cout << vec[i]; }
	if (vec.size() >= 1)cout << endl;
	return 0;
}