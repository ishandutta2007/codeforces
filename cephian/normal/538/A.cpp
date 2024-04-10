#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); ++i) {
		for (int j = i; j <= str.length(); ++j) {
			string news = str.substr(0, i) + str.substr(j);
			if (news == "CODEFORCES") {
				cout << "YES\n";
				return 0;
			}
		}
	}

	cout << "NO\n";

	return 0;
}