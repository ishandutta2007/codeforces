#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			if (ch == '#') a[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (auto elem : a) {
			if (elem == a[i]) continue;
			bool ok = 1;
			for (int j = 0; j < m; j++) {
				if (elem[j] & a[i][j]) ok = 0;
			}
			if (!ok) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}