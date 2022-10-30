#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	string abc = "abc";
	vector<string> res;
	do {
		string cur;
		for (int i = 0; i < n; ++i) cur += abc;
		res.push_back(cur);
		res.push_back(string(n, abc[0]) + string(n, abc[1]) + string(n, abc[2]));
	} while (next_permutation(abc.begin(), abc.end()));
	
	for (auto str : res) {
		if (str.find(s) == string::npos && str.find(t) == string::npos) {
			cout << "YES" << endl << str << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
	return 0;
}