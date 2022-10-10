#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	char ch;
	bool firstTime = true;
	while (cin >> ch) cout << (firstTime and ch == '9' ? '9' : min(ch, (char) (48 + '9' - ch))), firstTime = false;
	return 0;
}