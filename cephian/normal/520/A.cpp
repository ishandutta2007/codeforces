#include <iostream>
#include <set>
#include <cctype>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int n;
	string str;
	cin >> n >> str;
	set<char> s;
	for (int i = 0; i < str.size(); ++i)
		s.insert(tolower(str[i]));
	if (s.size() == 26)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}