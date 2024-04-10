#include <iostream>
using namespace std;
#define F0R(i,a) for (int i = 0; i < a; ++i)
int k[26], ans;
string s;

int main() {
	cin >> s;
	F0R(i,s.length()) k[int(s[i]-'a')] ++;
	F0R(i,26) if (k[i]) ans ++;
	if (ans % 2 == 1) cout << "IGNORE HIM!";
	else cout << "CHAT WITH HER!";
	return 0;
}