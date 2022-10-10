#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> t[3];
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a; cin >> a; --a;
		t[a].push_back(i);
	}
	int s =  min(min(t[0].size(), t[1].size()), t[2].size());
	cout << s << '\n';
	for (int i = 0; i < s; ++i) {
		cout << t[0][i] <<  ' ' << t[1][i] << ' ' << t[2][i] << '\n';
	}
	return 0;
}