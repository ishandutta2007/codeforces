#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
typedef complex<ld> pt;


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	string s;
	cin >> s;
	int ct = 0;
	for(int i=0;i<s.length()/2;++i) {
		if(s.at(i) != s.at(s.length()-1-i))
			++ct;
	}
	if(ct == 1 || (ct == 0 && s.length()%2 == 1))
		cout << "YES" << endl;
	else cout << "NO" << endl;
	
	
	
	return 0;
}