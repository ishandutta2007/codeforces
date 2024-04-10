#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	string str; cin >> str;
	vector<int> depth(n, 0);
	int maxd = 0, dep = 0;
		
	for (int i = 0; i < n; ++i) {
		if (str[i] == ']') dep -= 1;
		depth[i] = dep;
		if (str[i] == '[') dep += 1;
		maxd = max(maxd, dep - 1);
	}

	vector<string> ret(3 + 2 * maxd);
	for (int i = 0; i < n; ++i) {
		int dep = depth[i];
		int it = 1;
		if (i == 0 || str[i] != str[i - 1]) 
			it += 1;
		if (i > 0 && str[i] == ']' && str[i - 1] == '[')
			it += 1;

		while (it--)
			for (int i = 0; i < (int)ret.size(); ++i)
				ret[i] += " ";
		
		int col1 = ret[0].size() - 1;
		int col2 = col1 - 1;
		if (str[i] == '[') 
			swap(col1, col2);
		int a = dep, b = ret.size() - 1 - dep;
		for (int i = a; i <= b; ++i)
			ret[i][col1] = '|';
		ret[a][col1] = ret[b][col1] = '+';
		ret[a][col2] = ret[b][col2] = '-';
	}

	for (int i = 0; i < (int)ret.size(); ++i)
		cout << ret[i] << '\n';

	return 0;
}