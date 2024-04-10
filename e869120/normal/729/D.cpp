#include <bits/stdc++.h>
using namespace std;
int n, a, b, m; string s;
int main() {
	cin >> n >> a >> b >> m >> s;
	vector<int> v = { -1 };
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '1') v.push_back(i);
	}
	v.push_back(n);
	vector<int> ret;
	for(int i = 0; i <= m; i++) {
		for(int j = v[i] + b; j < v[i + 1]; j += b) ret.push_back(j);
	}
	cout << max((int)ret.size() - a + 1, 0) << endl;
	for(int i = a - 1; i < ret.size(); i++) printf("%d ", ret[i] + 1);
	return 0;
}