#include <iostream>

using namespace std;

int n;
string s;

int main() {
	cin >> n >> s;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] != '<')
			break;
		++ans;
	}
	for(int i = 0; i < n; ++i) {
		if(s[n-1-i] != '>')
			break;
		++ans;
	}
	cout << ans << "\n";

	return 0;
}