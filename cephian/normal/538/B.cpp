#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	string num;
	cin >> num;
	string target = num;
	for (int i = 0; i < target.size(); ++i)
		target[i] = '0';

	vector<int> all;
	while (num != target) {
		int next = 0;
		for (int i = 0; i < num.size(); ++i) {
			next *= 10;
			if (num[i] != '0') {
				--num[i];
				next += 1;
			}
		}
		all.push_back(next);
	}

	cout << all.size() << "\n";
	for (int i = 0; i < all.size(); ++i) {
		cout << all[i];
		if (i != all.size() - 1)
			cout << " ";
		else
			cout << '\n';
	}

	return 0;
}