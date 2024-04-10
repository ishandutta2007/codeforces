#include <iostream>

using namespace std;

int main()
{
	string s, ans = "";
	cin >> s;
	char cur = 'a';
	for(char c:s) {
		if(c <= cur && cur <= 'z') ans += cur++;
		else ans += c;
	}
	if(cur > 'z') cout << ans << endl;
	else cout << -1 << endl;
}