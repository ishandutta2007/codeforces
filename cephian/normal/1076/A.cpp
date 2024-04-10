#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string s;
	cin >> n >>s;
	for(int i = 0; i < (int)s.size()-1; ++i) {
		if(s[i] > s[i+1]) {
			cout << s.substr(0, i) << s.substr(i+1) << "\n";
			return 0;
		}
	}
	cout << s.substr(0, (int)s.size()-1) << "\n";
}