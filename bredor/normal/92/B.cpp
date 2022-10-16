//  228

#include <iostream>

using namespace std;

int main() {
	cin.tie(0);cin.sync_with_stdio(0);cout.tie(0);
	
		int ans = 0,i;
		string s;
		
	cin  >> s;
	i = s.length()-1;
	while (s[i] == '0') {
		i--;
		ans++;
	}
	if (i == 0) {
		cout << ans;
		return 0;
	}
	ans += 2;
	s.erase(i,s.length()-i);
//	cout << s;
	for (int i=s.length()-1;i>=0;i--)
		if (s[i] == '1') ans++;
		else ans += 2;
	cout << ans;
	return 0;
}