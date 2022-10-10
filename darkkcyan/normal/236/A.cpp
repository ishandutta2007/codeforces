#include <iostream>
#include <bitset>
using namespace std;

bitset<27> bs;

int main() {
	char ch;
	while (cin >> ch) bs[ch - 'a'] = true;
	cout << (bs.count() % 2 ?  "IGNORE HIM!" : "CHAT WITH HER!");
	return 0;
}