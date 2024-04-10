#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n; string S; vector<char>vec;
bool reset(char t) {
	if (vec.size() == 2) {
		if (vec[1] != t && vec[0] != t)return true;
		return false;
	}
	if (vec.size() == 1) {
		if (vec[0] == 'L' && t == 'R')return true;
		if (vec[0] == 'R' && t == 'L')return true;
		if (vec[0] == 'U' && t == 'D')return true;
		if (vec[0] == 'D' && t == 'U')return true;
		return false;
	}
	return false;
}
int main() {
	cin >> n >> S; int cnt = 0;
	for (int i = 0; i < S.size(); i++) {
		if (i == 0 || S[i - 1] != S[i]) {
			if (reset(S[i]) == true) {
				cnt++; vec.clear();
			}
			if (vec.size() == 0 || vec.size() == 1)vec.push_back(S[i]);
		}
	}
	cout << cnt + 1 << endl;
	return 0;
}