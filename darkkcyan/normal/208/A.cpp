#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<string> a(1, "");
	for (int i = 0; i < (int) s.size(); ++i) {
		if (string() + s[i] + s[i + 1] + s[i + 2] == "WUB") {
			i += 2;
			if (a.back() != "") a.push_back("");
		}
		else a.back() += s[i];
	}
	for (int i = 0; i < (int) a.size(); ++i) {
		cout << a[i] << ' ';
	}
	return 0;
}