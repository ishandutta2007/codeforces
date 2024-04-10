#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {	
	int n;
	string s;
	cin >> n >> s;
	for(int i = 1; i < size(s); ++i) {
		if(s[i] != s[i-1]) {
			cout << "YES\n" << s[i-1] << s[i] << "\n";
			return 0;
		}
	}
	cout << "NO\n";
}