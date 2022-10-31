#include <bits/stdc++.h>
using namespace std;

deque<int> vec[3];
vector<int> v1, v2;
string s;
int r[3], cn[3][3];
int main() {	
	int n; cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) vec[s[i] - '0'].push_back(i);
	for (int i = 0; i < 3; i++) {
		r[i] = int(vec[i].size()) - n / 3;
		if (r[i] < 0) {
			for (int j = 0; j < -r[i]; j++) v2.push_back(i);
		} else {
			for (int j = 0; j < r[i]; j++) v1.push_back(i);
		}
	}
	for (int i = 0; i < v1.size(); i++) cn[v1[i]][v2[i]]++;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < cn[i][j]; k++) {
				int p = vec[i].front();
				vec[i].pop_front();
				s[p] = j + '0';
			}
		}
		for (int j = 2; j > i; j--) {
			for (int k = 0; k < cn[i][j]; k++) {
				int p = vec[i].back();
				vec[i].pop_back();
				s[p] = j + '0';
			}
		}
	}
	cout << s << endl;
	return 0;
}