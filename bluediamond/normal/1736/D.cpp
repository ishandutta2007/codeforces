#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif 

	int t;
	cin >> t;
	while (t--) {
		int n;
		string str;
		cin >> n >> str;
		vector<int> inds;
		for (int i = 0; i < 2 * n; i += 2) {
			if (str[i] != str[i + 1]) {
				int j = i;
				if (str[j] != '0' + (int) inds.size() % 2) {
					j++;
				}
				inds.push_back(j + 1);
			}
		}
		if ((int) inds.size() % 2 == 1) {
			cout << "-1\n";
			continue;
		}
		cout << (int) inds.size() << "\n";
		for (auto &i : inds) {
			cout << i << " ";
		}
		cout << "\n";
		for (int i = 1; i <= 2 * n; i += 2) {
			cout << i << " ";
		}
		cout << "\n";
	}

 	return 0;
}
/*
*/